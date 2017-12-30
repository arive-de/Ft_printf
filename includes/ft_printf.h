/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:18:05 by arive-de          #+#    #+#             */
/*   Updated: 2017/04/25 17:51:56 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# define NB_TYPE 15
# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "+-0#"
# define NB_FLAGS 4

typedef struct	s_type
{
	char		*sign;
	void		(*f_sign)(void*);
}				t_type;

typedef struct	s_ptf
{
	int			null;
	int			empty;
	int			sharp;
	int			flag;
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			size;
	int			new_len;
	wchar_t		*s_char;
	wint_t		w_char;
	intmax_t	arg_nb;
	uintmax_t	arg_u;
	uintmax_t	arg_o;
	char		fmt;
	int			len;
	int			width;
	int			precision;
	char		*conv;
	char		*point;
	char		*buf;
	char		*tmp;
	va_list		ap;
	t_type		*tab;
}				t_ptf;
void			sign_s();
void			sign_spe_s();
int				sign_spe_s1(t_ptf *env, char *str, int flag);
void			sign_spe_s2(t_ptf *env, char *tmp, int i);
void			sign_p();
void			sign_d();
void			sign_spe_d();
void			sign_i();
void			sign_o();
void			sign_spe_o();
void			sign_u();
void			sign_spe_u();
void			sign_x();
void			sign_spe_x();
void			sign_c();
void			sign_spe_c();
void			sign_percent();
int				ending(t_ptf *env, int len);
int				moove_lc(t_ptf *env);
int				moove_ls(t_ptf *env);
char			*replace_zeros(t_ptf *env, char *str);
char			*spe_count_bits(t_ptf *env, wchar_t arg, char *str);
char			*count_bits(t_ptf *env, char *str);
char			*apply_flags(t_ptf *env, char *str);
char			*fill_space_end(t_ptf *env, char *str);
char			*fill_zero(t_ptf *env, char *str);
char			*fill_precision(t_ptf *env, char *str);
char			*fill_precision_d(t_ptf *env, char *str, int i, int stop);
char			*fill_space(t_ptf *env, char *str);
char			*apply_flags2(t_ptf *env, char *str);
char			*fill_space_end2(t_ptf *env, char *str);
char			*fill_precision2(t_ptf *env, char *str);
char			*fill_space2(t_ptf *env, char *str);
char			*fill_zero2(t_ptf *env, char *str);
char			*apply_flags3(t_ptf *env, char *str);
char			*fill_space_end3(t_ptf *env, char *str);
char			*fill_precision3(t_ptf *env, char *str);
char			*fill_precision_o(t_ptf *env, char *str, int i, int stop);
char			*fill_precision_p(t_ptf *env, char *str, int i, int stop);
char			*fill_precision_u(t_ptf *env, char *str, int i, int stop);
char			*fill_precision_x(t_ptf *env, char *str, int i, int stop);
char			*fill_precision_51(t_ptf *env, char *str, int stop, char *tmp);
char			*fill_space3(t_ptf *env, char *str);
char			*fill_zero3(t_ptf *env, char *str);
char			*apply_flags4(t_ptf *env, char *str);
char			*fill_space_end4(t_ptf *env, char *str);
char			*fill_precision4(t_ptf *env, char *str);
char			*fill_space4(t_ptf *env, char *str);
char			*fill_zero4(t_ptf *env, char *str);
char			*apply_flags6(t_ptf *env, char *str);
char			*fill_space_end6(t_ptf *env, char *str);
char			*fill_precision6(t_ptf *env, char *str);
char			*fill_space6(t_ptf *env, char *str);
char			*fill_zero6(t_ptf *env, char *str);
char			*apply_flags5(t_ptf *env, char *str);
char			*fill_precision5(t_ptf *env, char *str);
char			*fill_space_end5(t_ptf *env, char *str);
char			*fill_space_s(t_ptf *env, char *str);
char			*fill_space7(t_ptf *env, char *str);
char			*fill_precision7(t_ptf *env, char *str);
char			*fill_space_end7(t_ptf *env, char *str);
intmax_t		convert_d(t_ptf *env);
uintmax_t		convert_u(t_ptf *env);
uintmax_t		convert_spe_u(t_ptf *env);
uintmax_t		convert_spe_o(t_ptf *env);
uintmax_t		convert_spe_d(t_ptf *env);
int				width(t_ptf *env, intmax_t nb);
int				width_s(t_ptf *env, char *str);
char			get_format(char *str, int i);
int				checks(t_ptf *env, char *str, int i);
int				check_flags(t_ptf *env, char c);
int				check_conversion(t_ptf *env, char *str, int i);
int				check_precision(t_ptf *env, char *str, int i);
int				check_width(t_ptf *env, char *str, int i);
int				check_point(char *str, int i);

#endif
