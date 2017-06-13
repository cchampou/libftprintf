/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:31:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 14:01:22 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_list(t_parse **list, va_list *ap)
{
	t_parse	*tmp;

	D(printf("= treat.c = Starting list treatment...\n"));
	tmp = *list;
	while (tmp)
	{
		treat_elem(tmp, ap);
		tmp = tmp->next;
	}
	D(printf("= treat.c = Finished list treatment !\n"));
}

void	treat_elem(t_parse *e, va_list *ap)
{
	char	*buffer;

	buffer = NULL;
	if (e->spec)
	{
		get_arg(e, ap);
	}
	apply_flags(e);
	if (e->prec)
		apply_prec(e);
	if (e->width)
		apply_width(e);
}
