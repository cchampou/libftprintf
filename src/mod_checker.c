/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:27:47 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 23:28:02 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_mod(char **s, t_parse *e)
{
	char	*tmp;

	tmp = *s;
	printf("%c%c\n", *tmp, *(tmp + 1));
	if ((*tmp == 'h' && *(tmp + 1) == 'h')
	|| (*tmp == 'l' && *(tmp + 1) == 'l'))
	{
		printf("Mod detected\n");
		e->mod = strndup(*s, 2);
		*s = *s + 2;
	}
	else if (**s == 'h' || **s == 'l' || **s == 'j'
	|| **s == 'z')
	{
		printf("Mod detected\n");
		e->mod = strndup(*s, 1);
		(*s)++;
	}
}