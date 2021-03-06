CC = gcc -m32
AS = as
LD = ld
OBJDUMP = objdump
CHMOD = chmod
RM = rm -f

CFLAGS = -Wall -g
LDFLAGS = -z execstack


all: buffer_overflow_1 buffer_overflow_2 buffer_overflow_3 \
     shell_code udp_send \
     goodbye exec_sh exec_chmod setuid rootshell

buffer_overflow_1: buffer_overflow_1.o
	@echo "build ... $@"
	@$(CC) $(LDFLAGS) $< -o $@
	@$(OBJDUMP) -S $@ > $@.asm

buffer_overflow_2: buffer_overflow_2.o
	@echo "build ... $@"
	@$(CC) $(LDFLAGS) $< -o $@
	@$(OBJDUMP) -S $@ > $@.asm

buffer_overflow_3: buffer_overflow_3.o
	@echo "build ... $@"
	@sudo $(CC) $(LDFLAGS) $< -o $@
	@sudo $(CHMOD) u+s $@
	@$(OBJDUMP) -S $@ > $@.asm

shell_code: shell_code.o
	@echo "build ... $@"
	@$(CC) $(LDFLAGS) $< -o $@

udp_send: udp_send.o
	@echo "build ... $@"
	@$(CC) $(LDFLAGS) $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


goodbye: goodbye.o
	@echo "build ... $@"
	@$(LD) -s -o $@ $<
	@$(OBJDUMP) -S $@ > $@.asm
	@./gen_shellcode_1.sh $@ > $@.code

exec_sh: exec_sh.o
	@echo "build ... $@"
	@$(LD) -s -o $@ $<
	@$(OBJDUMP) -S $@ > $@.asm
	@./gen_shellcode_2.sh $@ > $@.code

exec_chmod: exec_chmod.o
	@echo "build ... $@"
	@$(LD) -s -o $@ $<
	@$(OBJDUMP) -S $@ > $@.asm
	@./gen_shellcode_2.sh $@ > $@.code

setuid: setuid.o
	@echo "build ... $@"
	@$(LD) -s -o $@ $<
	@$(OBJDUMP) -S $@ > $@.asm
	@./gen_shellcode_3.sh $@ > $@.code

rootshell: rootshell.o
	@echo "build ... $@"
	@$(LD) -s -o $@ $<
	@$(OBJDUMP) -S $@ > $@.asm
	@./gen_shellcode_3.sh $@ > $@.code

%.o: %.S
	@$(AS) -o $@ $<


clean:
	@echo "clean ..."
	@$(RM) buffer_overflow_1 buffer_overflow_2
	@sudo $(RM) buffer_overflow_3
	@$(RM) shell_code udp_send
	@$(RM) goodbye exec_sh exec_chmod setuid rootshell
	@$(RM) *.o

distclean: clean
	@$(RM) *.asm *.sec *.code

.PHONY: all clean distclean
