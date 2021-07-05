target: client.o project.o
	gcc -g -o main client.o project.o -pthread
client.o: client.c
	gcc -c -g -o client.o client.c -pthread
project.o: project.c
	gcc -c -g -o project.o project.c
clean: 
	rm -f client.o project.o
