/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:28:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 09:57:45 by cchampou         ###   ########.fr       */
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
	char		*tmp;

	if (**s == '.')
	{
		D(printf("= prec_checker.c = Precision reached, parsing...\n"));
		i = 0;
		++(*s);
		while (is_width_or_prec((*s)[i]))
			i++;
		tmp = ft_strndup(*s, i);
		e->prec_value = atoi(tmp);
		e->prec = 1;
		free(tmp);
		*s += i;
	}
}
