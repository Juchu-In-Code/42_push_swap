/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:17:33 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/09 13:30:40 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	calc_moves(int x, int y)
{
	int	sign_x;

	if (!x && !y)
		return (x);
	sign_x = (x >= 0);
	if ((x < 0) == (y < 0))
	{
		if (sign_x)
			return (int_max(x, y));
		else
			return (int_abs(int_min(x, y)));
	}
	if (sign_x)
		return (x + int_abs(y));
	return (int_abs(x) + y);
}

int	get_pos_of_val(t_stack stack, int val)
{
	int	pos;

	pos = -1;
	while (++pos < stack.curr_size)
		if (val == get_value_from(stack, stack.curr_top, pos))
			return (pos);
	return (INT_MIN);
}

int	dist_to_bot(t_stack stack, int i)
{
	int	dist_to_bot;

	if (i < 0 || i >= stack.curr_size || stack.curr_size <= 0)
		return (INT_MIN);
	dist_to_bot = stack.curr_size - 1 - i;
	if (dist_to_bot > stack.curr_size / 2)
		dist_to_bot -= stack.curr_size;
	return (dist_to_bot * -1);
}

int	dist_to_top(t_stack stack, int i)
{
	int	dist_to_top;

	if (i < 0 || i >= stack.curr_size || stack.curr_size <= 0)
		return (INT_MIN);
	dist_to_top = i;
	if (i > (stack.curr_size / 2))
		dist_to_top = i - stack.curr_size;
	return (dist_to_top);
}
