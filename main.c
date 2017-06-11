/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 10:49:51 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/11 16:24:31 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("{%30d}", 10000);
	printf("\n");
	r2 = printf("{%30d}", 10000);
	printf("\n\nft_printf returned : %d\n", r1);
	printf("printf returned : %d\n", r2);
	return (0);
}
