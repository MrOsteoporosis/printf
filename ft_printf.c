/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:54:08 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 11:13:45 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_identify_flag(const char **format, t_conv *conv)
{
	if (**format == '-')
		conv->leftj = 1;
	else if (**format == '0')
		conv->padzero = 1;
	else if (**format == '+' || **format == ' ')
	{
		conv->sign = **format;
		conv->hassign = 1;
	}
	else if (**format == '#')
		conv->hash = 1;
	else if (**format == '*')
		conv->width = -1;
	else if (ft_isdigit(**format))
		conv->width = ft_atoi(*format);
	else if (**format == '.' && *(*format + 1) == '*')
		conv->precision = -1;
	else if (**format == '.' && ft_isdigit(*(*format + 1)))
		conv->precision = ft_atoi(*format + 1);
	else if (**format == '.')
		conv->precision = 0;
	ft_identify_size_flag(format, conv);
	ft_find_flag_end(format, conv);
}

void	ft_set_conv_vars(const char **format, t_conv *conv)
{
	char	*types;

	if (ft_spotter(format, conv))
		return ;
	*format = *format + 1;
	while (**format)
	{
		types = "cspdiuxXnfeg%";
		while (*types)
		{
			if (**format == *types)
			{
				conv->type = *types;
				return ;
			}
			types++;
		}
		ft_identify_flag(format, conv);
		if (ft_spotter(format, conv))
			return ;
		*format = *format + 1;
	}
}

void	ft_call_converter(t_conv *conv, va_list a_list, int *nprint)
{
	char	*types;
	t_cfunc	funcs[8];
	int		i;

	types = "cspdiuxX";
	funcs[0] = &ft_print_char;
	funcs[1] = &ft_print_string;
	funcs[2] = &ft_print_pointer;
	funcs[3] = &ft_pre_int;
	funcs[4] = &ft_pre_int;
	funcs[5] = &ft_pre_uint;
	funcs[6] = &ft_pre_hex_lower;
	funcs[7] = &ft_pre_hex_upper;
	if (conv->type == 'n')
		ft_print_count(a_list, nprint);
	if (conv->type == '%')
		ft_print_percent(conv, nprint);
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			funcs[i](conv, a_list, nprint);
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list a_list;
	t_conv	conv;
	int		nprint;

	va_start(a_list, format);
	nprint = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			nprint++;
		}
		else
			ft_do_conv(&format, a_list, &conv, &nprint);
		format++;
	}
	va_end(a_list);
	return (nprint);
}
