/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:29:17 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/05 12:42:08 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(char **s, t_parse *e)
{
	size_t	i;
	char 	save;

	i = 0;
	while (is_width_or_prec((*s)[i]))
		i++;
	if (i > 0)
	{
		e->width = 1;
		save = (*s)[i];
		(*s)[i] = 0;
		e->width_value = atoi(*s);
		(*s)[i] = save;
		*s = *s + i;
	}
}
