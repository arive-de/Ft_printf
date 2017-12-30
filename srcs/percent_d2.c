/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:16:42 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:17:13 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_precision(t_ptf *env, char *str)
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
		else if (env->width > env->size && env->size > env->precision &&
				env->arg_nb < 0)
			stop = env->new_len - env->size + 1;
		else
			stop = env->new_len - env->size;
		if (env->arg_nb < 0)
			stop--;
		while (i < stop)
		{
			ft_strcat(str, " ");
			i++;
		}
	}
	fill_precision_d(env, str, i, stop);
	return (str);
}

char	*fill_precision_d(t_ptf *env, char *str, int i, int stop)
{
	if (env->arg_nb < 0 && env->width > env->precision)
		ft_strcat(str, "-");
	if (env->arg_nb < 0 && env->width < env->precision &&
			env->width > env->size)
		ft_strcat(str, "-");
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
	if (env->arg_nb < 0 && env->size < env->precision)
		stop++;
	while (i < stop)
	{
		ft_strcat(str, "0");
		i++;
	}
	return (str);
}
