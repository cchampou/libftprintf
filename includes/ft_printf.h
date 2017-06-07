/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:57 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/06 11:55:31 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

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
void				print(t_parse *list);
void				freelist(t_parse **list);
void				treat_list(t_parse **list, va_list *ap);
void				treat_elem(t_parse *e, va_list *ap);
void				get_arg(t_parse *e, va_list *ap);
void				*get_function(t_parse *e);
void				get_int(t_parse *e, va_list *ap);
void				get_uint(t_parse *e, va_list *ap);
void				get_char(t_parse *e, va_list *ap);
void				get_string(t_parse *e, va_list *ap);

void				apply_raw(t_parse *e);
void				apply_width(t_parse *e);
void				apply_flags(t_parse *e);
void				apply_prec(t_parse *e);
void				print_elem(t_parse *e);
#endif
