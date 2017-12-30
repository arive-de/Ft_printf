/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:52:38 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/01 16:01:54 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	get_format(char *str, int i)
{
	int j;
	int flag;

	flag = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '%')
			return ('%');
		while (TYPES[j])
		{
			if (str[i] == TYPES[j])
				return (str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_var(t_ptf *env)
{
	env->precision = 0;
	env->plus = 0;
	env->sharp = 0;
	env->minus = 0;
	env->space = 0;
	env->zero = 0;
	ft_strclr(env->point);
	ft_strclr(env->conv);
	ft_strclr(env->buf);
}

int		checks(t_ptf *env, char *str, int i)
{
	int		j;
	int		k;
	int		l;
	int		m;
	int		flag;

	j = 0;
	k = 0;
	l = 0;
	m = 0;
	flag = 0;
	init_var(env);
	while (check_flags(env, str[i]) > 0 && str[i])
		env->buf[k++] = str[i++];
	i = check_width(env, (char*)str, i);
	while (check_point((char*)str, i) > 0 && str[i])
		env->point[l++] = str[i++];
	if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == '.')
		i = check_precision(env, (char*)str, i);
	while (check_conversion(env, (char*)str, i) > 0 && str[i])
		env->conv[m++] = str[i++];
	if (str[i] != env->fmt)
		i--;
	return (i);
}
