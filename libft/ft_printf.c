/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:13:32 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 11:56:17 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_printf_forms(va_list params, const char *str, int size)
{
	if (*str == 'c')
		size += ft_putchar((char)va_arg(params, int));
	else if (*str == 's')
		size += ft_putstr(va_arg(params, char *));
	else if (*str == 'p')
		size += ft_putadress(va_arg(params, void *), 0);
	else if (*str == 'd' || *str == 'i')
		size += ft_putnbr(va_arg(params, int), 0);
	else if (*str == 'u')
		size += ft_putnbr_u(va_arg(params, int), 0);
	else if (*str == 'x')
		size += ft_putnbr_base(va_arg(params, unsigned int), 0, 'x');
	else if (*str == 'X')
		size += ft_putnbr_base(va_arg(params, unsigned int), 0, 'X');
	else
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		size;

	va_start(params, str);
	size = 0;
	if (!str || (str[0] == '%' && str[1] == '\0'))
		return (-1);
	while (*str)
	{
		if (*str != '%')
			size += ft_putchar(*str);
		if (*str == '%')
		{
			str++;
			size = ft_printf_forms(params, str, size);
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X'
				|| *str == '%')
				str++;
		}
		else
			str++;
	}
	va_end(params);
	return (size);
}
