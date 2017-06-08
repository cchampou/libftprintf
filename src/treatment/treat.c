/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:31:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 16:58:02 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_list(t_parse **list, va_list *ap)
{
	t_parse	*tmp;

	tmp = *list;
	while (tmp)
	{
		treat_elem(tmp, ap);
		tmp = tmp->next;
	}
}

void	treat_elem(t_parse *e, va_list *ap)
{
	char	*buffer;

	buffer = NULL;
	if (e->spec)
	{
		get_arg(e, ap);
		apply_raw(e);
		apply_width(e);
		apply_flags(e);
		apply_prec(e);
		print_elem(e);
	}
}

void	apply_raw(t_parse *e)
{
	(void)e;
}

void	apply_width(t_parse *e)
{
	(void)e;
}

void	apply_flags(t_parse *e)
{
	(void)e;
}

void	apply_prec(t_parse *e)
{
	(void)e;
}

void	print_elem(t_parse *e)
{
	(void)e;
}
