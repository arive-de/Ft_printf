/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:47:57 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 16:15:22 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision4(t_ptf *env, char *str)
{
	int i;
	int stop;

	stop = 0;
	i = (env->sharp ? 2 : 0);
	if (env->width > env->precision && env->minus == 0)
	{
		if (env->precision > env->size)
			stop = env->new_len - env->precision;
		else
			stop = env->new_len - env->size;
		if (env->size > env->precision)
			stop++;
		if ((env->size > env->precision && (env->size >= 9 ||
						env->width - env->size == 1)))
			stop--;
		while (i < stop)
		{
			ft_strcat(str, " ");
			i++;
		}
	}
	fill_precision_x(env, str, i, stop);
	return (str);
}

char	*fill_precision_x(t_ptf *env, char *str, int i, int stop)
{
	i = 0;
	if (env->sharp == 1 && env->fmt == 'x' && env->arg_u != 0)
		ft_strcat(str, "0x");
	if (env->sharp == 1 && env->fmt == 'X' && env->arg_u != 0)
		ft_strcat(str, "0X");
	if (env->precision > env->width && env->precision > env->size)
		stop = env->precision - env->size;
	if (!env->width && env->size > env->precision)
		return (str);
	if (env->width > env->precision && env->width > env->size)
		stop = env->precision - env->size;
	if ((env->size > env->precision && env->size >= 6) ||
			(env->precision > env->size && env->size >= 6))
		stop++;
	if (env->size > env->precision)
		stop = i;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}
