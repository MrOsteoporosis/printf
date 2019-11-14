/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:55:12 by averheij       #+#    #+#                */
/*   Updated: 2019/11/14 12:27:04 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"

int		ft_puthex_size(unsigned int i, t_conv *conv)
{
	unsigned int	temp;
	int				size;

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

void	ft_puthex_lower_n_fd(unsigned int i, int *nprint)
{
	unsigned int	temp;
	unsigned int	pow;
	char			*hex;

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

void	ft_puthex_upper_n_fd(unsigned int i, int *nprint)
{
	unsigned int	temp;
	unsigned int	pow;
	char			*hex;

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

void	ft_prep_hex(t_conv *conv, unsigned int i)
{
	conv->length = ft_puthex_size(i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (i == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && conv->precision != 0))
		conv->precision = conv->length;
}
