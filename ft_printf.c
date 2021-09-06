/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:57:52 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/05 21:36:06 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	masks_type(va_list args, char masks, int *count)
{
	char	*string_va;

	if (masks == 99 || masks == 37)
		ft_onechar(args, masks, count);
	else if (masks == 115)
	{
		string_va = va_arg(args, char *);
		if (!string_va)
		{
			ft_putstr_fd("(null)", 1);
			(*count) += 6;
		}
		if (string_va)
		{
			ft_putstr_fd(string_va, 1);
			*count += ft_strlen(string_va);
		}
	}
	else if (masks == 100 || masks == 105 || masks == 117)
		master_int(args, masks, count);
	else if (masks == 112 || masks == 120 || masks == 88)
		master_hex(args, masks, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*dupdata;
	int		i;
	int		count;

	va_start(args, format);
	dupdata = ft_strdup(format);
	i = -1;
	count = 0;
	while (dupdata[++i])
	{
		if (dupdata[i] == 37)
		{
			masks_type(args, dupdata[++i], &count);
		}
		else
		{
			ft_putchar_fd(dupdata[i], 1);
			count++;
		}
	}
	free(dupdata);
	va_end(args);
	return (count);
}
