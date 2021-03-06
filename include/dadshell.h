/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:06:13 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 18:28:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DADSHELL_H
#	define DADSHELL_H

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include "../libft/include/get_next_line.h"
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

#define SEPARATORS ":;!#%&()*+=`^,-./{|}~"
#define BUILTINS 7
#define STD_ENVV 0
#define VECTOR_CAP 50

extern char			**g_envv;
extern size_t		g_envv_len;
extern t_vector		g_linev;

/*
** Builtins
*/

int		cd(char **args);
int		print_env(char **args);
int		display_help(char **args);
int		exit_shell(char **args);
int		echo(char **args);
int		set_env(char **args);
int		unset_env(char **args);

/*
** Input Handler
*/

void	quote_message(char quote);
char	**normalize_input(char *input);
int		initialize_linefeed(int fd);
char	**parse_quotes(int fd);
char	**get_user_input(int fd);

/*
** Argument Parsing
*/

void	parse_arg(t_vector *t, char **envv_tok);
void	translate_envv_args(char **args);

/*
** General Helpers
*/

int		is_in(char *directory_name, char *executable);
void	handle_signal(int sig);
int     matches_path(char *path_to_match, char *path);

/*
** Environment Helpers
*/


char	*get_envv_key(char *envv_str);
char	**realloc_envv(int new_size);
char	*find_envv(const char *key, int val_only);
int		get_envv_index(const char *key);
void	translate_envv_args(char **args);

/*
** Process Execution
*/

int		run(char *path, char **args);
int		launch(char *path, char **args);
int		build_path(char **args);
int		execute(char **args);

typedef struct dirent	t_dirent;

#	endif
