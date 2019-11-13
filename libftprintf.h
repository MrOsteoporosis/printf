/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:47:49 by averheij       #+#    #+#                */
/*   Updated: 2019/11/13 15:58:49 by averheij      ########   odam.nl         */
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
	int		hassign;
	int		length;
}				t_conv;
typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *format, ...);
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(const char **format, t_conv *conv);
void			ft_identify_flag(const char **format, t_conv *conv);
void			ft_call_converter(t_conv *conv, va_list a_list, int *nprint);
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
void			ft_putchar_n_fd(char c, int fd, int *nprint);
void			ft_putnstr_n_fd(char *str, int fd, int n, int *nprint);
void			ft_putint_n_fd(int i, int *nprint);
int				ft_putint_size(int i, t_conv *conv);
void			ft_putuint_n_fd(unsigned int i, int *nprint);
int				ft_putuint_size(unsigned int i, t_conv *conv);
int				ft_puthex_size(unsigned int i, t_conv *conv);
void			ft_puthex_lower_n_fd(unsigned int i, int *nprint);
void			ft_puthex_upper_n_fd(unsigned int i, int *nprint);
void			ft_pad_width(int width, int precision, int pad, int *nprint);
int				ft_spotter(const char **format, t_conv *conv);
#endif
