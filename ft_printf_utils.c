/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:58:19 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/06 13:34:29 by fmoreira         ###   ########.fr       */
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
	unsigned long	arg_va;

	arg_va = va_arg(args, unsigned long long int);
	if (arg_va)
	{
		if (masks == 112)
		{
			ft_putstr_fd("0x", 1);
			(*count) += 2;
			ft_puthex_fd(arg_va, 1, masks, count);
		}
		else
			ft_puthex_fd((unsigned int)arg_va, 1, masks, count);
	}
	else if (masks == 112)
	{
		ft_putstr_fd("0x0", 1);
		(*count) += 3;
	}
	else
	{
		ft_putchar_fd('0', 1);
		(*count)++;
	}
}

void	ft_puthex_fd(unsigned long long int n, int fd, char masks, int *count)
{
	size_t	i;

	i = n;
	n = (i % 16);
	if (n < 10)
		n += 48;
	else if (masks != 88)
		n += 87;
	else
		n += 55;
	i = i / 16;
	if (i != (i > 0 && i < 1))
		ft_puthex_fd(i, fd, masks, count);
	(*count)++;
	write(fd, &n, sizeof(char));
}
