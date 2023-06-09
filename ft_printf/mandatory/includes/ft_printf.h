/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:52:59 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0

int			ft_printf(const char *format, ...);

void		init_parse_table(int (*types[])(va_list));

int			parse_format(va_list ap, const char *format);

int			print_char(va_list ap);
int			print_address(va_list ap);
int			print_hex_lower(va_list ap);
int			print_hex_upper(va_list ap);
int			print_decimal(va_list ap);
int			print_percent(va_list ap);
int			print_str(va_list ap);
int			print_u_decimal(va_list ap);

size_t		ft_strlen(const char *str);
void		number_to_string(char *buf, uintptr_t n, int r, const char *b);
ssize_t		ft_abs(ssize_t n);
int			ft_nbrlen(size_t n, int radix);

#endif
