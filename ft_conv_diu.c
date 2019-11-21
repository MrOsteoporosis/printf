/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_diu.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:19:01 by averheij       #+#    #+#                */
/*   Updated: 2019/11/21 14:46:00 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_int(t_conv *conv, int *i)
{
	if (conv->size == 'h')
		*i = (short)*i;
	if (conv->size == 'H')
		*i = (char)*i;
	if (*i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->length = ft_putint_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_int(t_conv *conv, va_list a_list, int *n)
{
	int		i;

	i = va_arg(a_list, int);
	ft_prep_int(conv, &i);
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

void	ft_prep_uint(t_conv *conv, unsigned int *i)
{
	if (conv->size == 'h')
		*i = (unsigned short)*i;
	if (conv->size == 'H')
		*i = (unsigned char)*i;
	conv->length = ft_putuint_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_uint(t_conv *conv, va_list a_list, int *n)
{
	unsigned int	i;

	i = va_arg(a_list, unsigned int);
	ft_prep_uint(conv, &i);
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
