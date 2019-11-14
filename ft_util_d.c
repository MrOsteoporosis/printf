/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_util_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:57:42 by averheij       #+#    #+#                */
/*   Updated: 2019/11/14 12:58:20 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_find_flag_end(const char **format, t_conv *conv)
{
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*format)) && ft_isdigit(*(*format + 1)))
			*format = *format + 1;
}
