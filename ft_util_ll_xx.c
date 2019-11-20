/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_ll_xx.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:04:06 by averheij       #+#    #+#                */
/*   Updated: 2019/11/20 13:14:26 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_ll_hex(t_conv *conv, unsigned long long *i)
{
	if (conv->size == 'l')
		*i = (long)*i;
	conv->length = ft_puthex_ll_size(*i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*i == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && conv->precision != 0))
		conv->precision = conv->length;
}

int		ft_puthex_ll_size(unsigned long long i, t_conv *conv)
{
	unsigned long long	temp;
	int					size;

	temp = i;
	size = 0;
	if (i == 0)
		size++;
	while (temp)
	{
		temp = temp / 16;
		size++;
	}
	return (size);
}

void	ft_puthex_ll_lower_n_fd(unsigned long long i, int *nprint)
{
	unsigned long long	temp;
	unsigned long long	pow;
	char				*hex;

	hex = "0123456789abcdef";
	temp = i;
	pow = 1;
	while (temp / 16)
	{
		temp = temp / 16;
		pow = pow * 16;
	}
	temp = i;
	while (pow)
	{
		ft_putchar_n_fd(hex[i / pow], 1, nprint);
		i = i % pow;
		pow = pow / 16;
	}
}

void	ft_puthex_ll_upper_n_fd(unsigned long long i, int *nprint)
{
	unsigned long long	temp;
	unsigned long long	pow;
	char				*hex;

	hex = "0123456789ABCDEF";
	temp = i;
	pow = 1;
	while (temp / 16)
	{
		temp = temp / 16;
		pow = pow * 16;
	}
	temp = i;
	while (pow)
	{
		ft_putchar_n_fd(hex[i / pow], 1, nprint);
		i = i % pow;
		pow = pow / 16;
	}
}
