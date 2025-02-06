/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:44:50 by trolland          #+#    #+#             */
/*   Updated: 2024/03/30 19:16:13 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += write_unsigned(n / 10);
	count += ft_putchar(n % 10 + 48);
	return (count);
}

int	write_hex(unsigned int n, char c)
{
	int		count;
	char	*caps;

	if (c == 'x')
		caps = "0123456789abcdef";
	else
		caps = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += write_hex(n / 16, c);
	count += ft_putchar(caps[n % 16]);
	return (count);
}

static int	write_adress(void *addr)
{
	int					count;
	unsigned long long	byte;

	count = 0;
	byte = (unsigned long long)addr;
	if (!addr)
		return (ft_putstr(PTRNULL));
	count += ft_putstr("0x");
	count += ft_putnbr_base(byte, "0123456789abcdef");
	return (count);
}

static int	transform_agr(char c, va_list *ap)
{
	int		count;
	char	*str;

	count = 0;
	if (c == '%')
		count += write(1, "%", 1);
	else if (c == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
	{
		str = va_arg(*ap, char *);
		if (str == NULL)
			count += ft_putstr("(null)");
		else
			count += ft_putstr(str);
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (c == 'p')
		count += write_adress(va_arg(*ap, void *));
	else if (c == 'u')
		count += write_unsigned(va_arg(*ap, unsigned long));
	else if (c == 'x' || c == 'X')
		count += write_hex(va_arg(*ap, int), c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	int	i;

	if (str == NULL)
		return (-1);
	va_list(ap);
	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += transform_agr(str[i], &ap);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
