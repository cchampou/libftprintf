/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:33:12 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 17:43:09 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("Test d'affichage : %ld\n", (long)2147483647);
	ft_printf("Test d'affichage : %ld\n", (long)2147483647);
	return (0);
}
