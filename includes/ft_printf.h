/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:57 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 16:32:01 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEBUG 0

# define D(x)	if (DEBUG) { x; }

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include <limits.h>

typedef struct			s_parse
{
	struct s_parse		*next;
	char			*raw;
	int			hashtag;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			width;
	int			width_value;
	int			prec;
	int			prec_value;
	char			*len;
	char			*spec;
	int			length;
}				t_parse;

typedef struct			s_get
{
	char			spec;
	void			(*f)(t_parse *e, va_list *ap);
}				t_get;

int				ft_printf(const char *s, ...);
int				ft_parse(char *s, t_parse **list);
int				copy_raw(char **s, t_parse **list);
int				parse_param(char **s, t_parse **list);
void				check_flags(char **s, t_parse *e);
int				is_flag(char c, t_parse *e);
void				check_width(char **s, t_parse *e);
int				is_width_or_prec(char c);
void				check_prec(char **s, t_parse *e);
void				check_len(char **s, t_parse *e);
int				check_spec(char **s, t_parse *e);
int				check_percent(char **s, t_parse *e);
t_parse				*create();
void				push_back(t_parse **list, t_parse *e);
int					debug_print(t_parse **list);
int					print(t_parse **list);
void				freelist(t_parse **list);
void				treat_list(t_parse **list, va_list *ap);
void				treat_elem(t_parse *e, va_list *ap);
void				get_arg(t_parse *e, va_list *ap);
void				*get_function(t_parse *e);
void				get_int(t_parse *e, va_list *ap);
void				get_uint(t_parse *e, va_list *ap);
void				get_ouint(t_parse *e, va_list *ap);
void				get_xuint(t_parse *e, va_list *ap);
void				get_char(t_parse *e, va_list *ap);
void				get_string(t_parse *e, va_list *ap);
void				get_ustring(t_parse *e, va_list *ap);
void				get_pointer(t_parse *e, va_list *ap);
void				apply_width(t_parse *e);
void				apply_flags(t_parse *e);
void				apply_prec(t_parse *e);
void				print_elem(t_parse *e);
void				apply_space(t_parse *e);
void				push_left(t_parse *e, char c, size_t nb);
void				push_right(t_parse *e, char c, size_t nb);
void				apply_plus(t_parse *e);
void				apply_hashtag(t_parse *e);
void				reduce_value(t_parse *e);

#endif
