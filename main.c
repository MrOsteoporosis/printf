/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:58:58 by averheij       #+#    #+#                */
/*   Updated: 2019/11/21 14:42:21 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char *tictac = "|this %i number|\n";
	printf("%s", tictac);
	ft_printf(tictac, 0);
	printf(tictac, 0);
	char *str113 = "|%.0i|\n";
	printf("%s", str113);
	ft_printf(str113, 0);
	printf(str113, 0);
	char *str11 = "|%-101.+.60d|\n";
	printf("%s", str11);
	ft_printf(str11, 2000);
	printf(str11, 2000);
	char *str123 = "|%.-+100d|\n";
	printf("%s", str123);
	ft_printf(str123, 2000);
	printf(str123, 2000);
	char *str12 = "|%+.100X|\n";
	printf("%s", str12);
	ft_printf(str12, 2000);
	printf(str12, 2000);
	char *str = "|%.-100X|\n";
	printf("%s", str);
	ft_printf(str, 2000);
	printf(str, 2000);
	char *str1 = "|%7x|\n";
	printf("%s", str);
	ft_printf(str1, 33000);
	printf(str1, 33000);
	char *str2 = "|%.0s|\n";
	printf("%s", str2);
	ft_printf(str2, "Griffin has a tiny dick");
	printf(str2, "Griffin has a tiny dick");
	char *str23 = "|%.03s|\n";
	printf("%s", str23);
	ft_printf(str23, "Griffin has a tiny dick");
	printf(str23, "Griffin has a tiny dick");
}
