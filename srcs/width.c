/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:23:56 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/06 13:31:30 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width(t_ptf *env, intmax_t nb)
{
	if (nb < 0)
		nb = nb * 10;
	env->size = int_len(nb);
	if (env->size > env->width && env->size > env->precision)
		return (env->size);
	else if (env->size < env->precision && env->precision > env->width)
		return (env->precision);
	else
		return (env->width);
}

char	*replace_zeros(t_ptf *env, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			str[i] = ' ';
		i++;
	}
	return (str);
}

int		ending(t_ptf *env, int len)
{
	int		ln;
	char	c;

	len = (env->empty == 1 ? ft_strlen(env->tmp) + 1 : ft_strlen(env->tmp));
	ln = ft_strlen(env->tmp);
	while (ln--)
	{
		c = ((int)(*(env->tmp)) == 127) ? 0 : *(env->tmp);
		ft_putchar(c);
		env->tmp++;
	}
	va_end(env->ap);
	free(env);
	return (len);
}
