/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_nfeg_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 10:19:21 by averheij       #+#    #+#                */
/*   Updated: 2019/11/11 14:13:19 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_print_float(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("FLOAT", 1);
}

void	ft_print_science(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("SCI NOT", 1);
}

void	ft_print_compact_float(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("FLOAT/SCI NOT", 1);
}

void	ft_print_count(t_conv *conv, va_list a_list, int *nprint)
{
	ft_putstr_fd("COUNT", 1);
}
