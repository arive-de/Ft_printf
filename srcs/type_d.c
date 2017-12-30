/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:38:48 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 11:52:29 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sign_d2(t_ptf *env, char *str)
{
	str = apply_flags(env, str);
	if (env->arg_nb < 0)
		str = ft_strcat(str, ft_u_itoa_base(env->arg_nb * -1, 10));
	else
		str = ft_strcat(str, ft_itoa_base(env->arg_nb, 10));
	if (env->new_len > env->size && env->minus && env->width > env->precision)
		fill_space_end(env, str);
	if (!env->arg_nb && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (!env->arg_nb && env->point[0] == '.' && !env->precision && !env->width)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_d(t_ptf *env)
{
	char *str;

	env->arg_nb = convert_d(env);
	env->new_len = width(env, env->arg_nb);
	str = ft_strnew(env->new_len);
	if (env->arg_nb < 0)
	{
		if (env->width > env->size && !env->zero &&
				!env->minus && !env->precision)
			fill_space(env, str);
		if ((env->precision && !env->width) || (env->arg_nb < 0 &&
					!env->precision) ||
				(env->size > env->width && env->arg_nb < 0) || env->zero)
			ft_strcat(str, "-");
		if (env->zero == 1 && env->minus == 0)
			fill_zero(env, str);
		if (env->precision > env->size || env->precision > env->width
				|| (env->width > env->size && env->size > env->precision
					&& env->precision))
			fill_precision(env, str);
	}
	sign_d2(env, str);
}

void	sign_spe_d2(t_ptf *env, char *str)
{
	if (env->width > env->size && !env->zero && !env->minus)
		fill_space(env, str);
	ft_strcat(str, "-");
	if (env->width > env->size && env->zero == 1 && !env->minus)
		fill_zero(env, str);
	if (!env->width && env->precision)
		fill_precision(env, str);
}

void	sign_spe_d(t_ptf *env)
{
	char *str;

	env->arg_nb = convert_spe_d(env);
	env->new_len = width(env, env->arg_nb);
	str = ft_strnew(env->new_len);
	if (env->arg_nb < 0)
		sign_spe_d2(env, str);
	str = apply_flags(env, str);
	if (env->arg_nb < 0)
		str = ft_strcat(str, ft_u_itoa_base(env->arg_nb * -1, 10));
	else
		str = ft_strcat(str, ft_itoa_base(env->arg_nb, 10));
	if (env->new_len > env->size && env->minus == 1)
		fill_space_end(env, str);
	if (!env->arg_nb && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (!env->arg_nb && env->point[0] == '.' && !env->precision && !env->width)
		str = "";
	ft_strcat(env->tmp, str);
}
