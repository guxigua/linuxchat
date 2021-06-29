
target: client.o login.o
	gcc -g -o bin/main lib/client.o lib/login.o
client.o: src/client.c
	gcc -c -g -o lib/client.o src/client.c
login.o: src/login.c
	gcc -c -g -o lib/login.o src/login.c
clean: 
	rm -f lib/client.o lib/login.o
