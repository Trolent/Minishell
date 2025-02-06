/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:38:30 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/06 15:04:19 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "AST.h"
#include "exec.h"
#include "env.h"

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
