/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 07:00:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

# define ERROR -1
# define ENABLE 1
# define DISABLE 0

typedef struct s_info
{
	long long	width;
	int			zero;
	int			space;
	int			plus;
	int			sharp;
	int			minus;
	int			dot;
	int			precision;
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
