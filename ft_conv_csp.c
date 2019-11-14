/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_csp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 09:57:15 by averheij       #+#    #+#                */
/*   Updated: 2019/11/14 12:20:32 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_print_char(t_conv *conv, va_list a_list, int *n)
{
	int		c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
	{
		*n = *n + 1;
		ft_putchar_fd(c, 1);
	}
	ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
	{
		*n = *n + 1;
		ft_putchar_fd(c, 1);
	}
}

void	ft_print_string(t_conv *conv, va_list a_list, int *n)
{
	char	*str;

	str = va_arg(a_list, char *);
	if (!str)
		str = "(null)";
	conv->length = ft_strlen(str);
	if (conv->precision > conv->length || conv->precision == -2)
		conv->precision = conv->length;
	if (conv->leftj)
		ft_putnstr_n_fd(str, 1, conv->precision, n);
	ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
		ft_putnstr_n_fd(str, 1, conv->precision, n);
}

void	ft_print_pointer(t_conv *conv, va_list a_list, int *n)
{
	ft_putstr_fd("POINTER", 1);
}

void	ft_print_percent(t_conv *conv, va_list a_list, int *n)
{
	int		c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
	{
		*n = *n + 1;
		ft_putchar_fd('%', 1);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', n);
	else
		ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
	{
		*n = *n + 1;
		ft_putchar_fd('%', 1);
	}
}
