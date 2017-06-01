/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:29:17 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 23:29:29 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(char **s, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_width_or_prec((*s)[i]))
		i++;
	if (i > 0)
	{
		printf("Width detected\n");
		e->width = strndup(*s, i);
		*s = *s + i;
	}
}