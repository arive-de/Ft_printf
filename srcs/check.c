/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:41:47 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 11:38:10 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_flags(t_ptf *env, char c)
{
	if (c == '+')
		env->plus = 1;
	if (c == '-')
		env->minus = 1;
	if (c == '#')
		env->sharp = 1;
	if (c == '0')
		env->zero = 1;
	if (c == ' ')
		env->space = 1;
	if (c == '+' || c == '-' || c == '#' || c == '0' || c == ' ')
		return (1);
	return (0);
}

int		check_conversion(t_ptf *env, char *str, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
		return (6);
	else if (str[i] == 'l')
		return (5);
	else if (str[i] == 'h' && str[i + 1] == 'h')
		return (4);
	else if (str[i] == 'h')
		return (3);
	else if (str[i] == 'j')
		return (2);
	else if (str[i] == 'z')
		return (1);
	return (0);
}

int		check_precision(t_ptf *env, char *str, int i)
{
	env->precision = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		env->precision = env->precision * 10;
		env->precision = env->precision + ((int)str[i] - 48);
		i++;
	}
	return (i);
}

int		check_width(t_ptf *env, char *str, int i)
{
	env->width = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		env->width = env->width * 10;
		env->width = env->width + ((int)str[i] - 48);
		i++;
	}
	return (i);
}

int		check_point(char *str, int i)
{
	int n;

	n = i;
	while (str[i] == '.' || str[i] == 'Z' || str[i] == 'R')
		i++;
	if (i == n)
		return (0);
	else
		return (i);
}
