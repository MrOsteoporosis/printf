/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_l_diu.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:37:31 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 10:36:09 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putint_l_size(long i)
{
	long	temp;
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

void	ft_putint_l_n_fd(long i, int *nprint)
{
	long	temp;
	long	pow;

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

int		ft_putuint_l_size(unsigned long i)
{
	unsigned long	temp;
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

void	ft_putuint_l_n_fd(unsigned long i, int *nprint)
{
	unsigned long	temp;
	unsigned long	pow;

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
