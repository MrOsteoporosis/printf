/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:57:42 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 11:16:21 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

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
