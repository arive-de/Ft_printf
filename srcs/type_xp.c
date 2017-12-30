/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:37:22 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 11:48:46 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sign_x(t_ptf *env)
{
	char *str;

	env->arg_u = convert_u(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	str = apply_flags4(env, str);
	str = ft_strcat(str, ft_u_itoa_base(env->arg_u, 16));
	if (env->new_len > env->size && env->minus && env->precision <= env->width)
		fill_space_end4(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && !env->width)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_spe_x(t_ptf *env)
{
	char *str;

	env->arg_u = convert_u(env);
	env->new_len = width(env, env->arg_u);
	str = ft_strnew(env->new_len);
	str = apply_flags4(env, str);
	str = ft_strcat(str, ft_up_itoa_base(env->arg_u, 16));
	if (env->new_len > env->size && env->minus && env->precision <= env->width)
		fill_space_end4(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && env->width)
		replace_zeros(env, str);
	if (!env->arg_u && env->point[0] == '.' && !env->precision && !env->width)
		str = "";
	ft_strcat(env->tmp, str);
}

void	sign_percent(t_ptf *env)
{
	int		i;
	int		stop;
	char	*str;

	i = 0;
	stop = env->width - 1;
	str = ft_strnew(env->width);
	if (env->minus == 1)
	{
		str = ft_strdup("%");
		str = apply_flags5(env, str);
	}
	else
	{
		while (i < stop)
		{
			(env->zero == 1 ? ft_strcat(str, "0") : ft_strcat(str, " "));
			i++;
		}
		ft_strcat(str, "%");
	}
	ft_strcat(env->tmp, str);
}
