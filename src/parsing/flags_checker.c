/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:30:15 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/02 00:32:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char **s, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_flag((*s)[i]))
		i++;
	if (i > 0)
	{
		e->flags = strndup(*s, i);
		*s = *s + i;
		// printf("One or more flag(s) detected\n");
	} else {
		// printf("No flag detected\n");
	}
}

int		is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#'
		|| c == '0');
}