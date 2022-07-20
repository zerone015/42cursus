/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 22:24:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

typedef struct s_info
{
	int	width;
	int	zero;
	int	space;
	int	plus;
	int	sharp;
	int	minus;
	int	precision;
}	t_info;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
size_t	ft_strlen(char *str);
int		ft_puthex_address(size_t address);
int		ft_puthex_tolower(unsigned int n);
int		ft_puthex_toupper(unsigned int n);

#endif
