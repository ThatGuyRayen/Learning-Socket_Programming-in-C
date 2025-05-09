#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int		main()
{
	int	socketFD = socket(AF_INET, SOCK_STREAM, 0);

	char	*ip = "234.3.42.1";
	if (socketFD < 0)
	{
		perror("Connection Failed");
		exit(1);
	}
	struct	sockaddr_in address;
	address.sin_port = htons(2000);
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

	int result = connect(socketFD,(struct sockaddr *)&address, sizeof address);

	if (result == 0)
		printf("Connection was successful\n");
	

	return (0);
}
