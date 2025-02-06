/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:39:34 by trolland          #+#    #+#             */
/*   Updated: 2023/09/06 09:59:38 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

static void	ft_putnbrstr(int n, int i, char *str)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[i - 1] = n % 10 + '0';
	if (n > 9)
		ft_putnbrstr(n / 10, i - 1, str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_itoalen(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else
	{
		ft_putnbrstr(n, i, str);
		str[i] = '\0';
	}
	return (str);
}
