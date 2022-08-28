/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 07:42:40 by yoson             #+#    #+#             */
/*   Updated: 2022/08/28 09:32:52 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_instruction(char *line, t_list *list_a, t_list *list_b)
{
	if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		c_ra(list_a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		c_rb(list_b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		c_rra(list_a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		c_rrb(list_b);
	else if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		c_sa(list_a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		c_sb(list_b);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		c_pa(list_a, remove_first(list_b));
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		c_pb(list_b, remove_first(list_a));
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		c_rr(list_a, list_b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		c_rrr(list_a, list_b);
	else
		return (-1);
	return (0);
}

void	insert_numbers_to_list(t_list *list_a, int argc, char *argv[])
{
	int			i;
	char		**numbers;
	int			num;

	while (--argc)
	{
		if (**(++argv) == '\0')
			error("Error");
		numbers = ft_split(*argv, ' ');
		if (!numbers)
			error("Error");
		i = 0;
		while (numbers[i])
		{
			num = ft_atoi(numbers[i]);
			add_last(list_a, num);
			i++;
		}
		ft_free(numbers);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;
	char	*line;

	if (argc < 2)
		return (1);
	list_init(&list_a);
	insert_numbers_to_list(list_a, argc, argv);
	preprocess(list_a);
	list_init(&list_b);
	line = (char *) 1;
	while (line)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (execute_instruction(line, list_a, list_b) == -1)
			error("Error");
	}
	if (is_already_sorted(list_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}
