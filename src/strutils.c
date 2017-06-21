/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:40 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/21 17:21:12 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	push_left(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	D(printf("= strutils.c = Pushing %zu chars(%c) from the left of %s...\n", nb,
				c, e->raw));
	i = 0;
	if (e->length == 0)
		e->length = ft_strlen(e->raw);
	e->length += nb;
	sout = ft_memalloc(e->length + 2);
	if ((e->raw[i] == '-' || e->raw[i] == '+' || e->raw[i] == ' ') && c == '0')
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	if (c != ' ' && e->raw[i] == '0' && (e->raw[i + 1] == 'x' || e->raw[i + 1] == 'X'))
	{
		ft_strncpy(sout, e->raw, 2);
		i += 2;
		nb += 2;
	}
	ft_strncpy(sout + nb, e->raw + i, e->length);
	while (i < nb)
		sout[i++] = c;
	e->raw = sout;
	D(printf("= strutils.c = Finished pushing %zu chars(%c) from the left of %s !\n", nb, c, e->raw));
}

void	push_right(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	i = 0;
	if (e->length == 0)
		e->length = strlen(e->raw);
	e->length += nb;
	sout = (char*)malloc(sizeof(char) * (e->length + 1));
	if (c != ' ' && (e->raw[i] == '-' || e->raw[i] == '+'))
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	while (i < nb)
	{
		sout[e->length - nb + i] = c;
		i++;
	}
	ft_strncpy(sout, e->raw, e->length - nb);
	free(e->raw);
	e->raw = ft_strdup(sout);
	free(sout);
}
