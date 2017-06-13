/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:00:32 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 18:09:12 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_int(t_parse *e, va_list *ap)
{
	if (!ft_strcmp(e->spec, "D"))
		e->len = ft_strdup("l");
	if (e->len == NULL)
		e->raw = ft_itoa(va_arg(*ap, intmax_t));
	else if (!strcmp(e->len, "hh"))
		e->raw = ft_itoa((signed char)va_arg(*ap, intmax_t));
	else if (!strcmp(e->len, "h"))
		e->raw = ft_itoa((short int)va_arg(*ap, intmax_t));
	else if (!strcmp(e->len, "l"))
		e->raw = ft_imtoa(((long int)va_arg(*ap, long int)));
	else if (!strcmp(e->len, "ll"))
		e->raw = ft_imtoa(((long long int)va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "j"))
		e->raw = ft_imtoa((va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "z"))
		e->raw = ft_imtoa((va_arg(*ap, size_t)));
}

void	get_uint(t_parse *e, va_list *ap)
{
	if (!ft_strcmp(e->spec, "U"))
		e->len = ft_strdup("l");
	if (e->len == NULL)
		e->raw = ft_uimtoa(va_arg(*ap, unsigned int));
	else if (!strcmp(e->len, "hh"))
		e->raw = ft_uimtoa((unsigned char)va_arg(*ap, unsigned int));
	else if (!strcmp(e->len, "h"))
		e->raw = ft_uimtoa((unsigned short int)va_arg(*ap, unsigned int));
	else if (!strcmp(e->len, "l"))
		e->raw = ft_uimtoa((unsigned long int)va_arg(*ap, uintmax_t));
	else if (!strcmp(e->len, "ll"))
		e->raw = ft_uimtoa((unsigned long long int)va_arg(*ap, uintmax_t));
	else if (!strcmp(e->len, "j"))
		e->raw = ft_uimtoa(va_arg(*ap, uintmax_t));
	else if (!strcmp(e->len, "z"))
		e->raw = ft_uimtoa((size_t)va_arg(*ap, uintmax_t));
}

void	get_char(t_parse *e, va_list *ap)
{
	char	tmp;

	tmp = (char)va_arg(*ap, int);
	if (tmp)
		e->raw = ft_strndup(&tmp, 1);
	else
	{
		e->raw = ft_strnew(1);
		e->raw[0] = '\0';
		e->length = 1;
	}
}

void	get_string(t_parse *e, va_list *ap)
{
	char	*tmp;

	tmp = va_arg(*ap, char *);
	if (tmp)
		e->raw = ft_strdup(tmp);
	else
		e->raw = ft_strdup("(null)");
}

void	get_ustring(t_parse *e, va_list *ap)
{
	char	*tmp;

	tmp = va_arg(*ap, char *);
	if (tmp)
	{
		e->raw = ft_strdup(tmp);
		e->raw = ft_strtoupper(e->raw);
	}
	else
		e->raw = ft_strdup("(null)");
}
