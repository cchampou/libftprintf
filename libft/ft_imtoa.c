/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:22:51 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 19:02:50 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(intmax_t nb)
{
	int	digits;

	digits = 0;
	while (nb && ++digits)
		nb /= 10;
	digits = (nb != 0) ? digits + 1 : digits;
	return (digits);
}

char		*ft_imtoa(intmax_t n)
{
	int				digits;
	intmax_t		buffer;
	char			*str;

	buffer = (n < 0) ? -n : n;
	digits = (n <= 0) ? count_digits(buffer) + 1 : count_digits(buffer);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[digits--] = '\0';
	if (buffer == 0)
		str[0] = '0';
	while (buffer)
	{
		str[digits--] = '0' + buffer % 10;
		buffer /= 10;
	}
	return (str);
}
