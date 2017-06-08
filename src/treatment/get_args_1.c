/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:00:32 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 19:15:34 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_int(t_parse *e, va_list *ap)
{
	if (e->len == NULL)
		e->raw = ft_strdup(ft_itoa(va_arg(*ap, int)));
	else if (!strcmp(e->len, "hh"))
		e->raw = ft_strdup(ft_itoa((signed char)va_arg(*ap, int)));
	else if (!strcmp(e->len, "h"))
		e->raw = ft_strdup(ft_itoa((short int)va_arg(*ap, int)));
	else if (!strcmp(e->len, "l"))
		e->raw = ft_strdup(ft_imtoa(((long int)va_arg(*ap, int))));
	else if (!strcmp(e->len, "ll"))
		e->raw = ft_strdup(ft_imtoa(((long long int)va_arg(*ap, intmax_t))));
	else if (!strcmp(e->len, "j"))
		e->raw = ft_strdup(ft_imtoa((va_arg(*ap, intmax_t))));
	else if (!strcmp(e->len, "z"))
		e->raw = ft_strdup(ft_imtoa((va_arg(*ap, size_t))));
}

void	get_uint(t_parse *e, va_list *ap)
{
	if (e->len == NULL)
		printf("Get an unsigned int\n");
	else if(!strcmp(e->len, "hh"))
		printf("Get an unsigned char\n");
	else if (!strcmp(e->len, "h"))
		printf("Get an unsigned short int\n");
	else if (!strcmp(e->len, "l"))
		printf("Get an unsigned long int\n");
	else if (!strcmp(e->len, "ll"))
		printf("Get an unsigned long long int\n");
	else if (!strcmp(e->len, "j"))
		printf("Get an uintmax_t\n");
	else if (!strcmp(e->len, "z"))
		printf("Get a size_t\n");
	(void)e;
	(void)ap;
}

void	get_char(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm a char\n");
}

void	get_string(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm a string\n");
}
