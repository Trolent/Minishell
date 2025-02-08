/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:04:39 by trolland          #+#    #+#             */
/*   Updated: 2025/02/08 13:05:36 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_change_value(t_env *node, char *str)
{
	char	*tmp;

	free(node->value);
	if (ft_strchr(str, '='))
	{
		tmp = ft_strdup(str + ft_strlen(node->key) + 1);
		if (!tmp)
			return (1);
		str = remove_quotes(tmp);
		free(tmp);
		if (!str)
			return (1);
		node->value = str;
	}
	else
		node->value = NULL;
	return (0);
}

static int	check_alnum_str(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] != '=')
		return (2);
	return (1);
}

static int	update_or_add_node(t_env **env, char *str)
{
	t_env	*node;
	char	*key_tmp;
	char	*equal_sign;

	equal_sign = ft_strchr(str, '=');
	if (equal_sign)
		key_tmp = ft_strndup(str, equal_sign - str);
	else
		key_tmp = ft_strdup(str);
	if (!key_tmp)
		return (1);
	node = env_get_node(*env, key_tmp);
	free(key_tmp);
	if (!node)
	{
		node = env_new(str);
		if (!node)
			return (1);
		env_add_back(env, node);
	}
	else if (equal_sign)
		if (ft_change_value(node, str))
			return (1);
	return (0);
}

int	check_and_update_env(t_env **env, char *str)
{
	int	check;

	check = check_alnum_str(str);
	if (check == 0)
		return (ft_dprintf(2,
				"minishell: export: `%s': not a valid identifier\n", str), 1);
	else if (check == 2)
		return (update_or_add_node(env, str));
	return (update_or_add_node(env, str));
}
