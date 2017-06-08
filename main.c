/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:33:12 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 21:58:04 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("Test d'affichage : %llX\n", (unsigned long long)42);
	ft_printf("%llX", (unsigned long long)42);
	return (0);
}
