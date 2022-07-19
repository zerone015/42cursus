/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 00:57:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
size_t	ft_strlen(char *str);
int		ft_puthex_address(size_t address);
int		ft_puthex_tolower(unsigned int n);
int		ft_puthex_toupper(unsigned int n);

#endif
