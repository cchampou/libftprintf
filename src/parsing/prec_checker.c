/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:28:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/05 12:33:02 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_width_or_prec(char c)
{
	return ((c >= '0' && c <= '9'));
}

void	check_prec(char **s, t_parse *e)
{
	size_t		i;
	char	save;

	if (**s == '.')
	{
		i = 0;
		++(*s);
		while (is_width_or_prec((*s)[i]))
			i++;
		save = (*s)[i];
		(*s)[i] = 0;
		e->prec_value = atoi(*s);
		(*s)[i] = save;
		e->prec = 1;
		*s += i;
	}
}
