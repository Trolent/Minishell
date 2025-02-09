/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:11:00 by trolland          #+#    #+#             */
/*   Updated: 2025/02/09 21:47:50 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	print_error(int status, int is_sig)
{
	if (!is_sig)
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(2, "Quit", 4);
		if (WTERMSIG(status) == SIGBUS)
			write(2, "Bus error (core dumped)", 24);
		write(2, "\n", 1);
	}
}

static void	wait_for_children(t_data *data)
{
	int			status;
	int			is_sig;
	t_pidlst	*node;

	node = data->pidlst;
	status = 0;
	is_sig = 0;
	while (node)
	{
		waitpid(node->pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			data->status = 128 + WTERMSIG(status);
			print_error(status, is_sig);
			is_sig = 1;
		}
		else
			data->status = WEXITSTATUS(status);
		pidlst_eat(&node);
	}
	sigaction(SIGINT, &data->sa, NULL);
	data->pidlst = NULL;
}

int	ft_wait_pid(t_ast *ast, t_data *data)
{
	data->status = exec_recursion(ast->wait_next, data);
	if (!data->pidlst)
		return (data->status);
	wait_for_children(data);
	return (data->status);
}
