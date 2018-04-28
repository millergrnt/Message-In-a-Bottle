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


/**
	Takes in the error message, prints it to stderr
	and then exits the program.
*/
void report_error_and_die(char *error_message){
	fprintf(stderr, error_message);
	exit(EXIT_FAILURE);
}


/**
	Creates the socket to be used in chat by the server
*/
int make_server_socket(){
	//fd = File Descriptor
	int sock_fd, connected_socket_fd, client_length;
	int unsigned port = 31337;
	struct sockaddr_in server_address, client_address;

	//Create socket and then check if it was successful
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_error_check < 0)
		report_error_and_die("Error creating socket\n");

	//Zero out the server_address array, this will prevent 
	//errors based around us not knowing if the memory is 0
	bzero((char *) &server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);

	//Bind the socket to the server
	if(bind(sock_fd, 
		(struct sockaddr *) &server_address, 
		sizeof(server_address) < 0)
		report_error_and_die("Error binding server socket");

	return sock_fd;

}


/**
	Sends a mesage across the wire
	Params:
		Socket to send over

*/
int send_message(){
	return EXIT_SUCCESS;
}


/**
	Main function, handles input and calls the send message functions
	Params:
		argc - Count of arguments
		argv - Argument Array
	Returns:
		EXIT_SUCCESS if okay
		EXIT_FAILURE otherwise

	//Server waits for a connection and then accepts it.
	listen(sock_fd, 1);
	client_length = sizeof(client_address);
	connected_socket_fd = accept(sock_fd, (struct sockaddr*) &client_address, &client_length);

	if(connected_socket_fd < 0)
		report_error_and_die("Error with client connection");
*/
int main(int argc, char ** argv){
	if(argc > 1){
		printf("**************Welcome to Messaging in a Bottle**************\n");
		printf("You are currently connecting to: %s\n", argv[1]);
		printf("Be Nice and have a good time!!\n");
		int socket = make_server_socket();
	} else {
		printf("**************Welcome to Message in a Bottle**************\n");
		printf("You never supplied someone to talk to :( exiting\n");
	}
	return EXIT_SUCCESS;
}