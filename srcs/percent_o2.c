/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:33:15 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:50:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision3(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	if (env->plus == 1 || env->space == 1)
		i++;
	if (env->sharp == 1 && env->width && env->precision < env->size)
		i++;
	if (env->width > env->precision && env->minus == 0)
	{
		if (env->precision > env->size)
			stop = env->new_len - env->precision;
		else
			stop = env->new_len - env->size;
		if (!env->sharp && !env->zero &&
				env->size > env->precision && env->size > 5)
			stop--;
		while (i < stop)
		{
			ft_strcat(str, " ");
			i++;
		}
	}
	str = fill_precision_o(env, str, i, stop);
	return (str);
}

char	*fill_precision_o(t_ptf *env, char *str, int i, int stop)
{
	if (env->plus == 1)
		ft_strcat(str, "+");
	i = 0;
	if (env->sharp == 1 && env->width && env->precision < env->size)
		ft_strcat(str, "0");
	if (env->precision <= env->size && !env->width &&
			env->point[0] == '.' && env->arg_u != 0)
		i++;
	if (env->precision > env->width && env->precision > env->size)
		stop = env->precision - env->size;
	if (!env->width && env->size > env->precision)
		return (str);
	if (env->width > env->precision && env->width > env->size)
		stop = env->precision - env->size;
	if (env->size > env->precision)
		stop = i;
	if ((env->precision - env->size == 0) || (!env->sharp && !env->zero
				&& env->width < env->precision && env->size > 5))
		stop--;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}
