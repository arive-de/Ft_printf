/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 11:18:24 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 16:09:44 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_space4(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->precision < env->size)
		stop = env->new_len - env->size;
	else if (env->precision > env->size)
		stop = env->new_len - env->precision;
	if (env->sharp == 1 && env->arg_u != 0)
		i = i + 2;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_space_end4(t_ptf *env, char *str)
{
	int i;
	int stop;

	if (env->precision < env->size)
		i = env->size;
	else
		i = env->precision;
	stop = env->new_len;
	if (env->sharp && env->arg_u != 0 && env->minus)
		stop = stop - 2;
	else if (env->sharp && env->arg_u != 0)
		stop = stop + 2;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_zero4(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->new_len - int_len(env->arg_u);
	if (env->sharp == 1 && env->arg_u != 0)
		i = i + 2;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}

char	*apply_flags4(t_ptf *env, char *str)
{
	if (env->sharp && !env->width && !env->precision && env->arg_u != 0
			&& env->fmt == 'x')
		ft_strcat(str, "0x");
	if (env->sharp && !env->width && !env->precision && env->arg_u != 0
			&& env->fmt == 'X')
		ft_strcat(str, "0X");
	if (env->width && !env->precision)
	{
		if (env->sharp && env->arg_u != 0 && env->fmt == 'x' && env->zero)
			ft_strcat(str, "0x");
		if (env->sharp && env->arg_u != 0 && env->fmt == 'X' && env->zero)
			ft_strcat(str, "0X");
		if (env->zero == 0 && env->minus == 0)
			fill_space4(env, str);
		else if (env->zero == 1 && env->minus == 0)
			fill_zero4(env, str);
		if (env->sharp && env->arg_u != 0 && env->fmt == 'x' && !env->zero)
			ft_strcat(str, "0x");
		if (env->sharp && env->arg_u != 0 && env->fmt == 'X' && !env->zero)
			ft_strcat(str, "0X");
	}
	if (env->precision)
		fill_precision4(env, str);
	return (str);
}
