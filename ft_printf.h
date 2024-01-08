/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:08:10 by melshafi          #+#    #+#             */
/*   Updated: 2023/11/27 09:50:45 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		get_next_index(const char *str, int count);
char	check_next_conversion(const char *str, int count);
char	exists_in(char c, char *set);
int		get_pure_strlen(const char *str);
int		step_into_args(const char *str, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstr_rev(char *str, int len);
int		ft_putnbr_hex(unsigned int nbr, int mode);
int		putnbr_hex_upper(unsigned int nbr, size_t len);
int		putnbr_hex_low(unsigned int nbr, size_t len);
int		get_num_len(unsigned int nbr);
int		putptr_hex(size_t ptr, size_t len);
int		ft_putptr(void *ptr);
char	*ft_unsigned_itoa(unsigned int n);

#endif
