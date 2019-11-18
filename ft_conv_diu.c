/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_diu.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:19:01 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 13:23:18 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_int(t_conv *conv, va_list a_list, int *n)
{
	int		i;

	i = va_arg(a_list, int);
	ft_prep_int(conv, i);
	if (conv->hassign && (conv->padzero || conv->leftj))
		ft_putchar_n_fd(conv->sign, 1, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putint_n_fd(i, n);
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
			ft_putint_n_fd(i, n);
	}
}

void	ft_print_uint(t_conv *conv, va_list a_list, int *n)
{
	unsigned int	i;

	i = va_arg(a_list, unsigned int);
	conv->length = ft_putuint_size(i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && conv->precision != 0))
		conv->precision = conv->length;
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', n);
	else
		ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_n_fd(i, n);
	}
}
