CC=gcc
WWW=-Wall -Werror -Wextra

all: cipher

cipher: cipher.o
	$(CC) $(WWW) cipher.o -o ../build/cipher

cipher.o: cipher.c
	$(CC) $(WWW) cipher.c -c

clean: 
	rm -rf *.o ../build/cipher