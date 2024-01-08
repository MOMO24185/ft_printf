/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:28:11 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/27 09:48:22 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conversion(char c, va_list args);
static int	check_conversion_int(char c, va_list args);

/*
Handles arguments passed from ft_printf and takes in the original
str to write out. Controls and calls all other functions.
(arg_str cannot be null, it is checked in printf beforehand)
*/
int	step_into_args(const char *str, va_list args)
{
	char	c;
	int		len;
	int		count;
	int		temp;
	int		result;

	count = 0;
	result = 0;
	temp = 0;
	len = ft_strlen(str);
	c = 0;
	while (count <= len && str[count])
	{
		c = check_next_conversion(str, count);
		if (c < 0)
			return (-1);
		temp = check_conversion(c, args);
		if (temp < 0)
			return (-1);
		result += temp;
		count = get_next_index(str, count);
	}
	return (get_pure_strlen(str) + result);
}

static int	check_conversion(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar((va_arg(args, unsigned int))));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (check_conversion_int(c, args));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	check_conversion_int(char c, va_list args)
{
	int		res;
	char	*str;

	if (c == 'i' || c == 'd')
	{
		str = ft_itoa(va_arg(args, int));
		if (!str)
			return (-1);
		res = ft_putstr(str);
		free(str);
		return (res);
	}
	else if (c == 'u')
	{
		str = ft_unsigned_itoa(va_arg(args, unsigned int));
		if (!str)
			return (-1);
		res = ft_putstr(str);
		free(str);
		return (res);
	}
	return (0);
}

int	get_num_len(unsigned int nbr)
{
	int	c;

	c = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}
