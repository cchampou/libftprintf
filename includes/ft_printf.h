
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char		*raw;
	char		*flags;
	char		*width;
	char		*precision;	
}			t_list;


int	ft_printf(const char *format, ...);

t_list	*ft_parse(char *format);

char	*copy_raw(char *format, t_list *list);

char	*extract_param(char *format, t_list *list);

char	*check_flags(char *format, t_list *element);

char	*check_width(char *format, t_list *element);

char	*check_precision(char *format, t_list *element);

char	*check_modifiers(char *format, t_list *element);

char	*check_format(char *format, t_list *element);

#endif
