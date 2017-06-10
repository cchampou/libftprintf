/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:27:34 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/09 17:11:45 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flags(t_parse *e)
{
	if (e->space)
		apply_space(e);
	if (e->plus)
		apply_plus(e);
	if (e->hashtag)
		apply_hashtag(e);
}

void	apply_space(t_parse *e)
{
	if (!ft_strchr(e->raw, '-'))
		e->raw = push_left(e->raw, ' ', 1);
}

void	apply_plus(t_parse *e)
{
	if (!ft_strchr(e->raw, '-') && e->spec[0] != 'x' && e->spec[0] != 'X'
			&& e->spec[0] != 'o' && e->spec[0] != 'O')
	{
		if (e->raw[0] == ' ')
			e->raw[0] = '+';
		else
			e->raw = push_left(e->raw, '+', 1);
	}
}

void	apply_hashtag(t_parse *e)
{
	if (e->spec[0] == 'x')
		e->raw = push_left(e->raw, 'x', 1);
	if (e->spec[0] == 'X')
		e->raw = push_left(e->raw, 'X', 1);
	if (e->spec[0] == 'o' || e->spec[0] == 'O' || e->spec[0] == 'x'
			|| e->spec[0] == 'X')
		e->raw = push_left(e->raw, '0', 1);
}
