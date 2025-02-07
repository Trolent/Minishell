/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:50:24 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 09:45:19 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"
#include "builtins.h"

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!*(lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*copy_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = ft_strndup(str, i);
	if (!key)
		return (NULL);
	return (key);
}

t_env	*env_new(char *var)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = copy_key(var);
	if (!node->key)
		return (free(node), NULL);
	if (ft_strchr(var, '='))
	{
		node->value = ft_strdup(var + ft_strlen(node->key) + 1);
		if (!node->value)
		{
			free(node->key);
			free(node);
			return (perror("minishell: ft_strdup"), NULL);
		}
	}
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
}
