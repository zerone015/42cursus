/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:00:06 by yoson             #+#    #+#             */
/*   Updated: 2022/08/07 22:00:56 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_arguments_valid(int argc, char *filename)
{
	int		len;
	char	*file_extension;

	if (argc < 2)
		return (print_error("The .ber file doesn't exist"));
	len = ft_strlen(filename);
	if (len < 5)
		return (print_error("Invalid file name"));
	file_extension = ft_substr(filename, len - 4, len);
	if (!file_extension)
		return (print_error("Memory allocation failed"));
	if (ft_strncmp(file_extension, ".ber", len) != 0)
		return (print_error("Invalid file extension"));
	return (TRUE);
}
