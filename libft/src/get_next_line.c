/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:21 by trolland          #+#    #+#             */
/*   Updated: 2024/04/01 10:13:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchr_index_n_strlen(char *s, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		if (!s)
			return (-1);
		while (s[i])
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
		return (-1);
	}
	else
	{
		while (s && s[i])
			i++;
		return (i);
	}
}

static char	*ft_strjoin_to_n(char *s1, char *s2)
{
	int		i;
	int		j;
	int		s1len;
	int		s2len;
	char	*join;

	s1len = ft_strchr_index_n_strlen(s1, 1);
	if (!s2[0])
		return (s1);
	if (ft_strchr_index_n_strlen(s2, 0) != -1)
		s2len = ft_strchr_index_n_strlen(s2, 0);
	else
		s2len = ft_strchr_index_n_strlen(s2, 1) + 1;
	join = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (++i < s1len)
		join[i] = s1[i];
	j = -1;
	while (++j < s2len && s2[j])
		join[i + j] = s2[j];
	free(s1);
	join[i + j] = '\0';
	return (join);
}

static int	ft_clear_temp(char *temp, int n)
{
	int	i;

	i = 0;
	while (temp[n] && n != 0)
	{
		temp[i] = temp[n];
		n++;
		i++;
	}
	temp[i] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	temp[BUFFER_SIZE + 1];
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (temp[0] != 0)
		line = ft_strjoin_to_n(line, temp);
	if (!line && temp[0] != 0)
		return (NULL);
	while (ft_strchr_index_n_strlen(line, 0) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0 && ft_clear_temp(temp, 0))
			return (free(line), NULL);
		temp[bytes_read] = '\0';
		line = ft_strjoin_to_n(line, temp);
		if (!line)
			return (NULL);
	}
	if (ft_strchr_index_n_strlen(temp, 0) >= 0)
		ft_clear_temp(temp, ft_strchr_index_n_strlen(temp, 0));
	return (line);
}
