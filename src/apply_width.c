/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:12:18 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/09 17:40:27 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_parse *e)
{
	int		len;

	len = ft_strlen(e->raw);
	if (len < e->width_value)
	{
		if (e->zero)
			e->raw = push_left(e->raw, '0', e->width_value - len);
		else
			e->raw = push_left(e->raw, ' ', e->width_value - len);
	}
}
