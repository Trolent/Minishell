
#include "builtins.h"

int	parse_flags(char **strs, int *i)
{
	int	flag;

	flag = 0;
	while (strs[*i] && strs[*i][0] == '-' && strs[*i][1] == 'n')
	{
		int j = 1;
		while (strs[*i][j] == 'n')
			j++;
		if (strs[*i][j] != '\0')
			break;
		flag = 1;
		(*i)++;
	}
	return (flag);
}

int	builtin_echo(char **strs)
{
	int	i;
	int	err;
	int	nl;

	i = 1;
	err = 0;
	nl = parse_flags(strs, &i);
	while (strs[i])
	{
		err = ft_dprintf(STDOUT_FILENO, "%s", strs[i]);
		if (strs[i + 1])
			err = ft_dprintf(STDOUT_FILENO, " ");
		i++;
	}
	if (!nl)
		err = ft_dprintf(STDOUT_FILENO, "\n");
	if (err == -1)
		return (perror("minishell: echo: write error"), 1);
	return (0);
}
