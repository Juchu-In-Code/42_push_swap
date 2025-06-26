/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:51:46 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/05 00:02:31 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_bool	push(t_stack *from, t_stack *dest)
{
	int	dest_index;

	if (dest->curr_size == dest->capacity)
		return (f);
	if (++dest->curr_size == 1)
	{
		dest_index = dest->capacity - 1;
		dest->curr_top = dest->capacity - 1;
		dest->curr_bot = dest->capacity - 1;
	}
	else
		dest_index = get_index_up(*dest, dest->curr_top);
	if (dest_index < 0)
		return (f);
	dest->nums[dest_index] = from->nums[from->curr_top];
	dest->curr_top = dest_index;
	from->nums[from->curr_top] = -9;
	from->curr_size--;
	if (!from->curr_size)
	{
		from->curr_top = -1;
		from->curr_bot = -1;
	}
	from->curr_top = get_index_down(*from, from->curr_top);
	return (t);
}

t_ops	op_push(t_data *data, t_ops op)
{
	if (op == pa)
		if (push(&data->b, &data->a))
			return (pa);
	if (op == pb)
		if (push(&data->a, &data->b))
			return (pb);
	return (error);
}
