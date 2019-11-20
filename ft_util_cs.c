/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_put.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 13:46:17 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 11:25:57 by averheij      ########   odam.nl         */
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
