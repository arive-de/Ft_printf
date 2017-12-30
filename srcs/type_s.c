/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:00:47 by arive-de          #+#    #+#             */
/*   Updated: 2017/03/02 16:46:02 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*sign_s2(t_ptf *env, char *str, char *dest, int i)
{
	ft_strnew(env->width);
	dest = va_arg(env->ap, char *);
	if (dest == NULL)
		dest = "(null)";
	if (env->point[0] == '.')
		dest = ft_strsub(dest, 0, env->precision);
	else if (env->point[0] == '.' && env->width && !env->precision)
		dest = ft_strsub(dest, env->width, 0);
	i = ft_strlen(dest);
	while (i < env->width)
	{
		if (env->zero == 1)
			str = ft_strcat(str, "0");
		else
			str = ft_strcat(str, " ");
		i++;
	}
	str = ft_strcat(str, dest);
	return (str);
}

int		moove_ls(t_ptf *env)
{
	if (env->conv[0] == 'l')
	{
		sign_spe_s(env);
		return (1);
	}
	return (0);
}

void	sign_s(t_ptf *env)
{
	int		i;
	int		nul;
	char	*str;
	char	*dest;

	i = 0;
	if (moove_ls(env) == 1)
		return ;
	str = ft_strnew(1);
	if (env->minus == 1)
	{
		str = va_arg(env->ap, char*);
		if (str == NULL)
		{
			str = "(null)";
			nul = 1;
		}
		if (env->precision)
			str = ft_strsub(str, 0, env->precision);
		if (env->minus == 1)
			str = ft_strjoin(str, fill_space_end5(env, str));
	}
	else
		str = sign_s2(env, str, dest, i);
	str = ft_strcat(env->tmp, str);
}

int		sign_spe_s5(t_ptf *env, char *str, int flag)
{
	str = (env->precision && env->width && !env->minus ?
			ft_strjoin(str, fill_precision7(env, str)) : "");
	str = ft_strcat(env->tmp, str);
	flag = 1;
	return (flag);
}

void	sign_spe_s(t_ptf *env)
{
	int		i;
	int		flag;
	char	*str;
	char	*tmp;

	i = 0;
	flag = 0;
	env->s_char = va_arg(env->ap, wchar_t *);
	tmp = ft_strnew(5);
	str = ft_strnew(1);
	if (env->s_char == NULL)
		flag = sign_spe_s1(env, str, flag);
	else if (ft_strcmp("", (char*)env->s_char) == 0 && env->precision)
		flag = sign_spe_s5(env, str, flag);
	else
	{
		while (env->s_char[i])
		{
			str = spe_count_bits(env, env->s_char[i], str);
			tmp = ft_strcat(tmp, str);
			i++;
		}
	}
	if (flag == 0)
		sign_spe_s2(env, tmp, i);
}
