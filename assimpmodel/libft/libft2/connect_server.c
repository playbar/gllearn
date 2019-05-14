/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:09:27 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/09 12:55:13 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "ft_printf.h"

in_addr_t	get_addr(char *ip)
{
	struct hostent *host;

	ft_dprintf(1, "Solve proxy\n");
	host = gethostbyname(ip);
	if (host)
		ip = inet_ntoa(*((struct in_addr *)host->h_addr));
	else
		return (-1);
	ft_dprintf(1, "%s\n", ip);
	return (inet_addr(ip));
}

t_sock		connect_server_ipv6(char *ip, int port, char *proto_name)
{
	t_sock			client;
	t_protoent		*proto;
	t_sockaddr_in6	sin;

	ft_dprintf(1, "{yellow}Try connecting to '%s:%d' on ipv6\n{eoc}", ip, port);
	client = 0;
	proto = getprotobyname(proto_name);
	if (proto)
		if ((client = socket(PF_INET6, SOCK_STREAM, proto->p_proto)) < 0)
			return (connect_server_ipv4(ip, port, proto_name));
	sin.sin6_family = AF_INET6;
	inet_pton(AF_INET6, ip, &sin.sin6_addr);
	sin.sin6_port = htons(port);
	if ((connect(client, (const t_sockaddr*)&sin, sizeof(sin))) < 0)
		return (connect_server_ipv4(ip, port, proto_name));
	ft_dprintf(1, "{yellow}Success\n{eoc}");
	return (client);
}

t_sock		connect_server_ipv4(char *ip, int port, char *proto_name)
{
	t_sock			client;
	t_protoent		*proto;
	t_sockaddr_in	sin;

	ft_dprintf(1, "{yellow}Try connecting to '%s:%d' on ipv4\n{eoc}", ip, port);
	client = 0;
	proto = getprotobyname(proto_name);
	if (proto)
		if ((client = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
			exit(ft_dprintf(2, "can't create socket\n"));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = get_addr(ip);
	if ((connect(client, (const t_sockaddr*)&sin, sizeof(sin))) == -1)
		exit(ft_dprintf(1, "\033[22;31mError : init client on %d\033[22;37m\n",
					port));
	ft_dprintf(1, "{yellow}Success\n{eoc}");
	return (client);
}
