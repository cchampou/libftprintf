/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:57 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/02 00:42:26 by cchampou         ###   ########.fr       */
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
	char			*raw;
	char			*flags;
	char			*width;
	char			*prec;
	char			*len;
	char			*conv;
}					t_parse;


int					ft_printf(const char *s, ...);
int					ft_parse(char *s, t_parse **list);
int					copy_raw(char **s, t_parse **list);
int					parse_param(char **s, t_parse **list);
void				check_flags(char **s, t_parse *e);
int					is_flag(char c);
void				check_width(char **s, t_parse *e);
int					is_width_or_prec(char c);
void				check_prec(char **s, t_parse *e);
void				check_len(char **s, t_parse *e);
int					check_conv(char **s, t_parse *e);
int					check_percent(char **s, t_parse *e);
t_parse				*create();
void				push_back(t_parse **list, t_parse *e);
void				print(t_parse *list);

#endif
