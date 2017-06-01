/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 16:03:26 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	extract_param(char **format, t_parse **list)
{
	t_parse	*e;

	e = create();
	format = check_percent(format, e);
	format = check_flags(format, e);
	format = check_width(format, e);
	format = check_prec(format, e);
	format = check_mod(format, e);
	format = check_format(format, e);
	return (format);
}

char	*check_flags(char *format, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_flag(format[i]))
		i++;
	e->flags = strndup(format, i);
	return (format[i]);
}

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#'
		|| c == '0');
}

char	*check_width(char *format, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_width(format[i]))
		i++;
	e->width = strndup(format, i);
}

int	is_width(char c)
{
	return (c == '*' || (c >= '0' && c <= '9'))
}

char	*check_prec(char *format, t_parse *e)
{
	
}

char	*check_mod(char *format, t_parse *e)
{
	
}

char	*check_conv(char *format, t_parse *e)
{
	
}
