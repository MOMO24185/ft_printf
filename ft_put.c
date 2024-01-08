/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:31:40 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/27 09:39:35 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//write char
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

//write str
int	ft_putstr(char *str)
{
	int		count;
	int		result;

	count = 0;
	result = 0;
	if (!str)
	{
		if (write (1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	else
	{
		while (str[count])
		{
			if (ft_putchar(str[count]) < 0)
				return (-1);
			else
				result++;
			count++;
		}
	}
	return (result);
}

int	ft_putstr_rev(char *str, int len)
{
	int		result;

	result = 0;
	if (!str)
		return (-1);
	else
	{
		while (str[--len])
			if (str[len] != '0')
				break ;
		while (len >= 0)
		{
			if (ft_putchar(str[len]) < 0)
			{
				free(str);
				return (-1);
			}
			else
				result++;
			len--;
		}
	}
	free(str);
	return (result);
}

int	ft_putnbr_hex(unsigned int nbr, int mode)
{
	size_t	len;

	len = get_num_len(nbr);
	if (!mode)
		return (putnbr_hex_low(nbr, len));
	else
		return (putnbr_hex_upper(nbr, len));
}

int	ft_putptr(void *ptr)
{
	size_t	len;

	len = sizeof(ptr);
	if (!ptr)
	{
		if (write (1, "0x0", 3) < 0)
			return (-1);
		return (3);
	}
	else
		return (putptr_hex((size_t)ptr, len));
}
