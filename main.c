/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:58:58 by averheij       #+#    #+#                */
/*   Updated: 2019/11/13 12:17:51 by averheij      ########   odam.nl         */
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

	//String tests, printf unit test gives garbled trash results on some tests
	ft_printf("ME: %05i %%05i\n", 43);
	printf("C : %05i\n", 43);
	ft_printf("ME: %07i %%07i\n", -54);
	printf("C : %07i\n", -54);
	ft_printf("ME: %08.5i %%08.5i\n", 34);
	printf("C : %08.5i\n", 34);
	ft_printf("ME: %010.5i %%010.5i\n", -216);
	printf("C : %010.5i\n", -216);
	ft_printf("ME: %08.5i %%08.5i\n", 0);
	printf("C : %08.5i\n", 0);
	// ft_printf("^.^/%-2.24s^.^/\n", "The Game.");
	// printf("^.^/%-2.24s^.^/\n", "The Game.");
	// ft_printf("42%-30.32s42\n", "");
	// printf("42%-30.32s42\n", "");
	// ft_printf("42%-.2s42\n", "(null)");
	// printf("42%-.2s42\n", "(null)");
	// printf("%d\n", ft_printf(">------------<%.2s>------------<\n", "(null)"));
	// printf("%d\n", printf(">------------<%.2s>------------<\n", "(null)"));
	// ft_printf("heres string |%10s|, and one more |%-*c|\n", str, i1, c);
	// printf("heres string |%10s|, and one more |%-*c| also pointer |%p|\n", str, i1, c, n1);
}
