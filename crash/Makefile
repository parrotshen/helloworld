CC = gcc

APPS  = segment_fault
APPS += stack_overflow
APPS += buffer_overflow
APPS += array_index_exceed
APPS += malloc_illegal_access
APPS += bus_error
APPS += free_invalid_pointer
APPS += double_free
APPS += free_invalid_next_size
APPS += out_of_memory
APPS += divide_by_zero
APPS += variable_lifetime
APPS += assert_causes_abort
APPS += broken_pipe


all: $(APPS)

segment_fault: segment_fault.c
	$(CC) -Wall -rdynamic $< -o $@

stack_overflow: stack_overflow.c
	$(CC) -Wall $< -o $@

buffer_overflow: buffer_overflow.c
	$(CC) -Wall $< -o $@

array_index_exceed: array_index_exceed.c
	$(CC) -Wall $< -o $@

malloc_illegal_access: malloc_illegal_access.c
	$(CC) -Wall $< -o $@

bus_error: bus_error.c
	$(CC) -Wall $< -o $@

free_invalid_pointer: free_invalid_pointer.c
	$(CC) -Wall $< -o $@

double_free: double_free.c
	$(CC) -Wall $< -o $@

free_invalid_next_size: free_invalid_next_size.c
	$(CC) -Wall $< -o $@

out_of_memory: out_of_memory.c
	$(CC) -Wall $< -o $@

divide_by_zero: divide_by_zero.c
	$(CC) -Wall -g $< -o $@

variable_lifetime: variable_lifetime.c
	$(CC) -Wall -g $< -o $@

assert_causes_abort: assert_causes_abort.c
	$(CC) -Wall -g $< -o $@

broken_pipe: broken_pipe.c
	$(CC) -Wall -lpthread $< -o $@

clean:
	rm -f $(APPS)
