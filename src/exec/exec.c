/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:07:09 by trolland          #+#    #+#             */
/*   Updated: 2025/02/08 13:11:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "AST.h"
#include "exec.h"
#include "env.h"

static int	ft_operator(t_ast *ast, t_data *data)
{
	exec_recursion(ast->op_left, data);
	if (ast->op_type == OR && data->status)
		data->status = exec_recursion(ast->op_right, data);
	else if (ast->op_type == AND && !data->status)
		data->status = exec_recursion(ast->op_right, data);
	return (data->status);
}

int	exec_recursion(t_ast *ast, t_data *data)
{
	if (ast->type == PIPE_NODE)
		pipe_node(ast, data);
	if (ast->type == SUBSHELL)
		subshell_node(ast, data);
	if (ast->type == CMD)
		data->status = command_node(ast, data);
	if (ast->type == WAIT_NODE)
		ft_wait_pid(ast, data);
	if (ast->type == OPERATOR)
		ft_operator(ast, data);
	if (ast->type == REDIR)
		redir_node(ast, data);
	return (data->status);
}
