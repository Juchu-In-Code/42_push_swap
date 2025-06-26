/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_manager_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:51:24 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 19:31:14 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

static t_bool	exec_ops(t_data *data, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		return (op_push(data, pa), t);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		return (op_push(data, pb), t);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		return (op_swap(data, sa), t);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		return (op_swap(data, sb), t);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		return (op_swap(data, ss), t);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		return (op_rotate(data, ra), t);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		return (op_rotate(data, rb), t);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		return (op_rotate(data, rr), t);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		return (op_rev_rotate(data, rra), t);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		return (op_rev_rotate(data, rrb), t);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		return (op_rev_rotate(data, rrr), t);
	else
		return (ft_fprintf(2, "ERROR\n"), f);
}

t_bool	read_ops(t_data *data)
{
	char	*line;
	int		flag;

	flag = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!exec_ops(data, line))
		{
			flag = 1;
			break ;
		}
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	line = NULL;
	if (flag)
		return (f);
	return (t);
}
