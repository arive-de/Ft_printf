/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_spe_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:07:38 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 15:01:22 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*sign_spe_s4(t_ptf *env, char *tmp, int stop, int i)
{
	stop = (env->precision > ft_strlen(tmp) ? env->width - env->precision
			: env->width - ft_strlen(tmp));
	stop = (env->flag == 1 ? stop + 1 : stop);
	stop = (env->flag == 2 ? stop + 2 : stop);
	while (i < stop)
	{
		tmp = ft_strjoin(" ", tmp);
		i++;
	}
	return (tmp);
}

char	*sign_spe_s3(t_ptf *env, char *tmp, int i)
{
	if ((env->precision > 3 && (env->precision && !env->width)) ||
			(i - env->precision == 1 && env->precision >= 6))
	{
		env->flag = (i - env->precision == 1
				&& env->precision >= 6 ? 1 : 0);
		tmp = ft_strsub(tmp, 0, env->precision - 1);
	}
	else if ((i - env->precision == 2 || i - env->precision == 1)
			&& env->precision < 6)
	{
		env->flag = 2;
		tmp = ft_strsub(tmp, 0, env->precision - 2);
	}
	else
	{
		env->flag = 3;
		tmp = ft_strsub(tmp, 0, env->precision);
	}
	return (tmp);
}

void	sign_spe_s2(t_ptf *env, char *tmp, int i)
{
	int stop;

	stop = 0;
	if (env->point[0] == '.' && env->width && !env->precision)
	{
		tmp = ft_strsub(tmp, env->width, 0);
		tmp = fill_space7(env, tmp);
	}
	else if (env->point[0] == '.' && env->precision)
		tmp = sign_spe_s3(env, tmp, i);
	else if (env->point[0] == '.')
		tmp = ft_strsub(tmp, 0, 0);
	if (env->minus)
		tmp = ft_strcat(tmp, fill_space_end5(env, tmp));
	i = 0;
	if (env->width >= env->precision && env->s_char != NULL && !env->minus)
		tmp = sign_spe_s4(env, tmp, stop, i);
	ft_strcat(env->tmp, tmp);
}

int		sign_spe_s1(t_ptf *env, char *str, int flag)
{
	str = "(null)";
	str = (env->precision ? ft_strsub(str, 0, env->precision) : str);
	str = (env->width && !env->precision ? fill_space7(env, str) : str);
	if (env->minus)
	{
		fill_space_end7(env, str);
		flag = 1;
	}
	str = (env->precision && env->width && !env->minus ?
			fill_precision7(env, str) : str);
	ft_strcat(env->tmp, str);
	return (flag);
}
