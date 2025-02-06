/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:08:40 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 15:08:46 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	subshell_child(t_ast *ast, t_data *data)
{
	data->status = exec_recursion(ast->subshell_next, data);
	fdlst_close_in_child(data->fdlst);
	clear_exit(data, data->status);
}

int	subshell_node(t_ast *ast, t_data *data)
{
	pid_t		pid;
	t_pidlst	*new;

	data->fork = true;
	pid = fork();
	if (pid < 0)
		return (perror("minishell: fork"), 1);
	if (pid == 0)
		subshell_child(ast, data);
	else
	{
		signal(SIGINT, SIG_IGN);
		new = ft_lstnew_pidlst(pid);
		if (!new)
			return (1);
		ft_lstadd_back_pidlst(&data->pidlst, new);
	}
	data->fork = false;
	return (data->status);
}
