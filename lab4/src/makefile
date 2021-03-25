CC=gcc
CFLAGS=-I.

all : parallel_min_max process_memory zombie_proc parallel_sum

parallel_sum : parallel_sum.c
	$(CC) -pthread -o parallel_sum parallel_sum.c $(CFLAGS)

parallel_min_max : parallel_min_max.c utils.c find_min_max.c
	$(CC) -o parallel_min_max parallel_min_max.c utils.c find_min_max.c $(CFLAGS)

zombie_proc : zombie_proc.c
	$(CC) -o zombie_proc zombie_proc.c $(CFLAGS)

process_memory : process_memory.c
	$(CC) -o process_memory process_memory.c $(CFLAGS)

clean:
	rm zombie_proc process_memory parallel_min_max parallel_sum