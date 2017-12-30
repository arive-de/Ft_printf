/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:44:44 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:52:47 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision2(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->width > env->precision && env->minus == 0)
	{
		if (env->precision > env->size)
			stop = env->new_len - env->precision;
		else
			stop = env->new_len - env->size;
		while (i < stop)
		{
			ft_strcat(str, " ");
			i++;
		}
	}
	str = fill_precision_u(env, str, i, stop);
	return (str);
}

char	*fill_precision_u(t_ptf *env, char *str, int i, int stop)
{
	if (env->plus == 1 && env->arg_nb >= 0)
		ft_strcat(str, "+");
	i = 0;
	if (env->precision > env->width && env->precision > env->size)
		stop = env->precision - env->size;
	if (!env->width && env->size > env->precision)
		return (str);
	if (env->width > env->precision && env->width > env->size)
		stop = env->precision - env->size;
	else if (env->precision > env->width && env->size >= env->precision)
		stop = i;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}
