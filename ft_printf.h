/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:58:42 by fmoreira          #+#    #+#             */
/*   Updated: 2021/09/04 19:33:08 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *strprintf, ...);
void	ft_putnbr_fd(long int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
void	ft_onechar(va_list args, char masks, int *count);
void	master_int(va_list args, char masks, int *count);
void	master_unsgined_int(va_list args, int *count);
void	master_hex(va_list args, char masks, int *count);

typedef struct s_type
{
	char	arg_char;
	size_t	arg_return;
	char	*arg_returnCP;

	#if (arg_char == 'c' || arg_char == 'i' || arg_char == 'd' || arg_char == '%')
	{
		arg_return = va_arg(args_args,	int);
	}
	if else (arg_char == 's')
	{
		arg_returnCP = va_arg(args_args,	char *);
	}
	if else (arg_char == 'p' || arg_char == 'x' || arg_char == 'X')
	{
		arg_return = va_arg(args_args,	unsigned long int);
	}
	if else (arg_char == 'u')
	{
		arg_return = va_arg(args_args,	unsigned int);
	}
	#endif
}	t_type;
#endif
