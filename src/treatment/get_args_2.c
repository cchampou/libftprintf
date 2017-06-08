/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:52:11 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 17:41:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_int(t_parse *e, va_list *ap)
{
	e->raw = ft_strdup(ft_itoa(va_arg(*ap, int)));
}

void	extract_schar(t_parse *e, va_list *ap)
{
	e->raw = ft_strdup(ft_itoa((signed char)va_arg(*ap, int)));
}

void	extract_sint(t_parse *e, va_list *ap)
{
	e->raw = ft_strdup(ft_itoa((short int)va_arg(*ap, int)));
}

void	extract_lint(t_parse *e, va_list *ap)
{
	e->raw = ft_strdup(ft_itoa(((long int)va_arg(*ap, int))));
}
