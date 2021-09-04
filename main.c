/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:38:39 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/04 12:27:23 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int i;
	int j;
	int k;
	//char *string; 
	k = -117;
	//string = "Hello Word!";
	//i = ft_printf("00 Teste com: '%c'\n", 'A');
	//i = ft_printf("00 Teste com: '%%'\n");
	//i = ft_printf("00 Teste com: '%s'\n", string);
	//i = ft_printf("00 Teste com: '%i', '%d'\n", k, k);
	//i = ft_printf("00 Teste com: '%u'\n", k);
	i = ft_printf("00 Teste com: '%p'\n", &k);
	j = printf("01 Teste com: '%p'\n", &k);

	printf("\n***Retorno de ft_printf I: %d***\n", i);
	printf("***Retorno de printf J: %d***\n", j);
}