/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:33 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 14:12:20 by cchampou         ###   ########.fr       */
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
	e->length = 0;
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

int		debug_print(t_parse **list)
{
	t_parse	*tmp;
	int		out;

	out = 0;
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
		printf("width : %d\n", tmp->width);
		printf("width_value : %d\n", tmp->width_value);
		printf("prec : %d\n", tmp->prec);
		printf("prec_value : %d\n", tmp->prec_value);
		printf("len : %s\n", tmp->len);
		printf("spec : %s\n", tmp->spec);
		printf("_____________\n\n");
		tmp = tmp->next;
	}
	return (out);
}

int		print(t_parse **list)
{
	t_parse	*tmp;
	int		out;

	D(printf("= parse_list_manager.c = Starting result printing...\n"));
	out = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->length)
		{
			out += tmp->length;
			ft_putnstr(tmp->raw, tmp->length);
		}
		else
		{
			out += ft_strlen(tmp->raw);
			ft_putstr(tmp->raw);
		}
		tmp = tmp->next;
	}
	D(printf("= parse_list_manager.c = Result has been printed !\n"));
	return (out);
}

void	freelist(t_parse **list)
{
	t_parse	*tmp;

	D(printf("= parse_list_manager.c = Starting list freeing...\n"));
	while (*list)
	{
		D(printf("= parse_list_manager.c = Starting element freeing...\n"));
		tmp = (*list)->next;
		if ((*list)->raw)
			free((*list)->raw);
		if ((*list)->len)
			free((*list)->len);
		if ((*list)->spec)
			free((*list)->spec);
		free(*list);
		*list = tmp;
		D(printf("= parse_list_manager.c = Element has been free !\n"));
	}
	D(printf("= parse_list_manager.c = List has been free !\n"));
}
