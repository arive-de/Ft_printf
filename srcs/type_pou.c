/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:37:05 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 11:49:59 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sign_p(t_ptf *env)
{
	char *str;

	env->arg_u = va_arg(env->ap, uintmax_t);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len + 2);
	if (!env->precision && !env->width)
		str = ft_strcat(str, "0x");
	str = apply_flags6(env, str);
	str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 16));
	if (env->new_len > env->size && env->minus && env->precision <= env->width)
		fill_space_end6(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && !env->width)
		str = ft_strdup("0x");
	str = ft_strcat(env->tmp, str);
}

void	sign_o(t_ptf *env)
{
	char *str;

	env->arg_u = convert_u(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	str = apply_flags3(env, str);
	str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 8));
	if (env->new_len > env->size && env->minus && env->precision <= env->width)
		fill_space_end3(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (env->arg_u == 0 && env->point[0] == '.' &&
			!env->precision && !env->width && env->sharp == 0)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_spe_o(t_ptf *env)
{
	char *str;

	env->arg_u = convert_spe_o(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	str = apply_flags3(env, str);
	str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 8));
	if (env->new_len > env->size && env->minus && env->precision <= env->width)
		fill_space_end3(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (env->arg_u == 0 && env->point[0] == '.' &&
			!env->precision && !env->width && env->sharp == 0)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_u(t_ptf *env)
{
	char *str;

	env->arg_u = convert_u(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	if (env->arg_u != 0 || (env->arg_u == 0 && ((env->precision ||
						env->width) || (!env->precision || !env->width))))
	{
		str = apply_flags2(env, str);
		str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 10));
		if (env->new_len > env->size && env->minus == 1)
			fill_space_end2(env, str);
	}
	if (env->arg_u == 0 && env->point[0] == '.' && !env->precision)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_spe_u(t_ptf *env)
{
	char *str;

	env->arg_u = convert_spe_u(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	str = apply_flags2(env, str);
	str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 10));
	if (env->new_len > env->size && env->minus == 1)
		fill_space_end2(env, str);
	ft_strcat(env->tmp, str);
}
