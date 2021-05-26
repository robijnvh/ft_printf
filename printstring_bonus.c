/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstring.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 11:24:51 by rvan-hou      #+#    #+#                 */
/*   Updated: 2019/12/06 11:24:54 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstring(char *s, t_struct *flags)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	if ((flags->precision > 0 || flags->precision == -1)
	&& flags->precision < (int)ft_strlen(s))
	{
		while (flags->precision > 0)
		{
			ft_putchar(s[i]);
			i++;
			flags->count++;
			flags->precision--;
		}
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
			flags->count++;
		}
	}
}

void		checkwidth(t_struct *flags, char *str)
{
	int		check;
	char	fill;

	check = flags->width - flags->precision;
	if (flags->precision > flags->width)
		check = 0;
	if (flags->precision >= (int)ft_strlen(str))
		check = flags->width - (int)ft_strlen(str);
	if (flags->precision == -1)
		check = flags->width;
	if (flags->precision == 0)
		check = flags->width - (int)ft_strlen(str);
	fill = ' ';
	if (flags->minus > 0)
		ft_putstring(str, flags);
	while (check > 0)
	{
		if (flags->zero > 0 && flags->minus == 0)
			fill = '0';
		ft_putchar(fill);
		flags->count++;
		check--;
	}
	if (flags->minus == 0)
		ft_putstring(str, flags);
}

void		printstring(t_struct *flags, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flags->width > 0)
		checkwidth(flags, str);
	else
		ft_putstring(str, flags);
}
