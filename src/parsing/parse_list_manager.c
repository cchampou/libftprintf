/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:33 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/05 16:35:51 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse	*create()
{	
	t_parse	*e;

	e = (t_parse*)malloc(sizeof(t_parse));
	e->next = NULL;
	e->raw = NULL;
	e->hashtag = 0;
	e->plus = 0;
	e->minus = 0;
	e->zero = 0;
	e->space = 0;
	e->width = 0;
	e->width_value = 0;
	e->prec = 0;
	e->prec_value = 0;
	e->len = NULL;
	e->spec = NULL;
	return (e);
}

void	push_back(t_parse **list, t_parse *e)
{
	t_parse	*tmp;

	if (*list == NULL)
		*list = e;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = e;
	}
}

void	print(t_parse *list)
{
	while (list)
	{
		printf("_____________\n");
		printf("raw : %s\n", list->raw);
		printf("# : %d\n", list->hashtag);
		printf("+ : %d\n", list->plus);
		printf("- : %d\n", list->minus);
		printf("0 : %d\n", list->zero);
		printf("space : %d\n", list->space);
		printf("width : %d\n", list->width_value);
		printf("prec : %d\n", list->prec_value);
		printf("len : %s\n", list->len);
		printf("spec : %s\n", list->spec);
		list = list->next;
	}
}

void	freelist(t_parse **list)
{
	t_parse	*tmp;
	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->raw)
			free((*list)->raw);
		if ((*list)->len)
			free((*list)->len);
		if ((*list)->spec)
			free((*list)->spec);
		free(*list);
		*list = tmp;
	}
}
