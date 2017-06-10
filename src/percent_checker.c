/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:31:15 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/02 00:33:46 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_percent(char **s, t_parse *e)
{
	if (**s == '%')
	{
		// printf("%% detected\n");
		e->raw = strndup(*s, 1);
		(*s)++;
		return (1);
	}
	else
		return (0);
}