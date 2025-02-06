/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:42:26 by trolland          #+#    #+#             */
/*   Updated: 2023/10/05 14:29:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	sublen;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	sublen = ft_strlen(s + start);
	if (sublen > len)
		sublen = len;
	newstr = malloc(sizeof(char) * sublen + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s + start, sublen + 1);
	return (newstr);
}
