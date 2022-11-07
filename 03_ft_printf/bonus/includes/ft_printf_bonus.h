/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:35:53 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# define ERROR -1
# define ENABLE 1
# define DISABLE 0
# define TRUE 1
# define FALSE 0
# define INT_MAX_LEN 10

typedef struct s_info
{
	long long	width;
	int			zero;
	int			space;
	int			plus;
	int			sharp;
	int			minus;
	int			dot;
	long long	precision;
	int			*flags[256];
	int			(*types[256])(va_list, struct s_info *);
}	t_info;

int			ft_printf(const char *format, ...);

void		init_table(t_info *info);
void		init_info(t_info *info);

int			parse_format(va_list ap, const char *format, t_info *info);

int			print_char(va_list ap, t_info *info);
int			print_address(va_list ap, t_info *info);
int			print_hex_lower(va_list ap, t_info *info);
int			print_hex_upper(va_list ap, t_info *info);
int			print_decimal(va_list ap, t_info *info);
int			print_percent(va_list ap, t_info *info);
int			print_str(va_list ap, t_info *info);
int			print_u_decimal(va_list ap, t_info *info);

int			ft_isdigit(char c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *dest, int c, size_t n);
void		ft_strncpy(char *dest, const char *src, size_t n);
void		number_to_string(char *buf, uintptr_t n, int r, const char *b);
ssize_t		ft_abs(ssize_t n);
int			ft_nbrlen(size_t n, int radix);
int			set_sign(char *buf, int n, t_info *info);
int			sign_exists(t_info *info, int n);
int			find_max(int a, int b);

#endif
