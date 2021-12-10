CROSS = 
CC = $(CROSS)gcc
AS = $(CROSS)as
LD = $(CROSS)ld
NM = $(CROSS)nm
SIZE = $(CROSS)size
OBJDUMP = $(CROSS)objdump


all: helloC helloS test memory stack


helloC: helloC.o
	@echo "[BUILD] $@"
	$(CC) $< -m32 -o $@
	@echo "Generating helloC.sym and helloC.asm ..."
	$(OBJDUMP) -t $@ | grep "\.text" | sort > helloC.sym
	$(OBJDUMP) -S $@ > helloC.asm
	$(OBJDUMP) -f $@ > helloC.arch
	ldd $@
	@echo

helloC.o: hello.c
	$(CC) -Wall -m32 -g -c $< -o $@
	$(NM) $@


helloS: helloS.o
	$(LD) -s -o $@ $<

helloS.o: hello.S
	$(AS) -o $@ $<


test: test.c
	@echo "[BUILD] $@"
	$(CC) -Wall $< -o $@
	@echo
	@file $@
	@echo


memory: memory.c
	@echo "[BUILD] $@"
	$(CC) -Wall $< -o $@
	$(SIZE) $@
	@echo


stack: stack.c
	@echo "[BUILD] $@"
	$(CC) -Wall -m32 -g $< -o $@
	$(OBJDUMP) -S stack > stack.asm
	$(OBJDUMP) -s stack > stack.sec
	@echo


clean:
	rm -f helloC helloC.o helloC.sym helloC.asm helloC.arch
	rm -f helloS helloS.o
	rm -f test
	rm -f memory
	rm -f stack

.PHONY: helloC helloS test memory stack
