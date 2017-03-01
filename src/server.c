/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:47:46 by sdelardi          #+#    #+#             */
/*   Updated: 2017/03/01 21:47:50 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if((bind(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		printf("Bind error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int argc, char **argv)
{
	int 				port;
	int 				sock;
	int 				cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	int					r;
	char				buf[1024];
	

	if (argc != 2)
		return (0);
	port = atoi(argv[1]);
	sock = create_server(port);
	printf("Waiting for connexion\n");
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	printf("Accepted\n");
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		printf("received %d bytes: [%s]\n", r, buf);
	}
	close(cs);
	close(sock);
	return (0);
}
