/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:31:05 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 14:31:10 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	ft_lstdelone_env(t_env **env, t_env *delone)
{
	t_env	*tmp;

	tmp = *env;
	if (delone == tmp)
	{
		*env = (*env)->next;
		free(delone->key);
		free(delone->value);
		free(delone);
		return ;
	}
	while (tmp && tmp->next != delone)
		tmp = tmp->next;
	if (tmp && tmp->next == delone)
	{
		tmp->next = delone->next;
		free(delone->key);
		free(delone->value);
		free(delone);
	}
}

static void	unset_env_var(char *var, t_env **env)
{
	t_env	*tmp;
	t_env	*next;

	tmp = *env;
	while (tmp)
	{
		next = tmp->next;
		if (!ft_strcmp(var, tmp->key))
		{
			ft_lstdelone_env(env, tmp);
			tmp = *env;
		}
		else
			tmp = next;
	}
}

static int	unset_env(char **tab, t_env **env)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		unset_env_var(tab[i], env);
		i++;
	}
	return (0);
}

int	unset(char **tab, t_data *data)
{
	unset_env(tab, &data->env);
	unset_env(tab, &data->export);
	if (tab[1] && !ft_strcmp(tab[1], "PATH"))
	{
		free(data->hardpath);
		data->hardpath = NULL;
	}
	return (0);
}
