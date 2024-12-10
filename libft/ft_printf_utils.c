/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:03:08 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 11:56:14 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int nbr, int size)
{
	if (nbr > 9)
		size = ft_putnbr_u(nbr / 10, size);
	size += ft_putchar(nbr % 10 + '0');
	return (size);
}

int	ft_putnbr_base(unsigned long nbr, int size, char formas)
{
	char	*base;

	if (formas == 'x' || formas == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		size = ft_putnbr_base((nbr / 16), size, formas);
	size += ft_putchar(base[nbr % 16]);
	return (size);
}

int	ft_putadress(void *str, int size)
{
	unsigned long	adress;

	adress = (unsigned long)str;
	if (adress == 0)
	{
		size += ft_putstr("(nil)");
		return (size);
	}
	ft_putstr("0x");
	size += ft_putnbr_base(adress, size, 'p');
	return (size + 2);
}

int	ft_putnbr(int n, int size)
{
	if (n == -2147483648)
		size += ft_putstr("-2147483648");
	else if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
		size = ft_putnbr(n, size);
	}
	else if (n > 9)
	{
		size = ft_putnbr((n / 10), size);
		size += ft_putchar(((n % 10) + '0'));
	}
	else
		size += ft_putchar((n % 10) + '0');
	return (size);
}
