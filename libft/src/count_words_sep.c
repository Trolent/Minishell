/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_sep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:10 by trolland          #+#    #+#             */
/*   Updated: 2024/02/02 14:47:33 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char *charset)
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

int	count_words_sep(char const *str, char *charset)
{
	int	i;
	int	expecting;
	int	word_count;

	i = 0;
	expecting = 1;
	word_count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset) && expecting == 1)
		{
			word_count++;
			expecting = 0;
		}
		if (is_charset(str[i], charset) && expecting == 0)
			expecting = 1;
		i++;
	}
	return (word_count);
}
