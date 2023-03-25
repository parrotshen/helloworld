CC = gcc
CFLAGS = -Wall

APPS = 8bits atoi bitfield cast pointer range string wchar

all: $(APPS)

8bits: 8bits.c
	$(CC) $(CFLAGS) -o $@ $<

atoi: atoi.c
	$(CC) $(CFLAGS) -o $@ $<

bitfield: bitfield.c
	$(CC) $(CFLAGS) -o $@ $<

cast: cast.c
	$(CC) $(CFLAGS) -o $@ $<

pointer: pointer.c
	$(CC) $(CFLAGS) -o $@ $<

range: range.c
	$(CC) $(CFLAGS) -o $@ $<

string: string.c
	$(CC) $(CFLAGS) -o $@ $<

wchar: wchar.c
	$(CC) $(CFLAGS) -std=c99 -o $@ $<

clean:
	rm -f $(APPS)
