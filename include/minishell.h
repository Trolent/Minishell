/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:41:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/08 13:04:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*#############################################################################
#                                  Includes                                   #
#############################################################################*/

/* Standard libraries */
# include <curses.h>    // tgetent, tgetflag, tgetnum, getstr, tgoto, tputs
# include <dirent.h>    // opendir, readdir, closedir
# include <errno.h>     // errno
# include <fcntl.h>     // open
# include <signal.h>    // signal, sigaction, sigemptyset, sigaddset, kill
# include <stdbool.h>   // bool type
# include <stdio.h>     // printf, perror
# include <stdlib.h>    // malloc, free, exit, getenv
# include <string.h>    // strerror
# include <sys/ioctl.h> // ioctl
# include <sys/stat.h>  // stat, lstat, fstat
# include <sys/types.h> // various types
# include <sys/wait.h>  // wait
# include <termios.h>   // tcsetattr, tcgetattr
# include <unistd.h>    /* write, access, open, read, close, fork, getcwd,
chdir, dup, dup2, pipe, execve, isatty, ttyname, ttyslot*/

/* Readline library */
# include <readline/history.h>
# include <readline/readline.h>

/* Custom libraries */
# include "libft.h" // libft functions
# include "type.h"  // custom types

/*#############################################################################
#                                  Defines                                    #
#############################################################################*/

# define RED "\001\x1b[31m\002"
# define GREEN "\001\x1b[32m\002"
# define YELLOW "\001\x1b[33m\002"
# define BLUE "\001\x1b[34m\002"
# define MAGENTA "\001\x1b[35m\002"
# define CYAN "\001\x1b[36;1m\002"
# define RESET "\001\x1b[0m\002"

# define HARDPATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
# define SYNTAX_ERR "minishell: syntax error near unexpected token `%s'\n"
# define NEWLINE_ERR "minishell: unexpected \
newline while looking for matching `%c'\n"
# define PARENTHESIS_ERR "minishell: unexpected newline \
while looking for closing `%c'\n"

/*#############################################################################
#                                  Globals                                    #
#############################################################################*/

extern volatile sig_atomic_t	g_state;

/*#############################################################################
#                                  Functions                                  #
#############################################################################*/

void							clear_exit(t_data *data, int code);

#endif
