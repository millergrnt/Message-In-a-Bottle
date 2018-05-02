miab_server: server.o miab_client
	gcc -o miab_server -ggdb `pkg-config --cflags ncurses` server.o `pkg-config --libs ncurses` -lssl -lcrypto init_screen.o wrap_socket.o
	openssl req -newkey rsa:2048 -nodes -keyout key.pem -out cert.csr -subj "/C=US/ST=New York/L=Rochester";
	openssl x509 -in cert.csr -out cert.pem -req -signkey key.pem -days 1001;
	rm -f cert.csr

miab_client: client.o
	gcc -o miab_client -ggdb `pkg-config --cflags ncurses` client.o `pkg-config --libs ncurses` -lssl -lcrypto init_screen.o wrap_socket.o

server.o: messageInABottleServer/messageInABottleServer.c init_screen.o wrap_socket.o
	gcc -o server.o -Iinit_screen/ -Wall -Wextra -c messageInABottleServer/messageInABottleServer.c

client.o: messageInABottleClient/messageInABottleClient.c init_screen.o wrap_socket.o
	gcc -o client.o -Iinit_screen/ -Wall -Wextra -c messageInABottleClient/messageInABottleClient.c

init_screen.o: init_screen/init_screen.c init_screen/init_screen.h
	gcc -o init_screen.o -Wall -Wextra -c init_screen/init_screen.c

wrap_socket.o: wrap_socket/wrap_socket.c wrap_socket/wrap_socket.h
	gcc -o wrap_socket.o -Wall -Wextra -lssl -lcrypto -c wrap_socket/wrap_socket.c

clean:
	rm -f *.o miab_server miab_client

