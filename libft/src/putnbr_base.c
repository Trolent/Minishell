/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:51:51 by trolland          #+#    #+#             */
/*   Updated: 2024/03/30 19:03:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] < ' ' || base[j] > '~'
				|| base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

static int	print_base(unsigned long long nbr, char *base, int base_len)
{
	unsigned long long	div;
	unsigned long long	mod;
	int					count;

	count = 0;
	div = nbr / base_len;
	mod = nbr % base_len;
	if (nbr > (unsigned long long)(base_len - 1))
		count += print_base(div, base, base_len);
	count += ft_putchar(base[mod]);
	return (count);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (check_base(base))
		return (print_base(nbr, base, base_len));
	return (0);
}
