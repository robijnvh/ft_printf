/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printchar.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 16:01:29 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/12/06 16:01:30 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	writechar(char c, t_struct *flags)
{
	ft_putchar(c);
	flags->count++;
}

void	printchar(t_struct *flags, va_list ap)
{
	char	fill;
	char	c;

	c = va_arg(ap, int);
	fill = ' ';
	if (flags->width > 0)
	{
		if (flags->minus > 0)
			writechar(c, flags);
		while (flags->width > 1)
		{
			if (flags->zero > 0 && flags->minus == 0)
				fill = '0';
			ft_putchar(fill);
			flags->count++;
			flags->width--;
		}
		if (flags->minus == 0)
			writechar(c, flags);
	}
	else
		writechar(c, flags);
	return ;
}
