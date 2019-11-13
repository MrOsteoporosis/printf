/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:55:12 by averheij       #+#    #+#                */
/*   Updated: 2019/11/13 15:58:45 by averheij      ########   odam.nl         */
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
	if (i == 0)
		ft_putchar_n_fd('0', 1, nprint);
	temp = i;
	while (i)
	{
		ft_putchar_n_fd(hex[i / pow], 1, nprint);
		i = i % pow;
		pow = pow / 16;
	}
}

void	ft_puthex_upper_n_fd(unsigned int i, int *nprint)
{
	//Lmao
}
