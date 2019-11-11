/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_csp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 09:57:15 by averheij       #+#    #+#                */
/*   Updated: 2019/11/11 14:16:35 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_print_char(t_conv *conv, va_list a_list, int *nprint)
{
	int		c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
	{
		*nprint = *nprint + 1;
		ft_putchar_fd(c, 1);
	}
	ft_pad_width(conv->width, conv->precision, ' ', nprint);
	if (!conv->leftj)
	{
		*nprint = *nprint + 1;
		ft_putchar_fd(c, 1);
	}
}

void	ft_print_string(t_conv *conv, va_list a_list, int *nprint)
{
	char	*str;

	str = va_arg(a_list, char *);
	if (!str)
		return ;
	if (conv->precision > ft_strlen(str) || conv->precision == -2)
		conv->precision = ft_strlen(str);
	if (conv->leftj)
		ft_putnstr_fd(str, 1, conv->precision, nprint);
	ft_pad_width(conv->width, conv->precision, ' ', nprint);
	if (!conv->leftj)
		ft_putnstr_fd(str, 1, conv->precision, nprint);
}

void	ft_print_pointer(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("POINTER", 1);
}

void	ft_print_percent(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("PERCENT", 1);
}
