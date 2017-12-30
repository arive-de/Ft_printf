/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 11:18:24 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 13:36:37 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_space3(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->precision < env->size)
		stop = env->new_len - env->size;
	else if (env->precision > env->size)
		stop = env->new_len - env->precision;
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->sharp == 1 && env->arg_u != 0)
		i++;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_space_end3(t_ptf *env, char *str)
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
	if (env->sharp == 1)
		stop--;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_zero3(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->new_len - int_len(env->arg_u);
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->minus == 1 || (env->sharp == 1 && env->arg_u != 0))
		i++;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}

char	*apply_flags3(t_ptf *env, char *str)
{
	if (env->sharp == 1 && !env->width && !env->precision && env->arg_u != 0)
		ft_strcat(str, "0");
	if (env->width && !env->precision)
	{
		if (env->zero == 0 && env->minus == 0)
			fill_space3(env, str);
		else if (env->zero == 1 && env->minus == 0)
			fill_zero3(env, str);
		if (env->sharp == 1 && env->arg_u != 0)
			ft_strcat(str, "0");
	}
	if (env->precision)
		fill_precision3(env, str);
	return (str);
}
