/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_spe_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:36:31 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 15:46:42 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*count_bits(t_ptf *env, char *str)
{
	str = ft_strnew(5);
	if (env->w_char < 0x80)
		str[0] = ((env->w_char >> 0) & 0x7F) | 0x00;
	else if (env->w_char < 0x0800)
	{
		str[0] = ((env->w_char >> 6) & 0x1F) | 0xC0;
		str[1] = ((env->w_char >> 0) & 0x3F) | 0x80;
	}
	else if (env->w_char < 0x010000)
	{
		str[0] = ((env->w_char >> 12) & 0x0F) | 0xE0;
		str[1] = ((env->w_char >> 6) & 0x3F) | 0x80;
		str[2] = ((env->w_char >> 0) & 0x3F) | 0x80;
	}
	else if (env->w_char < 0x110000)
	{
		str[0] = ((env->w_char >> 18) & 0x07) | 0xF0;
		str[1] = ((env->w_char >> 12) & 0x3F) | 0x80;
		str[2] = ((env->w_char >> 6) & 0x3F) | 0x80;
		str[3] = ((env->w_char >> 0) & 0x3F) | 0x80;
	}
	return (str);
}
