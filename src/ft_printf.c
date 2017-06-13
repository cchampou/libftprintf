/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:56:55 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 12:23:32 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		copy_raw(char **s, t_parse **list)
{
	t_parse	*e;
	int	i;

	if (**s != '\0' && **s != '%')
	{
		i = 0;
		e = create();
		while ((*s)[i] != '\0' && (*s)[i] != '%')
			i++;
		e->raw = strndup(*s, i);
		push_back(list, e);
		*s = *s + i;
	}
	return (0);
}

int		ft_parse(char *s, t_parse **list)
{
	while (*s != '\0')
	{
		if (copy_raw(&s, list) == -1
		|| parse_param(&s, list) == -1)
		{
			return (-1);
		}
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_parse	*list;
	va_list	ap;
	int		out;

	D(printf("= ft_printf.c = Entering ft_printf...\n"));
	va_start(ap, s);
	list = NULL;
	if (ft_parse((char*)s, &list) == -1)
		return (-1);
	D(debug_print(&list));
	treat_list(&list, &ap);
	out = print(&list);
	freelist(&list);
	D(printf("= ft_printf.c = Exiting ft_printf...\n"));
	return (out);
}
