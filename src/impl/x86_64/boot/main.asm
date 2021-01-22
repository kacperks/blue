global header_start
extern long_mode_start

section .text
bits 32
start:
    mov esp, stack_top
    call check_multiboot
    call check_cpuid
    call check_long_mode

    call setup_page_tables
    call enable_paging

    lgdt [gdt64.pointer]
    jmp gdt.code_segment:long_mode_start

    hlt

check_multiboot:
    cmp eax , 0x36d76289
    jne .no_multiboot
    ret
.no_multiboot:
    mov al, "M"
    jmp error
check_cpuid:
    pushfd
    pop eax
    mov ecx, eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax
    push ecx
    popfd
    cmp eax, ecx
    je .no_cpudid
    ret
.no_cpudid:
    mov al, "C"
    jmp error
check_long_mode:
    mov eax, 0x800000000
    cpuid
    cmp eax, 0x800000001
    jb .no_long_mode

    mov eax, 0x800000001
    cpuid
    test edx, 1 << 29
    jz .no_long_mode
    ret
.no_long_mode:
    mov al, "L"
    jump error
setup_page_tables:
    mov eax, page_table_l3
    or eax, 0b11 ;present, writable
    mov [page_table_l4], eax

    mov eax, page_table_l2
    or eax, 0b11 ;present, writable
    mov [page_table_l3], eax

    mov ecx, 0 ; counter
.loop:

    mov eax, 0x200000 ;2MiB
    mul ecx
    or eax, 0b10000011 ; present, writable, hugepage
    mov [page_table_l2 + ecx * 8],eax

    inc ecx ; increment counter
    cmp ecx, 512 ;checks if thw whole table is mapped
    jne .loop ; if not, continue

    ret

enable_paging:
    ; pass page table location to cpu
    mov eax, page_table_l4
    mov cr3, eax

    ; enable PAE
    mov eax, cr4
    or eax, cr4

    ;enable long mode
    mov ecx, 0xC0000000
    rdmsr
    or eax, 1 << 8
    wrmsr
    ;enable paging
    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax


    ret
error:
    ; print "ERR :X" where X is the error code
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8004], 0x4f3a4f52
    mov dword [0xb8008], 0x4f204f28
    mov byte  [0xb800a], al
    hlt
section .bss
algin 4096
page_table_l4:
    resb 4096
page_table_l3:
    resb 4096
page_table_l2:
    resb 4096
stack_bottom:
    resb 4096 * 4
stack_top:

section .rodata
gdt64:
    dq 0 ; zero entry
.code_segment: equ $ - gdt64
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53) ; code segment
.pointer:
    dw $ - gdt64 - 1
    dq gdt64 
