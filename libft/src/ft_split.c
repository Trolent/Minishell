/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:00 by trolland          #+#    #+#             */
/*   Updated: 2023/09/18 13:48:16 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char charset)
{
	if (c == charset)
		return (0);
	return (1);
}

static int	ft_count_words(char const *str, char charset)
{
	int	i;
	int	expecting;
	int	word_count;

	i = 0;
	expecting = 1;
	word_count = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) && expecting == 1)
		{
			word_count++;
			expecting = 0;
		}
		if (!ft_is_charset(str[i], charset) && expecting == 0)
			expecting = 1;
		i++;
	}
	return (word_count);
}

static char	*ft_create_sub_tab(char const *s, char c, int *pos)
{
	int		len;
	int		k;
	char	*tab;

	len = 0;
	k = 0;
	while (!ft_is_charset(s[*pos], c))
		(*pos)++;
	while (ft_is_charset(s[*pos + len], c) && s[*pos + len])
		len++;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (k < len)
	{
		tab[k] = s[(*pos)];
		k++;
		(*pos)++;
	}
	tab[k] = '\0';
	return (tab);
}

static void	ft_free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	word_count = (ft_count_words(s, c));
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (i < word_count)
	{
		split[i] = ft_create_sub_tab(s, c, &j);
		if (!split[i])
		{
			ft_free_tab(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
