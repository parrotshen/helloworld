CC = gcc
CFLAGS = -Wall -Iinc -g

SRC += src/main.c
SRC += src/morse.c

OBJ = $(SRC:.c=.o)


all: $(OBJ)
	$(CC) $(OBJ) -o test

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

gdb:
	@rm -f run_gdb.sh command.txt
	@echo "#!/bin/sh" > run_gdb.sh
	@echo "gdb --command=command.txt $$""1" >> run_gdb.sh
	@chmod +x run_gdb.sh
	@echo "#set solib-search-path /usr/lib" > command.txt
	@echo "dir inc" >> command.txt
	@echo "dir src" >> command.txt
	@echo "path src" >> command.txt
	@echo "list" >> command.txt

clean:
	rm -f test $(OBJ)

.PHONY: clean
