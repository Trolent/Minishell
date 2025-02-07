/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:41:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 09:55:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* printf, perror */
# include <stdio.h>
# include <errno.h>
/* malloc, free, exit, getenv */
# include <stdlib.h>
/* write, access, open, read, close, fork, getcwd, chdir, dup, dup2, pipe
execve, isatty, ttyname, ttyslot */
# include <unistd.h>
/* readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
add_history*/
# include <readline/readline.h>
# include <readline/history.h>
/* signal, sigaction, sigemptyset, sigaddset, kill */
# include <sys/wait.h>
/* stat, lstat, fstat */
# include <sys/stat.h>
/* open */
# include <fcntl.h>
/* opendir, readdir, closedir */
# include <dirent.h>
/* strerror */
# include <string.h>
/* ioctl */
# include <sys/ioctl.h>
/* tcsetattr, tcgetattr */
# include <termios.h>
/* tgetent, tgetflag, tgetnum, getstr, tgoto, tputs */
# include <curses.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include "libft.h"
// lib for signals
# include "type.h"
// lib fot structs

# define RED     "\001\x1b[31m\002"
# define GREEN   "\001\x1b[32m\002"
# define YELLOW  "\001\x1b[33m\002"
# define BLUE    "\001\x1b[34m\002"
# define MAGENTA "\001\x1b[35m\002"
# define CYAN    "\001\x1b[36;1m\002"
# define RESET   "\001\x1b[0m\002"

# define HARDPATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
# define SYNTAX_ERR "minishell: syntax error near \
unexpected token `%s'\n"
# define NEWLINE_ERR "minishell: unexpected newline \
while looking for matching `%c'\n"
# define PARENTHESIS_ERR "minishell: unexpected newline while \
looking for closing `%c'\n"

extern volatile sig_atomic_t	g_state;

void	clear_exit(t_data *data, int code);

#endif
