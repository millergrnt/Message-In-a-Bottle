/**
	Author: Grant Miller
	Description:
		Utilitzes the Openssl library to wrap the sockets in TLS.
		This will keep the messages encrypted over the network
		and protect the data being transmitted over the wire
*/

/**
	initiates the ssl session and returns the object
	Return:
		Returns the initiated SSL struct
*/
struct SSL * init_ssl();

/**
	Wraps the socket after connection has been made and before
	converstation thread begins
	Parms:
		int *socket_fd: Socket used for this connection
		struct SSL *ssl:
	Return:
		Returns the wrapped socket
*/
int *wrap_socket(int *socket_fd, struct SSL *ssl));