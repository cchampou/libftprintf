/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/02 00:42:26 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_param(char **s, t_parse **list)
{
	t_parse	*e;

	if (**s == '%')
	{
		// printf("---\nFormat detected\n");
		(*s)++;
		e = create();
		// printf("Starting anlysis of char %c\n", **s);
		check_flags(s, e);
		check_width(s, e);
		check_prec(s, e);
		check_len(s, e);
		if (!check_conv(s, e) && !check_percent(s, e))
		{
			printf("XXXXXXXXX\nX ERROR X\nXXXXXXXXX\n");
			return (-1);
		}
		push_back(list, e);
	}
	return (0);
}