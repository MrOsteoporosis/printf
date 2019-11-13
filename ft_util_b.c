/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:54:34 by averheij       #+#    #+#                */
/*   Updated: 2019/11/13 14:56:42 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	if (i == 0)
		ft_putchar_n_fd('0', 1, nprint);
	while (i)
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
	if (i == 0)
		ft_putchar_n_fd('0', 1, nprint);
	while (i)
	{
		ft_putchar_n_fd('0' + i / pow, 1, nprint);
		i = i % pow;
		pow = pow / 10;
	}
}
