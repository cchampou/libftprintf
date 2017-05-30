
#include "ft_printf.h"

char    *extract_param(char *format, t_list *list)
{
	t_list	*element;

	element = (t_list*)malloc(sizeof(t_list));
	element->next = null;
	element->raw = null;
	format = check_flags(format, element);
	format = check_width(format, element);
	format = check_precision(format, element);
	format = check_modifiers(format, element);
	format = check_format(format, element);
	return (format);
}

char	*check_flags(char *format, t_list *element)
{
	size_t	i;

	i = 0;
	while (is_flag(format[i]))
		i++;
	element->flags = strndup(format, i);
	return (format[i]);
}

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#'
		|| c == '0');
}

char	*check_width(char *format, t_list *element)
{
	size_t	i;

	i = 0;
	while (is_width(format[i]))
		i++;
	element->width = strndup(format, i);
}

int	is_width(char c)
{
	return (c == '*' || (c >= '0' && c <= '9'))
}

char	*check_precision(char *format, t_list *element)
{
	
}

char	*check_modifiers(char *format, t_list *element)
{
	
}

char	*check_format(char *format, t_list *element)
{
	
}
