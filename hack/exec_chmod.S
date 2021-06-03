.data

.text

.global _start

_start:

# argv[2]:
#   2e 2f 65 78  65 63 5f 63  68 6d 6f 64  00 00 00 00
#    .  /  e  x   e  c  _  c   h  m  o  d  \0 \0 \0 \0
    push    $0x00000000
    push    $0x646f6d68
    push    $0x635f6365
    push    $0x78652f2e
    movl    %esp, %edx
# argv[1]:
#   36 34 34 00
#    6  4  4 \0
    push    $0x00343436
    movl    %esp, %ecx
# argv[0]:
#   2f 62 69 6e  2f 63 68 6d  6f 64 00 00
#    /  b  i  n   /  c  h  m   o  d \0 \0
    push    $0x0000646f
    push    $0x6d68632f
    push    $0x6e69622f
    movl    %esp, %ebx
# sys_execve:
#   %eax  %ebx  %ecx  %edx
#    11    file  argv  envp
    push    $0x0  # argv[3] -> NULL
    push    %edx  # argv[2] -> "./exec_chmod"
    push    %ecx  # argv[1] -> "644"
    push    %ebx  # argv[0] -> "/bin/chmod"
    movl    %esp, %ecx
    movl    $0, %edx
    movl    $11, %eax
    int     $0x80

# sys_exit:
#   %eax  %ebx
#    1     code
    movl    $0, %ebx
    movl    $1, %eax
    int     $0x80
