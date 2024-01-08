/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:52:40 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/27 09:06:30 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		success;

	success = 1;
	va_start(args, str);
	success = step_into_args(str, args);
	va_end (args);
	return (success);
}

/*
Finds the next conversion in the string and
prints out the string till that point.
 */
char	check_next_conversion(const char *str, int count)
{
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1])
		{
			if (exists_in(str[count + 1], "cspdiuxX%%"))
				return (str[count + 1]);
		}
		else
		{
			if (ft_putchar(str[count]) < 0)
				return (-1);
		}
		count++;
	}
	return ('\0');
}

/*
Checks for the conversions and returns the char of the
found conversion.
 */
char	exists_in(char c, char *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (c);
		count++;
	}
	return ('\0');
}

/*
Returns the index that comes after the next conversion '%' symbol
(Used to skip onto the next conversion)
 */
int	get_next_index(const char *str, int count)
{
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1])
			if (exists_in(str[count + 1], "cspdiuxX%%"))
				return (count + 2);
		count++;
	}
	return (count + 2);
}

/*
Returns the total length of the string, excluding the conversions
 */
int	get_pure_strlen(const char *str)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1])
		{
			if (exists_in(str[count + 1], "cspdiuxX%%"))
				count += 2;
		}
		else
		{
			count++;
			len++;
		}
	}
	return (len);
}
