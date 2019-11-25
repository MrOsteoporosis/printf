/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_gen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:57:42 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 11:35:40 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_do_conv(const char **format, va_list a_list, t_conv *conv, int *n)
{
	ft_init_conv_vars(conv);
	ft_set_conv_vars(format, conv);
	if (conv->type)
	{
		if (conv->width == -1)
			conv->width = va_arg(a_list, int);
		if (conv->precision == -1)
			conv->precision = va_arg(a_list, int);
		ft_call_converter(conv, a_list, n);
	}
}

void	ft_init_conv_vars(t_conv *conv)
{
	conv->hash = 0;
	conv->leftj = 0;
	conv->padzero = 0;
	conv->precision = -2;
	conv->width = 0;
	conv->sign = 0;
	conv->hassign = 0;
	conv->size = 0;
	conv->length = 0;
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

void	ft_identify_size_flag(const char **format, t_conv *conv)
{
	if (**format == 'l' && *(*format + 1) == 'l')
		conv->size = 'L';
	else if (**format == 'h' && *(*format + 1) == 'h')
		conv->size = 'H';
	else if (**format == 'l' || **format == 'h')
		conv->size = **format;
}

void	ft_find_flag_end(const char **format, t_conv *conv)
{
	if (**format == 'l' && *(*format + 1) == 'l')
		*format = *format + 1;
	else if (**format == 'h' && *(*format + 1) == 'h')
		*format = *format + 1;
	else if (**format == '.' &&
			(*(*format + 1) == '*' || ft_isdigit(*(*format + 1))))
		*format = *format + 1;
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*format)) && ft_isdigit(*(*format + 1)))
			*format = *format + 1;
}
