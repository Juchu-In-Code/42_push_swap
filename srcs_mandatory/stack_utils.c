/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:34:56 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/09 13:30:50 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	get_index_up(t_stack stack, int pos)
{
	if (pos == 0)
		return (stack.capacity - 1);
	return (pos - 1);
}

int	get_index_down(t_stack stack, int pos)
{
	if (pos == stack.capacity - 1)
		return (0);
	return (pos + 1);
}

int	get_value_from(t_stack stack, int pos, int dir)
{
	int	new_index;

	new_index = pos;
	if (!dir)
		return (stack.nums[pos]);
	if (pos < 0)
		return (-888);
	if (dir < 0)
	{
		dir *= -1;
		while (dir--)
			new_index = (get_index_up(stack, new_index));
	}
	else
		while (dir--)
			new_index = (get_index_down(stack, new_index));
	if (new_index < 0)
		return (new_index);
	return (stack.nums[new_index]);
}
