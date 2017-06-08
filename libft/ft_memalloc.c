/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:18:42 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/26 12:50:26 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (!(ptr = (unsigned char*)malloc(sizeof(char) * (size + 1)))
			|| size > 65535)
		return (NULL);
	while (i < size)
		ptr[i++] = 0;
	ptr[i] = 0;
	return ((void*)ptr);
}
