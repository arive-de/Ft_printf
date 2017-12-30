/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:48:16 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 13:47:21 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_space2(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->new_len > env->precision || env->new_len > env->size)
		stop = env->new_len - env->size;
	if (env->plus == 1 || env->space == 1)
		i++;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_space_end2(t_ptf *env, char *str)
{
	int i;
	int stop;

	if (env->precision < env->size)
		i = env->size;
	else
		i = env->precision;
	stop = env->new_len;
	if (env->plus == 1 || env->space == 1)
		i++;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_zero2(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->new_len - int_len(env->arg_u);
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->minus == 1)
		i++;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}

char	*apply_flags2(t_ptf *env, char *str)
{
	if (env->width && !env->precision)
	{
		if (env->zero == 0 && env->minus == 0)
			fill_space2(env, str);
		else if (env->zero == 1 && env->minus == 0)
			fill_zero2(env, str);
	}
	if (env->precision)
		fill_precision2(env, str);
	return (str);
}
