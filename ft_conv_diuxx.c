/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_diuxx.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:19:01 by averheij       #+#    #+#                */
/*   Updated: 2019/11/12 15:40:45 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

void	ft_print_int(t_conv *conv, va_list a_list, int *nprint)
{
	int		i;
	int		pow;
	int		temp;
	int		len;

	i = va_arg(a_list, int);
	len = ft_putnbr_size(i, conv);
	if (conv->precision == -2)
		conv->precision = len;
	if (conv->sign && i >= 0 && (conv->padzero || conv->leftj))
		ft_putchar_n_fd(conv->sign, 1, nprint);
	if (i < 0 && (conv->padzero || conv->leftj))
		ft_putchar_n_fd('-', 1, nprint);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, len, '0', nprint);
		ft_putnbr_n_fd(i, nprint);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', nprint);
	else
		ft_pad_width(conv->width, conv->precision, ' ', nprint);
	if (!conv->leftj)
	{
		if (conv->sign && i >= 0 && !conv->padzero)
			ft_putchar_n_fd(conv->sign, 1, nprint);
		if (i < 0 && !conv->padzero)
			ft_putchar_n_fd('-', 1, nprint);
		ft_pad_width(conv->precision, len, '0', nprint);
		ft_putnbr_n_fd(i, nprint);
	}
}

void	ft_print_uint(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("UNSIGNED INT", 1);
}

void	ft_print_hex_lower(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("HEX LOWER", 1);
}

void	ft_print_hex_upper(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("HEX UPPER", 1);
}
