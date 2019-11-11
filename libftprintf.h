/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:47:49 by averheij       #+#    #+#                */
/*   Updated: 2019/11/11 13:49:40 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

typedef struct	s_conv
{
	char	type;
	int		width;
	int		precision;
	int		leftj;
	int		padzero;
	int		hash;
	char	sign;
}				t_conv;
typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *format, ...);
void			ft_set_conv_vars(const char **format, t_conv *conv);
void			ft_identify_flag(const char **format, t_conv *conv);
void			ft_call_converter(t_conv *conv, va_list a_list, int *nprint);
void			ft_init_conv_vars(t_conv *conv);
void			ft_print_char(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_string(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_pointer(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_int(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_uint(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_hex_lower(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_hex_upper(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_count(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_float(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_science(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_compact_float(t_conv *conv, va_list a_list,
										int *nprint);
void			ft_print_percent(t_conv *conv, va_list a_list, int *nprint);
void			ft_putnstr_fd(char *str, int fd, int n, int *nprint);
void			ft_pad_width(int width, int precision, int pad, int *nprint);
#endif
