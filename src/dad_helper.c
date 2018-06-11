/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:42:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 20:29:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void			print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_printf("%s\n", g_envv[i]);
}

int				env_len(char **envv)
{
	VAR(int, i, -1);
	while(envv[i])
		i++;
	return (i + STD_ENV);
}

void	init_envv(char **env)
{
	VAR(int, i, -1);
	if(!(g_envv = (char **)malloc(sizeof(char *) * (env_len(env) + 1))))
		throw_err("ENV MALL_ERR");
	while (env[++i])
		if(!(g_envv[i] = ft_strdup(envv[i])))
			throw_err("ENV MALL_ERR");
}

char		*get_envv(char *var)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(var));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], var, var_len) == 0)
			return(ft_strchr(g_envv[i], '=') + 1);
	return (NULL);
}

int 	find_envv(char *var)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(var));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], var, var_len) == 0)
			return(i);
	return (NULL);
}