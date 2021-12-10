CC = gcc
CFLAGS = -Wall

APPS  = 8bits 64bits cast
APPS += divide double.equal double.notequal
APPS += pointer range shift
APPS += wchar

all: $(APPS)

8bits: 8bits.c
	$(CC) $(CFLAGS) -o $@ $<

64bits: 64bits.c
	$(CC) $(CFLAGS) -o $@ $<

cast: cast.c
	$(CC) $(CFLAGS) -o $@ $<

divide: divide.c
	$(CC) $(CFLAGS) -o $@ $<

double.equal: double.c
	$(CC) $(CFLAGS) -D__TOLERANCE__ -lm -o $@ $<

double.notequal: double.c
	$(CC) $(CFLAGS) -o $@ $<

pointer: pointer.c
	$(CC) $(CFLAGS) -o $@ $<

range: range.c
	$(CC) $(CFLAGS) -o $@ $<

shift: shift.c
	$(CC) $(CFLAGS) -o $@ $<

wchar: wchar.c
	$(CC) $(CFLAGS) -std=c99 -o $@ $<

clean:
	rm -f $(APPS)
