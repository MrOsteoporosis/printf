/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_xx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:17:40 by averheij       #+#    #+#                */
/*   Updated: 2019/11/21 14:50:01 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_hex(t_conv *conv, unsigned int *i)
{
	if (conv->size == 'h')
		*i = (unsigned short)*i;
	if (conv->size == 'H')
		*i = (unsigned char)*i;
	conv->length = ft_puthex_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*i == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_hex_lower(t_conv *conv, va_list a_list, int *n)
{
	unsigned int	i;

	i = va_arg(a_list, unsigned int);
	ft_prep_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0x", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_lower_n_fd(i, n);
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
			ft_puthex_lower_n_fd(i, n);
	}
}

void	ft_print_hex_upper(t_conv *conv, va_list a_list, int *n)
{
	unsigned int	i;

	i = va_arg(a_list, unsigned int);
	ft_prep_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0X", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_upper_n_fd(i, n);
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
			ft_puthex_upper_n_fd(i, n);
	}
}
