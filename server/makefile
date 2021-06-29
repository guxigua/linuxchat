clean: 
	rm -f lib/server.o lib/project.o

target: server.o project.o
	gcc -g -o bin/main lib/server.o lib/project.o -pthread -lmysqlclient
server.o: src/server.c
	gcc -g -c -o lib/server.o src/server.c
project.o: src/project.c
	gcc -g -c -o lib/project.o src/project.c
