/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_ll_diu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:37:31 by averheij       #+#    #+#                */
/*   Updated: 2019/12/17 12:36:39 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putint_ll_size(long long i)
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

void	ft_pre_uint(t_conv *conv, va_list a_list, int *n)
{
	if (conv->size == 'L')
		ft_print_ll_uint(conv, a_list, n);
	else if (conv->size == 'l')
		ft_print_l_uint(conv, a_list, n);
	else
		ft_print_uint(conv, a_list, n);
}

int		ft_putuint_ll_size(unsigned long long i)
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
