/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:58:58 by averheij       #+#    #+#                */
/*   Updated: 2019/11/14 13:33:18 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

int		main(void)
{
	int 	i1 = 3456;
	int		i2 = 1;
	int		*n1 = &i1;
	int		*n2 = &i2;
	double	d1 = 12.34567;
	char	c = 'h';
	char	str[] = "hello";

	ft_printf("%%+04d 42 == %0+04d", 42);
	// ft_printf("ME: |%#7x| 		%%#7x\n", 32);
	// printf("C : |%#7x|\n", 32);
	// ft_printf("ME: |%5d|		%%5d\n", 50);
	// printf("C : |%5d|\n", 50);
}
