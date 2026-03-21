/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:00:35 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 20:31:23 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_padding(int width, int len, int neg)
{
	int	pad_len;
	int	count;

	count = 0;
	pad_len = width - len - neg;
	while (pad_len-- > 0)
		count += ft_putchar(' ');
	if (neg)
		count += ft_putchar('-');
	return (count);
}

static long long	compute_float_len(long long intpart, int precision)
{
	long long	len;

	len = get_int_digits(intpart);
	if (precision > 0)
		len += 1 + precision;
	return (len);
}

static int	print_float_output(long long intpart, long long fracpart,
							int neg, t_format *fmt)
{
	int			count;
	long long	len;
	int			precision;

	precision = get_precision(fmt);
	count = 0;
	len = compute_float_len(intpart, precision);
	if (fmt && fmt->width > 0)
	{
		count += print_padding(fmt->width, (int)len, neg);
		neg = 0;
	}
	count += output_float_number(intpart, fracpart, precision, neg);
	return (count);
}

int	ft_printfloat(double n, t_format *fmt)
{
	int			neg;
	long long	intpart;
	long long	fracpart;
	int			precision;
	int			carry;

	intpart = get_int_part(&n, &neg);
	precision = get_precision(fmt);
	fracpart = get_frac_part(n, precision, &carry);
	if (carry)
		intpart++;
	return (print_float_output(intpart, fracpart, neg, fmt));
}
