/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 09:47:49 by averheij       #+#    #+#                */
/*   Updated: 2019/11/18 13:28:02 by averheij      ########   odam.nl         */
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
	char	size;
	int		length;
}				t_conv;
typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *format, ...);
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(const char **format, t_conv *conv);
void			ft_identify_flag(const char **format, t_conv *conv);
void			ft_find_flag_end(const char **format, t_conv *conv);
void			ft_call_converter(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_char(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_string(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_pointer(t_conv *conv, va_list a_list, int *nprint);
void			ft_pre_int(t_conv *conv, va_list a_list, int *n);
void			ft_print_int(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_ll_int(t_conv *conv, va_list a_list, int *n);
void			ft_pre_uint(t_conv *conv, va_list a_list, int *n);
void			ft_print_uint(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_ll_uint(t_conv *conv, va_list a_list, int *nprint);
void			ft_pre_hex_lower(t_conv *conv, va_list a_list, int *n);
void			ft_print_hex_lower(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_ll_hex_lower(t_conv *conv,
				va_list a_list, int *nprint);
void			ft_pre_hex_upper(t_conv *conv, va_list a_list, int *n);
void			ft_print_hex_upper(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_ll_hex_upper(t_conv *conv,
				va_list a_list, int *nprint);
void			ft_print_count(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_float(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_science(t_conv *conv, va_list a_list, int *nprint);
void			ft_print_compact_float(t_conv *conv, va_list a_list,
										int *nprint);
void			ft_print_percent(t_conv *conv, va_list a_list, int *nprint);
void			ft_putchar_n_fd(char c, int fd, int *nprint);
void			ft_putnstr_n_fd(char *str, int fd, int n, int *nprint);
void			ft_prep_int(t_conv *conv, int i);
int				ft_putint_size(int i, t_conv *conv);
void			ft_putint_n_fd(int i, int *nprint);
int				ft_putuint_size(unsigned int i, t_conv *conv);
void			ft_putuint_n_fd(unsigned int i, int *nprint);
void			ft_prep_ll_int(t_conv *conv, long long i);
int				ft_putint_ll_size(long long i, t_conv *conv);
void			ft_putint_ll_n_fd(long long i, int *nprint);
int				ft_putuint_ll_size(unsigned long long i, t_conv *conv);
void			ft_putuint_ll_n_fd(unsigned long long i, int *nprint);
void			ft_prep_hex(t_conv *conv, unsigned int i);
int				ft_puthex_size(unsigned int i, t_conv *conv);
void			ft_puthex_lower_n_fd(unsigned int i, int *nprint);
void			ft_puthex_upper_n_fd(unsigned int i, int *nprint);
void			ft_prep_ll_hex(t_conv *conv, unsigned long long i);
int				ft_puthex_ll_size(unsigned long long i, t_conv *conv);
void			ft_puthex_ll_lower_n_fd(unsigned long long i, int *nprint);
void			ft_puthex_ll_upper_n_fd(unsigned long long i, int *nprint);
void			ft_pad_width(int width, int precision, int pad, int *nprint);
int				ft_spotter(const char **format, t_conv *conv);
#endif
