CC = gcc

all: stdout stdout_flush stderr syslog terminal format

stdout: stdout.c
	$(CC) -Wall -DPRINT_IMMEDIATELY=0 $< -o $@

stdout_flush: stdout.c
	$(CC) -Wall -DPRINT_IMMEDIATELY=1 $< -o $@

stderr: stderr.c
	$(CC) -Wall $< -o $@

syslog: syslog.c
	$(CC) -Wall $< -o $@

terminal: terminal.c
	$(CC) -Wall $< -o $@

format: format.c
	$(CC) -Wall $< -o $@

clean:
	rm -f stdout stdout_flush stderr syslog terminal format
