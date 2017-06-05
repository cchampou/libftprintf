
#include "ft_printf.h"

int		copy_raw(char **s, t_parse **list)
{
	t_parse	*e;
	int	i;

	if (**s != '\0' && **s != '%')
	{
		i = 0;
		e = create();
		while ((*s)[i] != '\0' && (*s)[i] != '%')
			i++;
		e->raw = strndup(*s, i);
		push_back(list, e);
		*s = *s + i;
	}
	return (0);
}

int		ft_parse(char *s, t_parse **list)
{
	while (*s != '\0')
	{
		if (copy_raw(&s, list) == -1
		|| parse_param(&s, list) == -1)
		{
			return (-1);
		}
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_parse	*list;
	
	list = NULL;
	if (ft_parse((char*)s, &list) == -1)
		return (-1);
	print(list);
	freelist(&list);
	return (0);
}
