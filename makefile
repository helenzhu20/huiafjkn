
all: server client clean

server: server.o networking.o
	gcc -o server forking_server.o networking.o

client: client.o networking.o
	gcc -o client client.o networking.o

server.o: forking_server.c networking.h
	gcc -c forking_server.c

client.o: client.c networking.h
	gcc -c client.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
