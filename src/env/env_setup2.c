/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:42 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 16:38:27 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static void	ft_sort_alpha(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;
	char	*tmp3;

	tmp = *env;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp->key, tmp2->key) > 0)
			{
				tmp3 = tmp->key;
				tmp->key = tmp2->key;
				tmp2->key = tmp3;
				tmp3 = tmp->value;
				tmp->value = tmp2->value;
				tmp2->value = tmp3;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static int	export_default_setup(t_data *data)
{
	t_env	*new;
	char	*tmp;

	if (env_lstdup(&data->export, data->env))
		return (1);
	tmp = env_get_value(data->export, "OLDPWD", data);
	if (!tmp)
	{
		new = env_new_key(ft_strdup("OLDPWD"), NULL);
		if (!new)
			return (1);
		env_add_back(&data->export, new);
	}
	ft_sort_alpha(&data->export);
	return (0);
}

static int	env_export_default_setup(t_data *data)
{
	if (env_default_setup(data))
		return (env_clear(&data->env), 1);
	if (export_default_setup(data))
		return (env_clear(&data->env), env_clear(&data->export), 1);
	return (0);
}

static int	env_export_copy(t_data *data, char **env)
{
	if (env_copy(&data->env, env))
		return (1);
	if (export_default_setup(data))
		return (env_clear(&data->env), env_clear(&data->export), 1);
	return (0);
}

int	env_setup(t_data *data, char **env)
{
	if (!env[0])
		return (env_export_default_setup(data));
	return (env_export_copy(data, env));
}
