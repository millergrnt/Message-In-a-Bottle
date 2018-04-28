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
#include <socket.h>


int 


/**

*/
int main(int argc, char ** argv){
	if(argc > 1){
		printf("**************Welcome to Messaging in a Bottle**************\n
				You are currently connecting to: %s\n
				Be Nice and have a good time!!\n");

		int sockCheck = socket();
	}
	return EXIT_SUCCESS;
}