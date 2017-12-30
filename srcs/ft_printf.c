/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:14:13 by arive-de          #+#    #+#             */
/*   Updated: 2017/04/24 18:40:05 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

t_type	*fill_tab(t_type *tab, char *sign, void (*f)(void*))
{
	tab->sign = ft_strnew(1);
	tab->sign = sign;
	tab->f_sign = f;
	return (tab);
}

t_ptf	*init_tab(t_ptf *env)
{
	env->tab = (t_type*)ft_memalloc(sizeof(t_type) * 15 + 1);
	fill_tab(env->tab, "s", &sign_s);
	fill_tab(env->tab + 1, "S", &sign_spe_s);
	fill_tab(env->tab + 2, "p", &sign_p);
	fill_tab(env->tab + 3, "d", &sign_d);
	fill_tab(env->tab + 4, "D", &sign_spe_d);
	fill_tab(env->tab + 5, "i", &sign_d);
	fill_tab(env->tab + 6, "o", &sign_o);
	fill_tab(env->tab + 7, "O", &sign_spe_o);
	fill_tab(env->tab + 8, "u", &sign_u);
	fill_tab(env->tab + 9, "U", &sign_spe_u);
	fill_tab(env->tab + 10, "x", &sign_x);
	fill_tab(env->tab + 11, "X", &sign_spe_x);
	fill_tab(env->tab + 12, "c", &sign_c);
	fill_tab(env->tab + 13, "C", &sign_spe_c);
	fill_tab(env->tab + 14, "%", &sign_percent);
	return (env);
}

int		get_type(t_ptf *env, char c)
{
	int		index;

	index = 0;
	while (index < NB_TYPE && c != env->tab[index].sign[0])
		index++;
	return (index);
}

t_ptf	*init_struct(t_ptf *env, char *str)
{
	env->len = ft_strlen((char*)str);
	env->buf = ft_strnew(5);
	env->point = ft_strnew(1);
	env->conv = ft_strnew(2);
	env->tmp = ft_strnew(0);
	init_tab(env);
	return (env);
}

int		ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	t_ptf	*env;

	i = 0;
	env = (t_ptf*)ft_memalloc(sizeof(t_ptf));
	va_start(env->ap, str);
	env = init_struct(env, (char*)str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			env->fmt = get_format((char*)str, ++i);
			i = checks(env, (char*)str, i);
			env->tab[get_type(env, env->fmt)].f_sign(env);
			i++;
		}
		else
		{
			env->tmp = ft_cjoin(env->tmp, str[i]);
			i++;
		}
	}
	len = ending(env, len);
	return (len);
}
