/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:32:19 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/12 11:38:30 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include <stdlib.h>

int	main(void)
{
	char	*test;
	char	*out;

	test = ft_strdup("Hello");
	out = ft_strdup(test);
	free(test);
	free(out);
	return (0);
}
