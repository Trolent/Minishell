/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AST_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:42:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 16:45:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "AST.h"

void	eat_token(t_token **tk)
{
	t_token	*tmp;

	if (!(*tk) || !tk)
		return ;
	tmp = (*tk)->next;
	free((*tk)->value);
	free(*tk);
	*tk = tmp;
	if (*tk)
		(*tk)->prev = NULL;
}
