
#include "ft_printf.h"

char	*copy_raw(char *format, t_list *list)
{
	/*
	* This function copy the exact content of format
	* in a new list element, in the raw field,
	* until a '%' or an EOF has been encountered
	* The other fields of this element would be null.
	*/
	t_list	*element;
	int	i;

	i = 0;
	element = (t_list*)malloc(sizeof(t_list));
	element->next = null;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	element->raw = strndup(format, i);
	while (list->next)
		list = list->next;
	list->next = element;
	return (format[i]); // return the current position in format
}

t_list	*ft_parse(char *format)
{
	t_list	*list;

	list = null;
	while (*format != '\0')
	{
		format = copy_raw(format, list);
		format = extract_param(format, list);
	}
	return (list_begin); // return full filled list
}

int	ft_printf(const char *format, ...)
{
	t_list	*list;
	
	list = ft_parse((char*)format);

	// At this point, no need to read format anymore
	// Now we need to treat each arg according to the list
	// And then print the result

	return (0); // Must return the number of printed characters
}
