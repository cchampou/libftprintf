/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:00:32 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 17:33:31 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_int(t_parse *e, va_list *ap)
{
	if (e->len == NULL)
		extract_int(e, ap);
	else if (!strcmp(e->len, "hh"))
		extract_schar(e, ap);
	else if (!strcmp(e->len, "h"))
		extract_sint(e, ap);
	else if (!strcmp(e->len, "l"))
		extract_lint(e, ap);
	else if (!strcmp(e->len, "ll"))
		printf("Get a long long int\n");
	else if (!strcmp(e->len, "j"))
		printf("Get a intmax\n");
	else if (!strcmp(e->len, "z"))
		printf("Get a size_t\n");
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
