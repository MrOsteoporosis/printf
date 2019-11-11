/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_diuxx.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:19:01 by averheij       #+#    #+#                */
/*   Updated: 2019/11/11 13:29:10 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_print_int(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("INT", 1);
}

void	ft_print_uint(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("UNSIGNED INT", 1);
}

void	ft_print_hex_lower(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("HEX LOWER", 1);
}

void	ft_print_hex_upper(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("HEX UPPER", 1);
}
