/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:57 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/01 16:03:24 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_parse
{
	struct s_parse	*next;
	char		*raw;
	char		*flags;
	char		*width;
	char		*prec;
	char		*mod;
	char		*conv;
}					t_parse;


int	ft_printf(const char *format, ...);

t_parse	*ft_parse(char *format);

void	copy_raw(char **format, t_parse **list);

void	extract_param(char **format, t_parse **list);

char	*check_flags(char *format, t_parse *e);

char	*check_width(char *format, t_parse *e);

char	*check_prec(char *format, t_parse *e);

char	*check_mod(char *format, t_parse *e);

char	*check_conv(char *format, t_parse *e);

t_parse	*create();

#endif
