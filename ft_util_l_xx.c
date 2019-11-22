/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_l_xx.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:04:06 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 10:46:43 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_puthex_l_size(unsigned long i)
{
	unsigned long	temp;
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

void	ft_puthex_l_lower_n_fd(unsigned long i, int *nprint)
{
	unsigned long	temp;
	unsigned long	pow;
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

void	ft_puthex_l_upper_n_fd(unsigned long i, int *nprint)
{
	unsigned long	temp;
	unsigned long	pow;
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
