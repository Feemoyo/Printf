/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:38:39 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/05 20:40:27 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int i;
	int j;
	unsigned int k;
	//char *string; 

	k = 5;
	//string = "Hello Word!";
	//i = ft_printf("00 Teste com: '%c'\n", 'A');
	//i = ft_printf("00 Teste com: '%%'\n");
	//i = ft_printf("00 Teste com: '%s'\n", string);
	//i = ft_printf("00 Teste com: '%i', '%d'\n", k, k);
	//i = ft_printf("00 Teste com: '%u'\n", k);
	//i = ft_printf("00 Teste com: '%p', '%u'\n", &k, k);
	//i = ft_printf("00 Teste com: '%p', '%p'\n", -__LONG_MAX__ -1L, __LONG_MAX__);
	i = ft_printf("01 Teste com: '%p', '%p'\n", 0, 0);
	j = printf("01 Teste com: '%p', '%p'\n", 0, 0);

	printf("\n***Retorno de ft_printf I: %d***\n", i);
	printf("***Retorno de printf J: %d***\n", j);
}