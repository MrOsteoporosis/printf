/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_cspn.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 09:57:15 by averheij       #+#    #+#                */
/*   Updated: 2019/12/12 11:07:59 by averheij      ########   odam.nl         */
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
		ft_putchar_n_fd(c, 1, n);
	ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
		ft_putchar_n_fd(c, 1, n);
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
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', n);
	else
		ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
		ft_putnstr_n_fd(str, 1, conv->precision, n);
}

void	ft_print_pointer(t_conv *conv, va_list a_list, int *n)
{
	unsigned long ptr;

	ptr = (unsigned long)va_arg(a_list, void*);
	conv->size = (ft_puthex_ll_size(ptr) + 2);
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
	if (conv->leftj)
	{
		ft_putnstr_n_fd("0x", 1, 2, n);
		ft_pad_width(conv->precision,
			conv->size - ((conv->precision > conv->size) ? 2 : 0), '0', n);
		if (conv->precision)
			ft_puthex_ll_lower_n_fd(ptr, n);
	}
	(!conv->leftj && conv->padzero) ? ft_pad_width(conv->width, conv->precision,
		'0', n) : ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!(conv->leftj))
	{
		ft_putnstr_n_fd("0x", 1, 2, n);
		ft_pad_width(conv->precision,
			conv->size - ((conv->precision > conv->size) ? 2 : 0), '0', n);
		if (conv->precision)
			ft_puthex_ll_lower_n_fd(ptr, n);
	}
}

void	ft_print_percent(t_conv *conv, int *n)
{
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

void	ft_print_count(va_list a_list, int *nprint)
{
	int *ptr;

	ptr = va_arg(a_list, int *);
	*ptr = *nprint;
}
