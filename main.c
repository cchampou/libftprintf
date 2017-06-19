/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 10:49:51 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/14 15:43:08 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	printf("%S", NULL);
	ft_printf("%S", NULL);
}
