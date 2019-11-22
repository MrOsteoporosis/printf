/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_l_xx.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:11:03 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 10:46:47 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_l_hex(t_conv *conv, unsigned long *i)
{
	conv->length = ft_puthex_l_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*i == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_l_hex_lower(t_conv *conv, va_list a_list, int *n)
{
	unsigned long	i;

	i = va_arg(a_list, unsigned long);
	ft_prep_l_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0x", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_l_lower_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', n);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', n);
	if (!conv->leftj)
	{
		if (conv->hash && i != 0 && !conv->padzero)
			ft_putnstr_n_fd("0x", 1, 2, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_l_lower_n_fd(i, n);
	}
}

void	ft_print_l_hex_upper(t_conv *conv, va_list a_list, int *n)
{
	unsigned long	i;

	i = va_arg(a_list, unsigned long);
	ft_prep_l_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0X", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_l_upper_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', n);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', n);
	if (!conv->leftj)
	{
		if (conv->hash && i != 0 && !conv->padzero)
			ft_putnstr_n_fd("0X", 1, 2, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_l_upper_n_fd(i, n);
	}
}
