/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:23:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/09 21:47:59 by trolland         ###   ########.fr       */
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
		ft_dprintf(STDERR_FILENO, "minishell: cd: HOME not set\n");
	return (home);
}

static char	*expand_tilde(char *path, t_env **env, t_data *data)
{
	char	*home;
	char	*expanded_path;

	if (path[0] == '~')
	{
		home = env_get_value(*env, "HOME", data);
		if (!home)
		{
			ft_dprintf(STDERR_FILENO, "minishell: cd: HOME not set\n");
			return (NULL);
		}
		expanded_path = ft_strjoin(home, path + 1);
		if (!expanded_path)
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: cd: memory allocation error\n");
			return (NULL);
		}
		return (expanded_path);
	}
	return (ft_strdup(path));
}

static char	*no_path_or_empty(char *path, t_data *data, t_env **env, int *ret)
{
	char	*expanded_path;

	if (!path)
	{
		*ret = 1;
		return (NULL);
	}
	else if (path[0] == '\0')
	{
		*ret = 0;
		return (NULL);
	}
	expanded_path = expand_tilde(path, env, data);
	if (!expanded_path)
	{
		*ret = 1;
		return (NULL);
	}
	*ret = 2;
	return (expanded_path);
}

int	builtin_cd(t_data *data, char **args, t_env **env)
{
	char	*path;
	int		ret;

	if (!args[1])
	{
		path = get_home_directory(env, data);
		if (!path)
			return (1);
	}
	else if (args[2])
		return (ft_dprintf(STDERR_FILENO,
				"minishell: cd: too many arguments\n"), 1);
	else
		path = args[1];
	path = no_path_or_empty(path, data, env, &ret);
	if (ret == 1 || ret == 0)
		return (free(path), ret);
	if (chdir(path))
	{
		ft_dprintf(STDERR_FILENO, "minishell: cd: %s: %s\n", path,
			strerror(errno));
		return (free(path), 1);
	}
	return (free(path), change_pwd(env), 0);
}
