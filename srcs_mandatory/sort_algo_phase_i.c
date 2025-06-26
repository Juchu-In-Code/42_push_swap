/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_phase_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:18:21 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:09:11 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_bool	check_for_swap(t_data *data)
{
	int	next_pos;
	int	next_lookup;
	int	curr_lookup;

	next_pos = get_index_down(data->a, data->a.curr_top);
	curr_lookup = data->lookup[data->a.nums[data->a.curr_top]];
	next_lookup = data->lookup[data->a.nums[next_pos]];
	if ((!curr_lookup) != (!next_lookup)
		&& check_consec(data, data->a.curr_top, next_pos, 1))
	{
		add_to_lookup(data, data->a.nums[data->a.curr_top], 2);
		add_to_lookup(data, data->a.nums[next_pos], 2);
		return (t);
	}
	return (f);
}

t_bool	check_for_swap_rev_rot(t_data *data)
{
	int	top_value;
	int	bot_value;
	int	top_lookup;
	int	bot_lookup;

	top_value = data->a.nums[data->a.curr_top];
	bot_value = data->a.nums[data->a.curr_bot];
	bot_lookup = data->lookup[bot_value];
	top_lookup = data->lookup[top_value];
	if (((!top_lookup) != (!bot_lookup)) && (bot_value - top_value == 1))
		return (t);
	return (f);
}

void	process_element(t_data *data, int *active, int chunk_index, int *flag)
{
	if (is_in_lookup(data, data->a.nums[data->a.curr_top]))
		conditional_rot(data, flag);
	else
	{
		if (chunk_index == active[0] || chunk_index == active[1])
		{
			if (*flag)
				op_print(op_rotate(data, rb));
			op_print(op_push(data, pb));
			*flag = 0;
			if (chunk_index == active[1] && data->b.curr_size >= 2)
				*flag = 1;
		}
		else
			conditional_rot(data, flag);
	}
}

void	sort_algo_phase_one(t_data *data)
{
	int			curr;
	int			chunk_index;
	int			active[2];
	static int	flag = 0;

	active[0] = 0;
	active[1] = 1;
	int_set(data->aux_nums, 0, data->a.capacity);
	while (!is_sorted_around(data))
	{
		check_adding_to_lookup(data);
		if (check_for_swap(data))
			op_print(op_swap(data, sa));
		else if (check_for_swap_rev_rot(data))
			op_print(op_rev_rotate(data, rra));
		else
		{
			curr = data->a.nums[data->a.curr_top];
			chunk_index = get_chunk_index(curr, data->a.capacity, data->chunk);
			process_element(data, active, chunk_index, &flag);
			update_chunks(data, curr, active, chunk_index);
		}
	}
}
