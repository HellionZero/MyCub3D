/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:10:33 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 20:28:48 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_frac(long long fracpart, int precision)
{
	char	buf[32];
	int		i;
	int		count;

	if (precision <= 0)
		return (0);
	buf[precision] = '\0';
	i = precision;
	while (i-- > 0)
	{
		buf[i] = (fracpart % 10) + '0';
		fracpart /= 10;
	}
	count = ft_putstr(buf);
	return (count);
}

void	parse_flags(const char *fstring, int *i, t_format *fmt)
{
	while (fstring[*i] == '0' || fstring[*i] == '-')
	{
		if (fstring[*i] == '0')
			fmt->zero_pad = 1;
		else if (fstring[*i] == '-')
			fmt->left_align = 1;
		(*i)++;
	}
}

long long	get_int_digits(long long value)
{
	long long	digits;

	digits = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 10;
		digits++;
	}
	return (digits);
}

int	output_float_number(long long intpart, long long fracpart,
						int precision, int neg)
{
	int	count;

	count = 0;
	if (neg)
		count += ft_putchar('-');
	count += ft_printnbr(intpart);
	if (precision > 0)
	{
		count += ft_putchar('.');
		count += print_frac(fracpart, precision);
	}
	return (count);
}

int	get_precision(t_format *fmt)
{
	if (fmt && fmt->precision_set)
	{
		if (fmt->precision < 0)
			return (6);
		return (fmt->precision);
	}
	return (6);
}
