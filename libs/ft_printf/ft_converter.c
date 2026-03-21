/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:27:29 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 19:41:32 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converter(char ch, t_format fmt, va_list lst)
{
	if (ch == '%')
		return (ft_putchar('%'));
	else if (ch == 'c')
		return (ft_putchar(va_arg(lst, int)));
	else if (ch == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (ch == 'p')
		return (ft_printptr(va_arg(lst, unsigned long)));
	else if (ch == 'd' || ch == 'i')
		return (ft_printnbr(va_arg(lst, int)));
	else if (ch == 'f')
		return (ft_printfloat(va_arg(lst, double), &fmt));
	else if (ch == 'u')
		return (ft_printmod(va_arg(lst, unsigned int)));
	else if (ch == 'x')
		return (ft_printhex(va_arg(lst, unsigned int), 0));
	else if (ch == 'X')
		return (ft_printhex(va_arg(lst, unsigned int), 1));
	return (0);
}
