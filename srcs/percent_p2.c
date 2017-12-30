/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:37:28 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:47:04 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision6(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = 0;
	if (env->width > env->precision && env->minus == 0)
	{
		if (env->precision > env->size)
			stop = env->new_len - env->precision - 2;
		else
			stop = env->new_len - env->size - 2;
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
	fill_precision_p(env, str, i, stop);
	return (str);
}

char	*fill_precision_p(t_ptf *env, char *str, int i, int stop)
{
	i = 0;
	ft_strcat(str, "0x");
	if (env->precision > env->width && env->precision > env->size)
		stop = env->precision - env->size;
	if (!env->width && env->size > env->precision)
		return (str);
	if (env->width > env->precision && env->width > env->size)
		stop = env->precision - env->size;
	if ((env->size > env->precision && env->size >= 4) ||
			(env->precision > env->size && env->size >= 4))
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
