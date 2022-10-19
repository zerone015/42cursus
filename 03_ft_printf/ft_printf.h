/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/10/19 17:25:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

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
	int			precision;
}	t_info;

int		ft_printf(const char *format, ...);

void	struct_init(t_info *info);

void	parse_flag(t_info *info, const char **format);
void	parse_width(t_info *info, const char **format);
void	parse_precision(t_info *info, const char **format);
int		parse_type(t_info *info, va_list ap, char type);
int		parse_format(va_list ap, const char *format);

int		print_char(va_list ap, t_info *info);
int		print_hex_address(va_list ap, t_info *info);
int		print_hex_lower(va_list ap, t_info *info);
int		print_hex_upper(va_list ap, t_info *info);
int		print_nbr(va_list ap, t_info *info);
int		print_percent(t_info *info);
int		print_str(va_list ap, t_info *info);
int		print_unbr(va_list ap, t_info *info);

int		ft_isdigit(char c);
int		is_flag(char c);
int		get_max(int a, int b);
int		putnchar(char c, int n);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dest, int c, size_t n);

#endif
