CROSS = 
CC = $(CROSS)gcc
OBJDUMP = $(CROSS)objdump
STRIP = $(CROSS)strip
SIZE = $(CROSS)size


all: main.normal main.normal.S \
     main.inline main.inline.S
	$(STRIP) main.normal main.inline
	$(SIZE) main.normal main.inline


main.normal: main.normal.o
	$(CC) $< -o $@
	$(OBJDUMP) -S $@ > $@.asm

main.normal.o: main.c
	$(CC) -g -c $< -o $@

main.normal.S: main.c
	$(CC) -S $< -o $@


main.inline: main.inline.o
	$(CC) $< -o $@
	$(OBJDUMP) -S $@ > $@.asm

main.inline.o: main.c
	$(CC) -O -g -c $< -o $@

main.inline.S: main.c
	$(CC) -O -S $< -o $@


clean:
	rm -f main.normal main.normal.S main.normal.o main.normal.asm
	rm -f main.inline main.inline.S main.inline.o main.inline.asm

.PHONY: all clean
