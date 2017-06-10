/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:40 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/10 17:04:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*push_left(char *s, int offset, char c, size_t nb)
{
	size_t	len;
	char	*sout;
	size_t	i;

	i = 0;
	len = ft_strlen(s + offset);
	len += nb;
	sout = (char*)malloc(sizeof(char) * (len + 1));
	ft_strncpy(sout + nb, s, len);
	if (c != ' ' && (s[i] == '-' || s[i] == '+'))
	{
		sout[i] = s[i];
		i++;
		nb++;
	}
	while (i < nb)
		sout[i++] = c;
	free(s);
	return (sout);
}
