/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:32:48 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/09 12:55:21 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "ft_printf.h"

t_sock	create_server_ipv6(int port, char *proto_name)
{
	t_sock			server;
	t_protoent		*proto;
	t_sockaddr_in6	sin;
	int				yes;

	server = 0;
	proto = getprotobyname(proto_name);
	if (proto && (server = socket(PF_INET6, SOCK_STREAM, proto->p_proto)) < 0)
		return (create_server_ipv4(port, proto_name));
	sin.sin6_family = AF_INET6;
	sin.sin6_addr = in6addr_any;
	sin.sin6_port = htons(port);
	yes = 1;
	setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	if ((bind(server, (const t_sockaddr*)&sin, sizeof(sin))) < 0)
		return (create_server_ipv4(port, proto_name));
	listen(server, MAX_CLIENT_NBR);
	return (server);
}

t_sock	create_server_ipv4(int port, char *proto_name)
{
	t_sock			server;
	t_protoent		*proto;
	t_sockaddr_in	sin;
	int				yes;

	server = 0;
	proto = getprotobyname(proto_name);
	if (proto && (server = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
	{
		perror("create_server :");
		return (-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	yes = 1;
	setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	if ((bind(server, (const t_sockaddr*)&sin, sizeof(sin))) < 0)
		return (-1);
	listen(server, MAX_CLIENT_NBR);
	return (server);
}
