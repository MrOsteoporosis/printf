/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:54:08 by averheij       #+#    #+#                */
/*   Updated: 2019/11/14 13:00:00 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

/*
**	function finds and assigns relevent flag value in conv struct
**	returns pointer to last char of flag section
**	dont forget format gets incr after return
*/

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
	if (**format == '.' &&
		(*(*format + 1) == '*' || ft_isdigit(*(*format + 1))))
		*format = *format + 1;
	ft_find_flag_end(format, conv);
}

/*
**	function matches type and calls identify flag on any flag characters found
*/

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

/*
** finds correct conversion function to call
*/

void	ft_call_converter(t_conv *conv, va_list a_list, int *nprint)
{
	char	*types;
	t_cfunc	funcs[13];
	int		i;

	types = "cspdiuxXnfeg%";
	funcs[0] = &ft_print_char;
	funcs[1] = &ft_print_string;
	funcs[2] = &ft_print_pointer;
	funcs[3] = &ft_print_int;
	funcs[4] = &ft_print_int;
	funcs[5] = &ft_print_uint;
	funcs[6] = &ft_print_hex_lower;
	funcs[7] = &ft_print_hex_upper;
	funcs[8] = &ft_print_count;
	funcs[9] = &ft_print_float;
	funcs[10] = &ft_print_science;
	funcs[11] = &ft_print_compact_float;
	funcs[12] = &ft_print_percent;
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
		{
			ft_init_conv_vars(&conv);
			ft_set_conv_vars(&format, &conv);
			if (conv.type)
			{
				if (conv.width == -1)
					conv.width = va_arg(a_list, int);
				if (conv.precision == -1)
					conv.precision = va_arg(a_list, int);
				ft_call_converter(&conv, a_list, &nprint);
				// printf("\n	type: %c\n", conv.type);
				// printf("	width: %d\n", conv.width);
				// printf("	precision: %d\n", conv.precision);
				// printf("	hash: %d\n", conv.hash);
				// printf("	leftj: %d\n", conv.leftj);
				// printf("	padzero: %d\n", conv.padzero);
				// printf("	sign: %c\n", conv.sign);
				// printf("	hassign: %d\n", conv.hassign);
				// printf("	length: %d\n", conv.length);
			}
		}
		format++;
	}
	va_end(a_list);
	return (nprint);
}
