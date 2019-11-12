/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:54:34 by averheij       #+#    #+#                */
/*   Updated: 2019/11/12 15:39:38 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putnbr_size(int i, t_conv *conv)
{
	int		temp;
	int		size;

	temp = i;
	size = 0;
	if (i < 0 || conv->sign)
		size++;
	if (i == 0)
		size++;
	while (temp)
	{
		temp = temp / 10;
		size++;
	}
	return (size);
}
