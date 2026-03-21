/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:42:52 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 20:01:40 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_width(const char *fstring, int *i, t_format *fmt)
{
	if (fstring[*i] >= '1' && fstring[*i] <= '9')
	{
		fmt->has_width = 1;
		fmt->width = 0;
		while (fstring[*i] >= '0' && fstring[*i] <= '9')
		{
			fmt->width = fmt->width * 10 + (fstring[*i] - '0');
			(*i)++;
		}
	}
}

static void	parse_precision(const char *fstring, int *i, t_format *fmt)
{
	if (fstring[*i] == '.')
	{
		fmt->dot = 1;
		(*i)++;
		if (fstring[*i] >= '0' && fstring[*i] <= '9')
		{
			fmt->precision_set = 1;
			fmt->precision = 0;
			while (fstring[*i] >= '0' && fstring[*i] <= '9')
			{
				fmt->precision = fmt->precision * 10 + (fstring[*i] - '0');
				(*i)++;
			}
		}
		else
			fmt->precision_set = 1;
	}
}

static int	process_format(const char *fstring, int *i, va_list *ls)
{
	int			count;
	t_format	fmt;

	count = 0;
	fmt = (t_format){0, 0, 0, 0, 0, 0, 0, 0, 0};
	fmt.precision = 6;
	(*i)++;
	parse_flags(fstring, i, &fmt);
	parse_width(fstring, i, &fmt);
	parse_precision(fstring, i, &fmt);
	fmt.spec = fstring[*i];
	if (!fmt.spec)
		return (0);
	count = ft_converter(fmt.spec, fmt, *ls);
	(*i)++;
	return (count);
}

int	ft_printf(const char *fstring, ...)
{
	va_list		ls;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ls, fstring);
	while (fstring[i] != '\0')
	{
		if (fstring[i] == '%')
		{
			count += process_format(fstring, &i, &ls);
		}
		else
		{
			count += ft_putchar(fstring[i]);
			i++;
		}
	}
	va_end(ls);
	return (count);
}
