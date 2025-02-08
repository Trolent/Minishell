/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:26:23 by trolland          #+#    #+#             */
/*   Updated: 2025/02/08 14:17:49 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_overflow(char *str)
{
	int		len;
	char	*max;
	char	*min;

	len = ft_strlen(str);
	max = "9223372036854775807";
	min = "9223372036854775808";
	if (str[0] == '-' || str[0] == '+')
		len--;
	if (len > 19)
		return (2);
	if (len == 19)
	{
		if (str[0] == '-')
		{
			if (ft_strncmp(str + 1, min, 19) > 0)
				return (2);
		}
		else
		{
			if (ft_strncmp(str, max, 19) > 0)
				return (2);
		}
	}
	return (0);
}
