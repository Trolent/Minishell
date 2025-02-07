/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:42:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:11 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "AST.h"

static void	ast_free_first_half(t_ast *ast)
{
	if (ast->type == CMD)
	{
		ft_free_tab(ast->cmd);
		free(ast);
	}
	else if (ast->type == OPERATOR)
	{
		ast_free(ast->op_left);
		ast_free(ast->op_right);
		free(ast);
	}
	else if (ast->type == REDIR)
	{
		ast_free(ast->redir_next);
		free(ast->redir_filename);
		free(ast);
	}
}

static void	ast_free_second_half(t_ast *ast)
{
	if (ast->type == PIPE_NODE)
	{
		ast_free(ast->pipe_left);
		ast_free(ast->pipe_right);
		free(ast);
	}
	else if (ast->type == SUBSHELL)
	{
		ast_free(ast->subshell_next);
		free(ast);
	}
	else if (ast->type == WAIT_NODE)
	{
		ast_free(ast->wait_next);
		free(ast);
	}
}

void	ast_free(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == CMD || ast->type == OPERATOR
		|| ast->type == REDIR)
		ast_free_first_half(ast);
	else
		ast_free_second_half(ast);
}
