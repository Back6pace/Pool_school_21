CC=gcc
WWW=-Wall -Werror -Wextra

all: state_sort state_search

state_sort: state_sort.o
	$(CC) $(WWW) state_sort.o -o ../build/Quest_1

state_sort.o: state_sort.c
	$(CC) $(WWW) state_sort.c -c

state_search: state_search.o
	$(CC) $(WWW) state_search.o -o ../build/Quest_2

state_search.o: state_search.c
	$(CC) $(WWW) state_search.c -c


clean: 
	rm -rf *.o ../build/Quest_1 ../build/Quest_2
