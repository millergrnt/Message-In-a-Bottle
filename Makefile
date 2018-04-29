miab_server: server.o miab_client
	gcc -o miab_server `pkg-config --cflags ncurses` server.o `pkg-config --libs ncurses`

miab_client: client.o
	gcc -o miab_client `pkg-config --cflags ncurses` client.o `pkg-config --libs ncurses`

server.o: messageInABottleServer/messageInABottleServer.c
	gcc -o server.o -Wall -Wextra -c messageInABottleServer/messageInABottleServer.c

client.o: messageInABottleClient/messageInABottleClient.c
	gcc -o client.o -Wall -Wextra -c messageInABottleClient/messageInABottleClient.c

clean:
	rm -f *.o miab_server miab_client

