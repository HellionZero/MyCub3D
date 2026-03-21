/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:58:05 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 20:09:41 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_int_part(double *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n = -(*n);
	}
	else
		*neg = 0;
	return ((long long)(*n));
}

static long long	pow10_ll(int precision)
{
	long long	v;
	int			idx;

	v = 1;
	idx = 0;
	while (idx < precision)
	{
		v *= 10;
		idx++;
	}
	return (v);
}

static long long	frac_to_digits(double frac, int precision)
{
	long long	result;
	int			idx;

	result = 0;
	idx = 0;
	while (idx < precision)
	{
		frac *= 10.0;
		if (frac < 0.0)
			frac = 0.0;
		result = result * 10 + (long long)frac;
		frac -= (long long)frac;
		idx++;
	}
	return (result);
}

static int	frac_needs_round(double frac)
{
	frac *= 10.0;
	if (frac < 0.0)
		frac = 0.0;
	return ((int)frac >= 5);
}

long long	get_frac_part(double frac, int precision, int *carry)
{
	long long	fracpart;
	long long	limit;

	if (precision <= 0)
	{
		*carry = (frac >= 0.5);
		return (0);
	}
	fracpart = frac_to_digits(frac, precision);
	if (frac_needs_round(frac))
		fracpart += 1;
	limit = pow10_ll(precision);
	if (fracpart >= limit)
	{
		*carry = 1;
		return (0);
	}
	*carry = 0;
	return (fracpart);
}
