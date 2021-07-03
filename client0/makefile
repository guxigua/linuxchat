target: client.o project.o
	gcc -g -o main client.o project.o
client.o: client.c
	gcc -c -g -o client.o client.c
project.o: project.c
	gcc -c -g -o project.o project.c
clean: 
	rm -f client.o project.o
