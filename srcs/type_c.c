/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:25:00 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/06 13:30:10 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		moove_lc(t_ptf *env)
{
	if (env->conv[0] == 'l')
	{
		sign_spe_c(env);
		return (1);
	}
	return (0);
}

char	*sign_c2(t_ptf *env, char *str, char *dest)
{
	int i;

	i = 0;
	if (env->minus == 1)
	{
		str[0] = va_arg(env->ap, int);
		str = apply_flags5(env, str);
	}
	else
	{
		dest[0] = (char)va_arg(env->ap, int);
		if (dest[0] == 0)
			dest[0] = 127;
		while (i < env->width - 1)
		{
			str = (!env->zero ? ft_strjoin(str, " ") : ft_strjoin(str, "0"));
			i++;
		}
		str = ft_cjoin(str, dest[0]);
	}
	return (str);
}

void	sign_c(t_ptf *env)
{
	char	*str;
	char	*dest;

	str = ft_strnew(1);
	dest = ft_strnew(1);
	if (moove_lc(env) == 1)
		return ;
	str = sign_c2(env, str, dest);
	if ((dest[0] == 0 && !env->minus) || (str[0] == 0 &&
				env->minus && !env->width))
		env->empty = 1;
	if (ft_strcmp(&str[env->width], "\0") == 0)
		env->null = 1;
	ft_strcat(env->tmp, str);
}

char	*sign_spe_c2(t_ptf *env, char *str, char *dest, int stop)
{
	int i;

	i = 0;
	stop = env->width - ft_strlen(str);
	if (ft_strlen(str) == 0)
	{
		env->empty = 1;
		stop--;
	}
	while (i < stop)
	{
		dest = (!env->zero ? ft_strjoin(dest, " ") : ft_strjoin(dest, "0"));
		i++;
	}
	return (dest);
}

void	sign_spe_c(t_ptf *env)
{
	int		stop;
	char	*str;
	char	*dest;

	stop = 0;
	dest = ft_strnew(env->width);
	str = ft_strnew(env->width);
	env->w_char = (wchar_t)va_arg(env->ap, wint_t);
	str = count_bits(env, str);
	if (env->minus == 1)
		str = apply_flags5(env, str);
	else
		dest = sign_spe_c2(env, str, dest, stop);
	str = ft_strjoin(dest, str);
	str = ft_strcat(env->tmp, str);
}
