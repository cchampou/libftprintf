/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:27:34 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 17:04:41 by cchampou         ###   ########.fr       */
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
	if (!ft_strchr(e->raw, '-') && e->spec != NULL && e->spec[0] != 'u'
			&& e->spec[0] != 'c')
	{
		D(printf("= apply_flags.c = Applying space flag...\n"));
		push_left(e, ' ', 1);
	}
}

void	apply_plus(t_parse *e)
{
	if (!ft_strchr(e->raw, '-') && e->spec[0] != 'x' && e->spec[0] != 'X'
			&& e->spec[0] != 'o' && e->spec[0] != 'O' && e->spec[0] != 'u'
			&& e->spec[0] != 'c')
	{
		if (e->raw[0] == ' ')
			e->raw[0] = '+';
		else
			push_left(e, '+', 1);
	}
}

void	apply_hashtag(t_parse *e)
{
	D(printf("= apply_flags.c = Applying hashtag flag...\n"));
	if (ft_strcmp(e->raw, "") && e->spec[0] == 'x')
		push_left(e, 'x', 1);
	if (ft_strcmp(e->raw, "") && e->spec[0] == 'X')
		push_left(e, 'X', 1);
	if (ft_strcmp(e->raw, "0") && ft_strcmp(e->raw, "") && (e->spec[0] == 'o'
				|| e->spec[0] == 'O'
				|| e->spec[0] == 'x' || e->spec[0] == 'X'))
		push_left(e, '0', 1);
}
