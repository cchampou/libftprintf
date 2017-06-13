/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 14:29:03 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_prec(t_parse *e)
{
	char	*tmp;

	D(printf("= apply_prec.c = Applying prec on e->raw : %s ...\n", e->raw));
	if (e->prec && e->spec && (e->spec[0] == 's' || e->spec[0] == 'S'
				|| e->spec[0] == 'c' || e->spec[0] == 'x' || e->spec[0] == 'X'))
	{
		tmp = ft_strndup(e->raw, e->prec_value);
		free(e->raw);
		e->raw = tmp;
	}
	else if (e->prec && e->prec_value > ft_strlen(e->raw))
	{
		push_left(e, '0', e->prec_value - ft_strlen(e->raw));
	}
	D(printf("= apply_prec.c = Applied prec on e->raw : %s !\n", e->raw));
}
