/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:23:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/06 13:52:40 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

static void	change_pwd(t_env **env)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = env_get_real_node(env, "OLDPWD");
	pwd = env_get_real_node(env, "PWD");
	if (oldpwd)
	{
		free(oldpwd->value);
		if (pwd)
			oldpwd->value = pwd->value;
		else
			oldpwd->value = NULL;
	}
	if (pwd)
		pwd->value = getcwd(NULL, 0);
}

static char	*get_home_directory(t_env **env, t_data *data)
{
	char	*home;

	home = env_get_value(*env, "HOME", data);
	if (!home)
		ft_dprintf(2, "minishell: cd: HOME not set\n");
	return (home);
}

int	builtin_cd(t_data *data, char **args, t_env **env)
{
	char	*path;

	if (!args[1])
	{
		path = get_home_directory(env, data);
		if (!path)
			return (1);
	}
	else if (args[2])
		return (ft_dprintf(2, "minishell: cd: too many arguments\n"), 1);
	else
		path = args[1];
	if (chdir(path))
	{
		ft_dprintf(2, "minishell: cd: %s: %s\n", path, strerror(errno));
		return (1);
	}
	change_pwd(env);
	return (0);
}
