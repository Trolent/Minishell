/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:24:29 by trolland          #+#    #+#             */
/*   Updated: 2023/12/02 16:37:58 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else
	{
		if (n < 0)
		{
			n = -n;
			count += ft_putchar_fd('-', fd);
		}
		if (n > 9)
			count += ft_putnbr_fd(n / 10, fd);
		count += ft_putchar_fd(n % 10 + 48, fd);
	}
	return (count);
}
