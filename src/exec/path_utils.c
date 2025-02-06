/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:08:20 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/06 16:45:27 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// Function to find the PATH environment variable
char	*find_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

// Function to free a 2D array
void	free_tab_2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// Function to find the command path in the PATH directories
char	*find_path_cmd(char **path_env, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*full_cmd_path;

	i = 0;
	while (path_env[i])
	{
		cmd_path = ft_strjoin(path_env[i], "/");
		full_cmd_path = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (!access(full_cmd_path, X_OK))
			return (full_cmd_path);
		free(full_cmd_path);
		i++;
	}
	return (NULL);
}

// Main function to find the command path
char	*find_cmd(char **cmd, char **envp)
{
	char	**path_env;
	char	*cmd_path;

	path_env = ft_split(find_path_env(envp), ':');
	if (!path_env)
		return (NULL);
	cmd_path = find_path_cmd(path_env, cmd[0]);
	ft_free_tab(path_env);
	return (cmd_path);
}
