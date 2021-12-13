CC = gcc


all: main.normal main.normal.S \
     main.inline main.inline.S


main.normal: main.normal.o
	$(CC) $< -o $@

main.normal.o: main.c
	$(CC) -c $< -o $@

main.normal.S: main.c
	$(CC) -S $< -o $@


main.inline: main.inline.o
	$(CC) $< -o $@

main.inline.o: main.c
	$(CC) -O -c $< -o $@

main.inline.S: main.c
	$(CC) -O -S $< -o $@


clean:
	rm -f main.normal main.normal.S main.normal.o
	rm -f main.inline main.inline.S main.inline.o

.PHONY: all clean
