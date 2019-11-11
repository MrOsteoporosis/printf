/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 13:46:17 by averheij       #+#    #+#                */
/*   Updated: 2019/11/11 13:57:57 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnstr_fd(char *str, int fd, int n, int *nprint)
{
	int		i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar_fd(str[i], fd);
		*nprint = *nprint + 1;
		i++;
	}
}

void	ft_pad_width(int width, int precision, int pad, int *nprint)
{
	while (width > precision)
	{
		*nprint = *nprint + 1;
		ft_putchar_fd(pad, 1);
		width--;
	}
}
