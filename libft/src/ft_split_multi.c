/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:00 by trolland          #+#    #+#             */
/*   Updated: 2024/05/07 18:48:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset_multi(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_words_multi(char const *str, char *charset)
{
	int	i;
	int	expecting;
	int	word_count;

	i = 0;
	expecting = 1;
	word_count = 0;
	while (str[i])
	{
		if (ft_is_charset_multi(str[i], charset) && expecting == 1)
		{
			word_count++;
			expecting = 0;
		}
		if (!ft_is_charset_multi(str[i], charset) && expecting == 0)
			expecting = 1;
		i++;
	}
	return (word_count);
}

static char	*ft_create_sub_tab(char const *s, char *c, int *pos)
{
	int		len;
	int		k;
	char	*tab;

	len = 0;
	k = 0;
	while (!ft_is_charset_multi(s[*pos], c))
		(*pos)++;
	while (ft_is_charset_multi(s[*pos + len], c) && s[*pos + len])
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

char	**ft_split_multi(char const *s, char *c)
{
	int		i;
	int		j;
	int		word_count;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	word_count = (ft_count_words_multi(s, c));
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (i < word_count)
	{
		split[i] = ft_create_sub_tab(s, c, &j);
		if (!split[i])
		{
			ft_free_tab(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
