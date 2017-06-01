/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:28:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 23:28:58 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_width_or_prec(char c)
{
	return (c == '*' || (c >= '0' && c <= '9'));
}

void	check_prec(char **s, t_parse *e)
{
	int	i;

	if (**s == '.')
	{
		printf("Precision detected\n");
		i = 1;
		while (is_width_or_prec((*s)[i]))
			i++;
		e->prec = strndup(*s, i);
		*s += i;
	}
}