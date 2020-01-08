/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:09:52 by averheij       #+#    #+#                */
/*   Updated: 2020/01/08 14:58:45 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
#endif
