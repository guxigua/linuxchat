clean: 
	rm -f lib/client.o lib/login.o

target: client.o login.o
	gcc -o bin/main lib/client.o lib/login.o
client.o: src/client.c
	gcc -c -o lib/client.o src/client.c
login.o: src/login.c
	gcc -c -o lib/login.o src/login.c
