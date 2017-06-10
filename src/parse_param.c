/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/10 11:58:01 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_param(char **s, t_parse **list)
{
	t_parse	*e;

	if (**s == '%')
	{
		(*s)++;
		e = create();
		check_flags(s, e);
		check_width(s, e);
		check_prec(s, e);
		check_len(s, e);
		if (!check_spec(s, e) && !check_percent(s, e))
		{
			return (0);
		}
		push_back(list, e);
	}
	return (0);
}
