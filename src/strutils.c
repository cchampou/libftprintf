/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:40 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/12 14:26:45 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	push_left(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	i = 0;
	if (e->length == 0)
		e->length = ft_strlen(e->raw);
	e->length += nb;
	sout = (char*)malloc(sizeof(char) * (e->length + 1));
	if (c != ' ' && (e->raw[i] == '-' || e->raw[i] == '+'))
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	ft_strncpy(sout + nb, e->raw, e->length);
	while (i < nb)
		sout[i++] = c;
	free(e->raw);
	e->raw = ft_strdup(sout);
	free(sout);
}

void	push_right(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	printf("%d\n", e->length);
	i = 0;
	if (e->length == 0)
		e->length = ft_strlen(e->raw);
	e->length += nb;
	sout = (char*)malloc(sizeof(char) * (e->length + 1));
	if (c != ' ' && (e->raw[i] == '-' || e->raw[i] == '+'))
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	ft_strncpy(sout, e->raw, e->length);
	while (i < nb)
	{
		sout[e->length - nb + i] = c;
		i++;
	}
	free(e->raw);
	e->raw = ft_strdup(sout);
	free(sout);
}
