/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:15:06 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/06 16:10:29 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	print_error(int status)
{
	if (WTERMSIG(status) == SIGINT)
		write(2, "\n", 1);
	if (WTERMSIG(status) == SIGQUIT)
		write(2, "Quit\n", 5);
	if (WTERMSIG(status) == SIGBUS)
		write(2, "Bus error (core dumped)\n", 25);
}

static void	wait_for_children(t_data *data)
{
	int			status;
	t_pidlst	*node;
	t_pidlst	*tmp;

	node = data->pidlst;
	status = 0;
	while (node)
	{
		waitpid(node->pid, &status, 0);
		if (WIFSIGNALED(status))
			data->status = 128 + WTERMSIG(status);
		else
			data->status = WEXITSTATUS(status);
		tmp = node;
		node = node->next;
		free(tmp);
		tmp = NULL;
	}
	print_error(status);
	data->pidlst = NULL;
	sigaction(SIGINT, &data->sa, NULL);
}

int	ft_wait_pid(t_ast *ast, t_data *data)
{
	data->status = exec_recursion(ast->wait_next, data);
	if (!data->pidlst)
		return (data->status);
	wait_for_children(data);
	return (data->status);
}
