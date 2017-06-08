/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:33:12 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 19:09:07 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("Test d'affichage : %zd\n", (size_t)9223372036854775807);
	ft_printf("Test d'affichage : %zd\n", (size_t)9223372036854775807);
	return (0);
}
