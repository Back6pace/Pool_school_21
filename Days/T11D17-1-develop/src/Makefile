CC=gcc
WWW=-Wall -Werror -Wextra

all: door_struct list_test clean

door_struct: dmanager_module
	$(CC) $(WWW) dmanager_module.o -o ../build/Quest_1

dmanager_module: dmanager_module.c
	$(CC) $(WWW) -c dmanager_module.c

list_test: 
	$(CC) $(WWW) list.c list_test.c -o ../build/Quest_2

clean: 
	rm -rf *.o 
