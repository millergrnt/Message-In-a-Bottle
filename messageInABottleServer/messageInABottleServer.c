/*
	Author: Grant Miller <gem1086@rit.edu>
	Description:
		This is a simple command line to command line messaging tool.
		Whereby two different people can connect to each other and
		talk through the command line.
		It uses openssl to encrypt the messages over the network

		Future Objectives:
			On Start up type a person's name and automatically connect to their computer by DNS and MySQL

			Make it a simple Desktop app
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LENGTH 141
#define KILL_WHOLE_SOCKET 2


/**
	Takes in the error message, prints it to stderr
	and then exits the program.
*/
void report_error_and_die(char *error_message){
	fprintf(stderr, "%s\n", error_message);
	exit(EXIT_FAILURE);
}


/**
	Controls the actual message sending and receiving.
	For now is a one to one ratio, next thing to do is 
	make two threads. One for sending messages, the other
	for receiving messages.
*/
void run_message_thread(int connected_socket_fd){
	//Maximum message size is 141 characters
	char message[MAX_MESSAGE_LENGTH];
	int n;

	strcpy(message, " ");
	//Until the user enters QUIT keep going
	while(strcmp(message, "QUIT") != 0){

		printf("\nThem: ");
		//Receive response and check for errors
		n = recv(connected_socket_fd, message, MAX_MESSAGE_LENGTH, 0);
		if(n < 0)
			report_error_and_die("Error reading from socket");
		printf("%s\n", message);

		//Zero out the message buffer so there are no left over chars
		bzero(message, MAX_MESSAGE_LENGTH);

		//Prompt user
		printf("\nYou: ");
		fgets(message, MAX_MESSAGE_LENGTH, stdin);

		if(strcmp(message, "QUIT") != 0){
			//Send message and check for errors
			n = send(connected_socket_fd, message, strlen(message), 0);
			if(n < 0)
				report_error_and_die("Error writing to the socket");
		}
	}

	printf("Thanks for using Message in a Bottle!\nShutting down now...\n");
	shutdown(connected_socket_fd, KILL_WHOLE_SOCKET);
}


/**
	Creates the socket to be used in chat by the server
	Params:
		None
	Return:
		Returns a created socket file descriptor ready to being listening
*/
int make_server_socket(){
	//fd = File Descriptor
	int sock_fd;
	int unsigned port = 31337;
	struct sockaddr_in server_address;

	//Create socket and then check if it was successful
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0)
		report_error_and_die("Error creating socket");

	//Zero out the server_address array, this will prevent 
	//errors based around us not knowing if the memory is 0
	bzero((char *) &server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);

	//Bind the socket to the server
	if(bind(sock_fd, 
		(struct sockaddr *) &server_address, 
		sizeof(struct sockaddr_in)) < 0){
		perror("bind");
		report_error_and_die("Error binding server socket");
	}

	return sock_fd;

}


/**
	Waits for incoming connections and then responds
	------Update this with threading so that you can talk to
			up to 5 people at once
	Params:
		server_fd: Server socket who will begin listening and
					then do what it needs to
	Return:
		returns EXIT_SUCCESS once all all connections are done
*/
int wait_for_connections(int *server_fd){
	int connected_socket_fd;
	int unsigned client_length;
	struct sockaddr_in client_address;
	char address[INET_ADDRSTRLEN];

	//Server waits for a connection and then accepts it.
	listen(*server_fd, 1);
	client_length = sizeof(client_address);
	connected_socket_fd = accept(*server_fd, (struct sockaddr*) &client_address, &client_length);

	if(connected_socket_fd < 0)
		report_error_and_die("Error with client connection");

	inet_ntop(AF_INET, ((struct sockaddr*) &client_address)->sa_data, address, INET_ADDRSTRLEN);
	printf("Connected to %s\n", address);

	run_message_thread(connected_socket_fd);

	return EXIT_SUCCESS;
}


/**
	Main function, handles input and calls the send message functions
	Returns:
		EXIT_SUCCESS if okay
		EXIT_FAILURE otherwise
*/
int main(){
	printf("**************Welcome to Messaging in a Bottle**************\n");
	printf("Be Nice and have a good time!!\n");
	int socket_fd = make_server_socket();
	wait_for_connections(&socket_fd);

	return EXIT_SUCCESS;
}