/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:15:56 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 20:28:16 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		width;
	int		has_width;
	int		precision;
	int		precision_set;
	int		zero_pad;
	int		left_align;
	int		sign;
	int		dot;
	char	spec;
}	t_format;

int			ft_printf(const char *fstring, ...);
int			ft_putchar(int c);
long		ft_putstr(const char *ch);
int			ft_converter(char ch, t_format fmt, va_list lst);
void		parse_flags(const char *fstring, int *i, t_format *fmt);
long long	get_int_part(double *n, int *neg);
long long	get_frac_part(double frac, int precision, int *carry);
int			output_float_number(long long intpart, long long fracpart,
				int precision, int neg);
long long	get_int_digits(long long value);
int			get_precision(t_format *fmt);
int			print_frac(long long fracpart, int precision);
int			ft_printfloat(double n, t_format *fmt);
int			ft_printnbr(long n);
int			ft_printmod(unsigned int n);
int			ft_printhex(unsigned int ch, int upper);
int			ft_printptr(unsigned long ptr);

#endif