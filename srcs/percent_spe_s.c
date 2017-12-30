/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_spe_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:22:04 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:54:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*spe_count_bits(t_ptf *env, wchar_t arg, char *str)
{
	str = ft_strnew(5);
	if (arg < 0x80)
		str[0] = ((arg >> 0) & 0x7F) | 0x00;
	else if (arg < 0x0800)
	{
		str[0] = ((arg >> 6) & 0x1F) | 0xC0;
		str[1] = ((arg >> 0) & 0x3F) | 0x80;
	}
	else if (arg < 0x010000)
	{
		str[0] = ((arg >> 12) & 0x0F) | 0xE0;
		str[1] = ((arg >> 6) & 0x3F) | 0x80;
		str[2] = ((arg >> 0) & 0x3F) | 0x80;
	}
	else if (arg < 0x110000)
	{
		str[0] = ((arg >> 18) & 0x07) | 0xF0;
		str[1] = ((arg >> 12) & 0x3F) | 0x80;
		str[2] = ((arg >> 6) & 0x3F) | 0x80;
		str[3] = ((arg >> 0) & 0x3F) | 0x80;
	}
	return (str);
}

char	*fill_space7(t_ptf *env, char *tmp)
{
	int i;
	int stop;

	i = 0;
	if (env->width && !env->precision)
		stop = env->width - ft_strlen(tmp);
	else
		stop = env->width;
	while (i < stop)
	{
		if (env->zero == 1)
			tmp = ft_strjoin("0", tmp);
		else
			tmp = ft_strjoin(" ", tmp);
		i++;
	}
	return (tmp);
}

char	*fill_precision7(t_ptf *env, char *tmp)
{
	int i;
	int stop;

	i = 0;
	if (env->precision > env->width && env->s_char != NULL)
		stop = env->width;
	else
		stop = env->width - env->precision;
	while (i < stop)
	{
		if (env->zero == 1)
			tmp = ft_strjoin("0", tmp);
		else
			tmp = ft_strjoin(" ", tmp);
		i++;
	}
	return (tmp);
}

char	*fill_space_end7(t_ptf *env, char *str)
{
	int i;
	int stop;

	i = 0;
	stop = env->width - env->precision;
	while (i < stop)
	{
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}
