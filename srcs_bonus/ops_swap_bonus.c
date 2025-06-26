/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:58:26 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 16:53:41 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

t_bool	swap(t_stack *stack)
{
	int	aux;
	int	top_index;
	int	next_index;

	if (!stack->curr_size || stack->curr_size == 1)
		return (f);
	top_index = stack->curr_top;
	next_index = get_index_down(*stack, top_index);
	if (top_index < 0 || next_index < 0)
		return (f);
	aux = stack->nums[next_index];
	stack->nums[next_index] = stack->nums[top_index];
	stack->nums[top_index] = aux;
	return (t);
}

t_ops	op_swap(t_data *data, t_ops op)
{
	if (op == sa)
		if (swap(&data->a))
			return (sa);
	if (op == sb)
		if (swap(&data->b))
			return (sb);
	if (op == ss)
		if (swap(&data->a) && swap(&data->b))
			return (ss);
	return (error);
}
