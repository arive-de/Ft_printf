/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:48:16 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/06 13:30:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_space(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->new_len > env->precision || env->new_len > env->size)
		stop = env->new_len - env->size;
	if ((env->plus == 1 || env->space == 1) && env->arg_nb >= 0)
		i++;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_space_end(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = env->size;
	stop = env->new_len;
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->minus == 1 && env->size < env->precision)
		stop--;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_zero(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->new_len - int_len(env->arg_nb);
	if ((env->plus == 1 || env->space == 1) && env->arg_nb >= 0)
		i++;
	if (env->arg_nb < 0 || env->minus == 1)
		i++;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}

char	*apply_flags(t_ptf *env, char *str)
{
	if (env->arg_nb >= 0)
	{
		if (env->plus && !env->precision && (!env->space || env->space))
		{
			if (!env->width || env->zero == 1)
				ft_strcat(str, "+");
		}
		else if (env->plus == 0 && env->space == 1)
			ft_strcat(str, " ");
		if (env->width && !env->precision)
		{
			if (env->zero == 0 && env->minus == 0)
				fill_space(env, str);
			else if (env->zero == 1 && env->minus == 0)
				fill_zero(env, str);
			if (env->plus == 1 && env->zero == 0)
				ft_strcat(str, "+");
		}
		if (env->precision)
			fill_precision(env, str);
	}
	return (str);
}
