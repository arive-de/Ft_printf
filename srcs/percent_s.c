/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:16:26 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:45:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width_s(t_ptf *env, char *str)
{
	env->size = ft_strlen(str);
	if (env->size > env->width && env->size > env->precision)
		return (env->size);
	else if (env->size < env->precision && env->precision > env->width)
		return (env->precision);
	else
		return (env->width);
}

char	*fill_space_s(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->width - ft_strlen(str);
	if (str[0] == 0 && env->width && env->minus == 1 && env->fmt == 'c')
	{
		env->empty = 1;
		stop--;
	}
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	*fill_space_end51(t_ptf *env, char *str, int stop, char *tmp)
{
	int i;

	i = 0;
	if ((ft_strcmp("", str) == 0 && env->precision && env->width
				&& ft_strlen(tmp) == 0 && env->fmt == 's') || env->flag == 2)
		stop = stop + 2;
	if (env->flag == 3 && !env->sharp && !env->zero && !env->plus
			&& !env->space)
		stop++;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	free(tmp);
	return (str);
}

char	*fill_space_end5(t_ptf *env, char *str)
{
	int		stop;
	char	*tmp;

	tmp = ft_strdup(str);
	stop = 0;
	env->new_len = width_s(env, str);
	str = ft_strnew(env->new_len);
	if (env->precision > ft_strlen(str))
		stop = env->new_len - env->precision;
	else if (env->precision < ft_strlen(str))
		stop = env->new_len - ft_strlen(str);
	else if (env->precision > env->size)
		stop = env->new_len - env->precision;
	else if (env->precision < env->size)
		stop = env->new_len - env->size;
	else
		stop = env->new_len;
	fill_space_end51(env, str, stop, tmp);
	return (str);
}

char	*apply_flags5(t_ptf *env, char *str)
{
	env->len = width_s(env, str);
	if (env->width > ft_strlen(str))
	{
		fill_space_s(env, str);
	}
	return (str);
}
