/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/13 18:25:13 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	throw_err(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	init_envv(char **envv)
{
	VAR(int, i, STD_ENV - 1);
	if(!(g_envv = (char **)malloc(sizeof(char *) * (STD_ENV + 1))))
		throw_err("ENV MALL_ERR");
	g_envv[0] = "PATH=/usr/bin";
	g_envv[1] = "HOME=/nfs/2018/e/egoodale/";
	
}

void dad_loop(int ttyfd)
{
	char *line;
	char **args;
	int status;

	status = 1;
	while (status)
	{
		ft_printf("\n> ");
		signal(SIGINT, dad_signal);
		get_next_line(ttyfd, &line);
		args = ft_strsplit(line, ' ');
		status = dadsh_exec(args);
		free(line);
		ft_freestrarr(args);
	}
	ft_freestrarr(g_envv);
}

int main(int ac, char **envv)
{
	char *ttyfile = "/dev/ttys001";
	int fd = open(ttyfile, O_RDWR);
	init_envv(envv);
	dad_loop(fd);
	return (EXIT_SUCCESS);
}
