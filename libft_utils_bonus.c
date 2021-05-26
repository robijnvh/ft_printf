/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 15:09:51 by rvan-hou       #+#    #+#                */
/*   Updated: 2019/12/15 13:22:57 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (0);
		ptr++;
	}
	return (ptr);
}

void			ft_putnbrdigit(long n, t_struct *flags)
{
	char	y;

	if (n < 0)
	{
		writechar('-', flags);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbrdigit((n / 10), flags);
		ft_putnbrdigit((n % 10), flags);
	}
	else
	{
		y = 48 + n;
		writechar(y, flags);
	}
}

int				ilen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int				ptr_length(unsigned long hex)
{
	int		ret;

	ret = 0;
	while (hex)
	{
		hex = hex / 16;
		ret++;
	}
	return (ret);
}
