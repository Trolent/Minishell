/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:49:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/09 19:23:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "expand.h"
#include "env.h"

char	*expand_string(char *str, t_data *data, t_files **head)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'')
			sq_copy(str, &i, head);
		else if (str[i] == '"')
			dq_copy2(str, &i, data, head);
		else if (str[i] == '$' && is_variable(str[i + 1]))
			var_copy(str, &i, data, head);
		else if (str[i] == '$' && str[i + 1] == '?')
			status_copy(&i, data, head);
		else if (str[i] == '$' && (str[i + 1] == '\'' 
			|| str[i + 1] == '"' || ft_isdigit(str[i + 1])))
			i += 2;
		else
			regular_copy(str, &i, head);
	}
	return (files_join(head));
}
