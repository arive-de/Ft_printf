/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:43:16 by arive-de          #+#    #+#             */
/*   Updated: 2017/12/06 14:40:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	convert_d(t_ptf *env)
{
	if (env->conv[0] == 'l' && env->conv[1] == 'l')
		return (va_arg(env->ap, long long int));
	else if (env->conv[0] == 'l')
		return (va_arg(env->ap, long int));
	else if (env->conv[0] == 'h' && env->conv[1] == 'h')
		return ((char)va_arg(env->ap, int));
	else if (env->conv[0] == 'h')
		return ((short int)va_arg(env->ap, int));
	else if (env->conv[0] == 'j')
		return (va_arg(env->ap, intmax_t));
	else if (env->conv[0] == 'z')
		return (va_arg(env->ap, ssize_t));
	else
		return (va_arg(env->ap, int));
}

uintmax_t	convert_spe_o(t_ptf *env)
{
	if (env->conv[0] == 'l' && env->conv[1] == 'l')
		return (va_arg(env->ap, unsigned long long int));
	else if (env->conv[0] == 'l')
		return (va_arg(env->ap, unsigned long int));
	else if (env->conv[0] == 'h' && env->conv[1] == 'h')
		return ((unsigned char)va_arg(env->ap, unsigned long long int));
	else if (env->conv[0] == 'h')
		return ((unsigned short int)va_arg(env->ap, unsigned int));
	else if (env->conv[0] == 'j')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'z')
		return (va_arg(env->ap, size_t));
	else
		return (va_arg(env->ap, unsigned long long int));
}

uintmax_t	convert_spe_d(t_ptf *env)
{
	if (env->conv[0] == 'l' && env->conv[1] == 'l')
		return (va_arg(env->ap, unsigned long long int));
	else if (env->conv[0] == 'l')
		return (va_arg(env->ap, unsigned long long int));
	else if (env->conv[0] == 'h' && env->conv[1] == 'h')
		return ((unsigned char)va_arg(env->ap, unsigned long long int));
	else if (env->conv[0] == 'h')
		return ((unsigned short int)va_arg(env->ap, unsigned int));
	else if (env->conv[0] == 'j')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'z')
		return (va_arg(env->ap, size_t));
	else
		return (va_arg(env->ap, unsigned long long int));
}

uintmax_t	convert_spe_u(t_ptf *env)
{
	if (env->conv[0] == 'l' && env->conv[1] == 'l')
		return (va_arg(env->ap, long long int));
	else if (env->conv[0] == 'l')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'h' && env->conv[1] == 'h')
		return (va_arg(env->ap, unsigned long));
	else if (env->conv[0] == 'h')
		return (va_arg(env->ap, unsigned long));
	else if (env->conv[0] == 'j')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'z')
		return (va_arg(env->ap, size_t));
	else
		return (va_arg(env->ap, unsigned long));
}

uintmax_t	convert_u(t_ptf *env)
{
	if (env->conv[0] == 'l' && env->conv[1] == 'l')
		return (va_arg(env->ap, long long int));
	else if (env->conv[0] == 'l')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'h' && env->conv[1] == 'h')
		return ((unsigned char)va_arg(env->ap, unsigned int));
	else if (env->conv[0] == 'h')
		return ((unsigned short int)va_arg(env->ap, unsigned int));
	else if (env->conv[0] == 'j')
		return (va_arg(env->ap, uintmax_t));
	else if (env->conv[0] == 'z')
		return (va_arg(env->ap, size_t));
	else
		return (va_arg(env->ap, unsigned int));
}
