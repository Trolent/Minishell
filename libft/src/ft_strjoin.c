/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:21 by trolland          #+#    #+#             */
/*   Updated: 2023/09/18 12:11:25 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_valid_len(int *s1len, int *s2len, char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		*s1len = ft_strlen(s1);
		*s2len = ft_strlen(s2);
		return (1);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (!ft_valid_len(&s1len, &s2len, s1, s2))
		return (NULL);
	join = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
