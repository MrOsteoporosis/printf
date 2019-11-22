/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_cs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 13:46:17 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 11:09:46 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_putnstr_n_fd(char *str, int fd, int n, int *nprint)
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

void	ft_putchar_n_fd(char c, int fd, int *nprint)
{
	ft_putchar_fd(c, fd);
	*nprint = *nprint + 1;
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
