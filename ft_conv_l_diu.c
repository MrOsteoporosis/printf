/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_l_diu.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:22:22 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 10:34:52 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_l_int(t_conv *conv, long *i)
{
	if (*i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->length = ft_putint_l_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_l_int(t_conv *conv, va_list a_list, int *n)
{
	long	i;

	i = va_arg(a_list, long);
	ft_prep_l_int(conv, &i);
	if (conv->hassign && (conv->padzero || conv->leftj))
		ft_putchar_n_fd(conv->sign, 1, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putint_l_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + conv->hassign, '0', n);
	else
		ft_pad_width(conv->width, conv->precision + conv->hassign, ' ', n);
	if (!conv->leftj)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_n_fd(conv->sign, 1, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putint_l_n_fd(i, n);
	}
}

void	ft_prep_l_uint(t_conv *conv, unsigned long *i)
{
	conv->length = ft_putuint_l_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_l_uint(t_conv *conv, va_list a_list, int *n)
{
	unsigned long	i;

	i = va_arg(a_list, unsigned long);
	ft_prep_l_uint(conv, &i);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_l_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', n);
	else
		ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_l_n_fd(i, n);
	}
}
