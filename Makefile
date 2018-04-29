miab_server: server.o miab_client
	gcc -o miab_server `pkg-config --cflags ncurses` server.o `pkg-config --libs ncurses` init_screen.o

miab_client: client.o
	gcc -o miab_client `pkg-config --cflags ncurses` client.o `pkg-config --libs ncurses` init_screen.o

server.o: messageInABottleServer/messageInABottleServer.c init_screen.o
	gcc -o server.o -Iinit_screen/ -Wall -Wextra -c messageInABottleServer/messageInABottleServer.c

client.o: messageInABottleClient/messageInABottleClient.c init_screen.o
	gcc -o client.o -Iinit_screen/ -Wall -Wextra -c messageInABottleClient/messageInABottleClient.c

init_screen.o: init_screen/init_screen.c init_screen/init_screen.h
	gcc -o init_screen.o -Wall -Wextra -c init_screen/init_screen.c

clean:
	rm -f *.o miab_server miab_client

