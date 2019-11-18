/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:54:34 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 11:37:56 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_int(t_conv *conv, int i)
{
	if (i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->length = ft_putint_size(i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && conv->precision != 0))
		conv->precision = conv->length;
}

int		ft_putint_size(int i, t_conv *conv)
{
	int		temp;
	int		size;

	temp = i;
	size = 0;
	if (i == 0)
		size++;
	while (temp)
	{
		temp = temp / 10;
		size++;
	}
	return (size);
}

void	ft_putint_n_fd(int i, int *nprint)
{
	int		temp;
	int		pow;

	temp = i;
	pow = 1;
	while (temp / 10)
	{
		temp = temp / 10;
		pow = pow * 10;
	}
	while (pow)
	{
		ft_putchar_n_fd(((i < 0) ? '0' - i / pow : '0' + i / pow), 1, nprint);
		i = i % pow;
		pow = pow / 10;
	}
}

int		ft_putuint_size(unsigned int i, t_conv *conv)
{
	unsigned int	temp;
	int				size;

	temp = i;
	size = 0;
	if (i == 0)
		size++;
	while (temp)
	{
		temp = temp / 10;
		size++;
	}
	return (size);
}

void	ft_putuint_n_fd(unsigned int i, int *nprint)
{
	unsigned int	temp;
	unsigned int	pow;

	temp = i;
	pow = 1;
	while (temp / 10)
	{
		temp = temp / 10;
		pow = pow * 10;
	}
	while (pow)
	{
		ft_putchar_n_fd('0' + i / pow, 1, nprint);
		i = i % pow;
		pow = pow / 10;
	}
}
