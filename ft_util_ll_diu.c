/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_ll_int.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:37:31 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 14:28:53 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prep_ll_int(t_conv *conv, long long *i)
{
	if (conv->size == 'l')
		*i = (long)*i;
	if (*i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->length = ft_putint_ll_size(*i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && conv->precision != 0))
		conv->precision = conv->length;
}

int		ft_putint_ll_size(long long i, t_conv *conv)
{
	long long	temp;
	int			size;

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

void	ft_putint_ll_n_fd(long long i, int *nprint)
{
	long long	temp;
	long long	pow;

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

int		ft_putuint_ll_size(unsigned long long i, t_conv *conv)
{
	unsigned long long	temp;
	int					size;

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

void	ft_putuint_ll_n_fd(unsigned long long i, int *nprint)
{
	unsigned long long	temp;
	unsigned long long	pow;

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
