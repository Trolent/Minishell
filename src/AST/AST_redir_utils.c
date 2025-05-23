/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST_redir_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:42:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "AST.h"

static t_ast	*redir_last(t_ast *lst)
{
	t_ast	*index;

	index = lst;
	if (!lst)
		return (NULL);
	while (index->redir_next)
		index = index->redir_next;
	return (index);
}

void	redir_add_back(t_ast **lst, t_ast *new)
{
	if (!*(lst))
		*lst = new;
	else
		redir_last(*lst)->redir_next = new;
}
