/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 13:46:17 by averheij       #+#    #+#                */
/*   Updated: 2019/11/13 13:32:01 by averheij      ########   odam.nl         */
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

void	ft_putnbr_n_fd(int i, int *nprint)
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

void	ft_pad_width(int width, int precision, int pad, int *nprint)
{
	while (width > precision)
	{
		*nprint = *nprint + 1;
		ft_putchar_fd(pad, 1);
		width--;
	}
}

int		ft_spotter(const char **format, t_conv *conv)
{
	if (!*(*format + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}
