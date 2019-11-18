/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:58:58 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 11:48:50 by averheij      ########   odam.nl         */
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

	ft_printf("ME: |%li| 		%%li\n", 22337203685477);
	printf("C : |%li|\n", 22337203685477);
	// ft_printf("ME: |%5d|		%%5d\n", 50);
	// printf("C : |%5d|\n", 50);
}
