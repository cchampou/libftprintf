
#include "ft_printf.h"

void	copy_raw(char **format, t_parse **list)
{
	t_parse	*e;
	int	i;

	i = 0;
	e = create();
	while (*format[i] != '\0' && *format[i] != '%')
		i++;
	e->raw = strndup(*format, i);
}

t_parse	*ft_parse(char *format)
{
	t_parse	*list;

	list = NULL;
	while (*format != '\0')
	{
		copy_raw(&format, &list);
		extract_param(&format, &list);
	}
	return (list); // return full filled list
}

int	ft_printf(const char *format, ...)
{
	t_parse	*list;
	
	list = ft_parse((char*)format);

	// At this point, no need to read format anymore
	// Now we need to treat each arg according to the list
	// And then print the result

	return (0); // Must return the number of printed characters
}
