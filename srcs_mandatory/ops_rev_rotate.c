/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:17:07 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/04 23:20:15 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_bool	rev_rotate(t_stack *stack)
{
	if (!stack->curr_size || stack->curr_size == 1)
		return (f);
	if (stack->curr_size == stack->capacity)
	{
		stack->curr_top = stack->curr_bot;
		stack->curr_bot = get_index_up(*stack, stack->curr_bot);
		return (t);
	}
	stack->curr_top = get_index_up(*stack, stack->curr_top);
	stack->nums[stack->curr_top] = stack->nums[stack->curr_bot];
	stack->nums[stack->curr_bot] = -888;
	stack->curr_bot = get_index_up(*stack, stack->curr_bot);
	return (t);
}

t_ops	op_rev_rotate(t_data *data, t_ops op)
{
	if (op == rra)
		if (rev_rotate(&data->a))
			return (rra);
	if (op == rrb)
		if (rev_rotate(&data->b))
			return (rrb);
	if (op == rrr)
		if (rev_rotate(&data->a) && rev_rotate(&data->b))
			return (rrr);
	return (error);
}
