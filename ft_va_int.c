/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:58:19 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/05 11:24:01 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_onechar(va_list args, char masks, int *count)
{
	if (masks == 37)
		write(1, &masks, 1);
	else
		ft_putchar_fd(va_arg(args, int), 1);
	(*count)++;
}

void	master_int(va_list args, char masks, int *count)
{
	long int	arg_va;

	if (masks == 100 || masks == 105)
		arg_va = va_arg(args, int);
	else if (masks == 117)
		arg_va = va_arg(args, unsigned int);
	ft_putnbr_fd(arg_va, 1);
	if (arg_va <= 0)
		(*count)++;
	while (arg_va)
	{
		arg_va = arg_va / 10;
		(*count)++;
	}
}

void	master_hex(va_list args, char masks, int *count)
{
	long int			arg_va;
	//unsigned long int	max_pointer;

	masks++;
	(*count)++;
	arg_va = va_arg(args, unsigned long long int);
	printf("\n***Valor do resto va_arg por 16: %ld***\n", arg_va % 15);
	ft_putstr_fd("0x", 1);
	ft_putnbr_fd(arg_va, 1);

	arg_va++;

} 
