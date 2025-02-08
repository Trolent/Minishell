/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/08 14:07:33 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"
#include "setup.h"

volatile sig_atomic_t	g_state;

static void	ft_sort_alpha(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;
	char	*tmp3;

	tmp = *env;
	while (tmp && tmp->next)
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

static int	setup_export_env(t_data *data)
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

static int	env_setup(t_data *data, char **env)
{
	if (!env[0])
	{
		if (env_default_setup(data))
			return (env_clear(&data->env), 1);
	}
	else
	{
		if (env_copy(&data->env, env))
			return (1);
	}
	if (setup_export_env(data))
		return (env_clear(&data->env), env_clear(&data->export), 1);
	return (0);
}

int	setup_shell(t_data *data, char **env)
{
	*data = (t_data){};
	g_state = 0;
	if (env_setup(data, env))
		return (1);
	rl_outstream = stderr;
	setup_signals(data);
	return (0);
}
