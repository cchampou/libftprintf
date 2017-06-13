/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:12:18 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 14:01:05 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_parse *e)
{
	int		len;

	D(printf("= apply_width.c = Applying width %d...\n", e->width_value));
	len = (e->length) ? e->length : ft_strlen(e->raw);
	if (len < e->width_value)
	{
		if (e->minus)
			push_right(e, ' ', e->width_value - len);
		else
		{
			if (e->zero)
				push_left(e, '0', e->width_value - len);
			else
				push_left(e, ' ', e->width_value - len);
		}
	}
	D(printf("= apply_width.c = Applied width !\n"));
}
