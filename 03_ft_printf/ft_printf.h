/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:52:02 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 16:49:34 by yoson            ###   ########.fr       */
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

void	struct_init(t_info info);

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
int		print_str(va_list ap, t_info info);
int		print_unbr(va_list ap, t_info *info);

#endif
