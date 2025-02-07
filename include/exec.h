/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:01:27 by trolland          #+#    #+#             */
/*   Updated: 2025/02/07 17:05:01 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "builtins.h"
# include "expand.h"

/*#############################################################################
#                              command_node.c                                 #
#############################################################################*/

int			command_node(t_ast *ast, t_data *data);

/*#############################################################################
#                              command_utils.c                                #
#############################################################################*/

void		clear_exit(t_data *data, int code);
char		*meet_in_the_middle(char *s1, char *s2, char c);
int			hard_path_check(char *cmd);

/*#############################################################################
#                                  exec.c                                     #
#############################################################################*/

int			exec_recursion(t_ast *ast, t_data *data);

/*#############################################################################
#                               pipe_node.c                                   #
#############################################################################*/

int			pipe_node(t_ast *ast, t_data *data);

/*#############################################################################
#                               exec_cmd.c                                    #
#############################################################################*/

int			ft_is_builtins(char *cmd);
int			ft_builtins(t_ast *ast, t_data *data);

/*#############################################################################
#                                pidlst.c                                     #
#############################################################################*/

t_pidlst	*ft_lstnew_pidlst(pid_t pid);
void		ft_lstadd_back_pidlst(t_pidlst **lst, t_pidlst *new);
void		pidlst_clear(t_pidlst **lst);

/*#############################################################################
#                                 wait_pid.c                                  #
#############################################################################*/

int			ft_wait_pid(t_ast *ast, t_data *data);

/*#############################################################################
#                               operator.c                                    #
#############################################################################*/

int			ft_operator(t_ast *ast, t_data *data);

/*#############################################################################
#                               subshell.c                                    #
#############################################################################*/

int			subshell_node(t_ast *ast, t_data *data);

/*#############################################################################
#                            redir_lst_clear.c                                #
#############################################################################*/

void		fdlst_clear(t_fdlst **lst);
void		fdlst_clear_leftovers(t_fdlst **lst);
void		fdlst_eat(t_fdlst **node);
void		fdlst_delete_node(t_fdlst **lst, int key);

/*#############################################################################
#                              redir_lst.c                                    #
#############################################################################*/

t_fdlst		*fdlst_new(int fd, bool close_in_child);
int			fdlst_add_front(t_fdlst **lst, t_fdlst *new);
void		fdlst_close_in_child(t_fdlst *lst);

/*#############################################################################
#                               redir_hd.c                                    #
#############################################################################*/

int			redir_hd(t_ast *ast, t_data *data);

/*#############################################################################
#                                redir_node.c                                 #
#############################################################################*/

int			redir_node(t_ast *ast, t_data *data);

/*#############################################################################
#                                redir_node.c                                 #
#############################################################################*/

int			redir_expand(t_ast *ast, t_data *data);

/*#############################################################################
#                           execution_loop.c                                  #
#############################################################################*/

void		execution_loop(t_data *data);
void		flag_c(char *line, t_data *data);

/*#############################################################################
#                          non_interactive.c                                  #
#############################################################################*/

void		non_interactive_shell(t_data *data);

#endif
