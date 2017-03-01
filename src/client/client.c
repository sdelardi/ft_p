/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:49:02 by sdelardi          #+#    #+#             */
/*   Updated: 2017/03/01 22:44:37 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "../../libft/libft.h"

int		create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if(connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(2);
	}
	return (sock);
}

int		main(int argc, char **argv)
{
	int 				port;
	int 				sock;
	int					res;
	char				*buf;
	
	if (argc != 3)
		return (0);
	port = atoi(argv[2]);
	sock = create_client(argv[1], port);
	while (((res = get_next_line(0, &buf)) >= 0))
	{
		write(sock, buf, ft_strlen(buf));
	}
	close(sock);
	return (0);
}
