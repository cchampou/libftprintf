
#include "ft_printf.h"

void	get_int(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm an int\n");
}

void	get_uint(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm an uint\n");
}

void	get_char(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm a char\n");
}

void	get_string(t_parse *e, va_list *ap)
{
	(void)e;
	(void)ap;
	printf("Hello, i'm a string\n");
}
