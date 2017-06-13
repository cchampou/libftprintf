/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 16:31:47 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_prec(t_parse *e)
{
	char	*tmp;

	e->prec_value += ((ft_atoi(e->raw) < 0) ? 1 : 0);
	if (e->prec)
	{
		D(printf("= apply_prec.c = Applying prec on e->raw : %s ...\n", e->raw));
		if (e->spec && (e->spec[0] == 's' || e->spec[0] == 'S'
				|| e->spec[0] == 'c'))
		{
			tmp = ft_strndup(e->raw, e->prec_value);
			free(e->raw);
			e->raw = tmp;
		}
		else if (e->spec && (e->spec[0] == 'x' || e->spec[0] == 'X'
					|| e->spec[0] == 'o' || e->spec[0] == 'O'
					|| e->spec[0] == 'd'))
		{
			if (e->prec_value > ft_strlen(e->raw) - e->plus - e->space
					&& (e->spec[0] = 'o'
						|| e->spec[0] == 'O' || e->spec[0] == 'd'))
				push_left(e, '0', e->prec_value - ft_strlen(e->raw) + e->plus
						+ e->space);
			else
				reduce_value(e);
		}
		else if (e->prec_value > ft_strlen(e->raw))
			push_left(e, '0', e->prec_value - ft_strlen(e->raw) + e->plus);
		D(printf("= apply_prec.c = Applied prec on e->raw : %s !\n", e->raw));
	}
}

void	reduce_value(t_parse *e)
{
	int		i;
	char	*tmp;

	i = 0;
	if (e->hashtag && (e->spec[0] == 'o' || e->spec[0] == 'O'))
	{
		
	}
	else 
	{
		D(printf("= apply_prec.c = Reducing value...\n"));
		while (e->raw[i] != 0 && ft_strlen(e->raw) - i > e->prec_value
			&& e->raw[i] == '0')
			i++;
		D(printf("= apply_prec.c = Found %d extra 0, removing...\n", i));
		tmp = ft_strdup(e->raw + i);
		free(e->raw);
		e->raw = tmp;
		D(printf("= apply_prec.c = Value has been reduced !\n"));
	}
}
