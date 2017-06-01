/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 17:07:49 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_param(char **format, t_parse **list)
{
	t_parse	*e;

	e = create();
	check_percent(format, e);
	check_flags(format, e);
	check_width(format, e);
	check_prec(format, e);
	check_mod(format, e);
	check_conv(format, e);
}

void	check_percent(char **format, t_parse *e)
{
	
}

void	check_flags(char **format, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_flag((*format)[i]))
		i++;
	if (i > 0)
		e->flags = strndup(*format, i);
}

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#'
		|| c == '0');
}

void	check_width(char **format, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_width_or_prec((*format)[i]))
		i++;
	if (i > 0)
		e->width = strndup(*format, i);
}

int	is_width_or_prec(char c)
{
	return (c == '*' || (c >= '0' && c <= '9'));
}

void	check_prec(char **format, t_parse *e)
{
	int	i;

	if (**format == '.')
	{
		i = 0;
		while (is_width_or_prec((*format)[i]))
			i++;
		e->prec = strndup(*format, i);
		*format += i; 
	}
}

void	check_mod(char **format, t_parse *e)
{
	
}

void	check_conv(char **format, t_parse *e)
{
	
}
