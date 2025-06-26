/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:49 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/04 23:18:39 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_bool	rotate(t_stack *stack)
{
	if (!stack->curr_size || stack->curr_size == 1)
		return (f);
	if (stack->curr_size == stack->capacity)
	{
		stack->curr_bot = stack->curr_top;
		stack->curr_top = get_index_down(*stack, stack->curr_top);
		return (t);
	}
	stack->curr_bot = get_index_down(*stack, stack->curr_bot);
	stack->nums[stack->curr_bot] = stack->nums[stack->curr_top];
	stack->nums[stack->curr_top] = -999;
	stack->curr_top = get_index_down(*stack, stack->curr_top);
	return (t);
}

t_ops	op_rotate(t_data *data, t_ops op)
{
	if (op == ra)
		if (rotate(&data->a))
			return (ra);
	if (op == rb)
		if (rotate(&data->b))
			return (rb);
	if (op == rr)
		if (rotate(&data->a) && rotate(&data->b))
			return (rr);
	return (error);
}
