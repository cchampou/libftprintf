/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:33 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/10 10:37:10 by cchampou         ###   ########.fr       */
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

void	debug_print(t_parse **list)
{
	t_parse	*tmp;

	tmp = *list;
	while (tmp)
	{
		printf("_____________\n");
		printf("raw : %s\n", tmp->raw);
		printf("# : %d\n", tmp->hashtag);
		printf("+ : %d\n", tmp->plus);
		printf("- : %d\n", tmp->minus);
		printf("0 : %d\n", tmp->zero);
		printf("space : %d\n", tmp->space);
		printf("width : %d\n", tmp->width_value);
		printf("prec : %d\n", tmp->prec_value);
		printf("len : %s\n", tmp->len);
		printf("spec : %s\n", tmp->spec);
		tmp = tmp->next;
	}
}

int		print(t_parse **list)
{
	t_parse	*tmp;
	int		out;

	out = 0;
	tmp = *list;
	while (tmp)
	{
		out += ft_strlen(tmp->raw);
		ft_putstr(tmp->raw);
		tmp = tmp->next;
	}
	return (out);
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
