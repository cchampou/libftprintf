/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:31:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/06 11:56:17 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_list(t_parse **list)
{
	while (*list)
	{
		treat_elem(*list);
		*list = (*list)->next;
	}
}

void	treat_elem(t_parse *e)
{
	char	*buffer;

	buffer = NULL;
	treat_raw(e, &buffer);
	apply_width(e, &buffer);
	apply_flags(e, &buffer);
	apply_prec(e, &buffer);
}

void	treat_raw(t_parse *e, char **buffer)
{
	
}

void	apply_width(t_parse *e, char **buffer)
{

}

void	apply_flags(t_parse *e, char **buffer)
{

}

void	apply_prec(t_parse *e, char **buffer)
{

}
