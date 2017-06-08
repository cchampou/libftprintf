/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:23:12 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/22 11:23:58 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*output;
	size_t	length;
	size_t	cpt;

	cpt = 0;
	length = (size_t)ft_strlen(s1);
	if (!(output = (char*)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (cpt < length)
	{
		output[cpt] = s1[cpt];
		cpt++;
	}
	output[cpt] = '\0';
	return (output);
}
