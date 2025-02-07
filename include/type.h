/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:53:30 by trolland          #+#    #+#             */
/*   Updated: 2025/02/07 17:31:19 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <signal.h>
# include <stdbool.h>
# include <termios.h>

/*#############################################################################
#                                  Enums                                      #
#############################################################################*/

typedef enum e_node
{
	CMD,
	OPERATOR,
	REDIR,
	PIPE_NODE,
	SUBSHELL,
	WAIT_NODE
}							t_node;

typedef enum e_token
{
	PIPE = '|',
	PARENTHESIS_L = '(',
	PARENTHESIS_R = ')',
	S_QUOTE = '\'',
	D_QUOTE = '\"',
	OUT = '>',
	IN = '<',
	BACKGROUND = '&',
	WORD = 1000,
	AND = 1001,
	OR = 1002,
	APPEND = 1003,
	HERE_DOC = 1004
}							t_type;

/*#############################################################################
#                                  Structures                                 #
#############################################################################*/

typedef struct s_env
{
	char					*key;
	char					*value;
	struct s_env			*next;
}							t_env;

typedef struct s_token
{
	int						type;
	int						fd;
	char					*value;
	struct s_token			*next;
	struct s_token			*prev;
}							t_token;

typedef struct s_cmdlist
{
	t_type					type;
	int						fd;
	char					*str;
	struct s_cmdlist		*next;
}							t_cmdlst;

typedef struct s_pidlst
{
	pid_t					pid;
	struct s_pidlst			*next;
}							t_pidlst;

typedef struct s_fdlst
{
	int						fd;
	bool					close_in_child;
	struct s_fdlst			*next;
}							t_fdlst;

typedef struct s_ast
{
	t_node					type;
	union
	{
		struct
		{
			char			**cmd;
		};
		struct
		{
			t_type			op_type;
			struct s_ast	*op_left;
			struct s_ast	*op_right;
		};
		struct
		{
			t_type			redir_type;
			char			*redir_filename;
			int				redir_fd;
			struct s_ast	*redir_next;
		};
		struct
		{
			struct s_ast	*pipe_left;
			struct s_ast	*pipe_right;
		};
		struct
		{
			struct s_ast	*subshell_next;
		};
		struct
		{
			struct s_ast	*wait_next;
		};
	};
}							t_ast;

typedef struct s_data
{
	bool					fork;
	bool					subshell;
	int						status;
	char					*hardpath;
	t_ast					*ast_root;
	t_pidlst				*pidlst;
	t_fdlst					*fdlst;
	t_env					*env;
	t_env					*export;
	struct sigaction		sa;
	struct termios			term;
}							t_data;

#endif