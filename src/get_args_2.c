/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:52:11 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 09:56:26 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_ouint(t_parse *e, va_list *ap)
{
	if (!ft_strcmp(e->spec, "O"))
		e->len = ft_strdup("l");
	if (e->len == NULL)
		e->raw = ft_ouimtoa((unsigned int)va_arg(*ap, uintmax_t));
	else if (!strcmp(e->len, "hh"))
		e->raw = ft_ouimtoa((unsigned char)va_arg(*ap, int));
	else if (!strcmp(e->len, "h"))
		e->raw = ft_ouimtoa((unsigned short int)va_arg(*ap, int));
	else if (!strcmp(e->len, "l"))
		e->raw = ft_ouimtoa(((long int)va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "ll"))
		e->raw = ft_ouimtoa(((long long int)va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "j"))
		e->raw = ft_ouimtoa((va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "z"))
		e->raw = ft_ouimtoa((va_arg(*ap, size_t)));
}

void	get_xuint(t_parse *e, va_list *ap)
{
	if (e->len == NULL)
		e->raw = ft_xuimtoa((unsigned int)va_arg(*ap, intmax_t));
	else if (!strcmp(e->len, "hh"))
		e->raw = ft_xuimtoa((unsigned char)va_arg(*ap, int));
	else if (!strcmp(e->len, "h"))
		e->raw = ft_xuimtoa((unsigned short int)va_arg(*ap, int));
	else if (!strcmp(e->len, "l"))
		e->raw = ft_xuimtoa(((unsigned long int)va_arg(*ap, uintmax_t)));
	else if (!strcmp(e->len, "ll"))
		e->raw = ft_xuimtoa(((long long int)va_arg(*ap, uintmax_t)));
	else if (!strcmp(e->len, "j"))
		e->raw = ft_xuimtoa((va_arg(*ap, intmax_t)));
	else if (!strcmp(e->len, "z"))
		e->raw = ft_xuimtoa((va_arg(*ap, size_t)));
	if (e->spec[0] == 'X')
		e->raw = ft_strtoupper(e->raw);
}
