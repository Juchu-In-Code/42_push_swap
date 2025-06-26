/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:10:35 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/09 13:26:30 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	is_in_lookup(t_data *data, int value)
{
	if (data->lookup[value])
		return (1);
	return (0);
}

void	add_to_lookup(t_data *data, int pos, int val)
{
	data->lookup[pos] = val;
}

void	add_both_to_lookup(t_data *data, int pos_a, int pos_b, int val)
{
	add_to_lookup(data, pos_a, val);
	add_to_lookup(data, pos_b, val);
}

int	check_consec(t_data *data, int x, int y, int flag)
{
	if (flag == 1)
		return (data->a.nums[x] - data->a.nums[y] == 1);
	if (flag == -1)
		return (data->a.nums[x] - data->a.nums[y] == -1);
	return (0);
}

void	check_adding_to_lookup(t_data *data)
{
	int	next_pos;
	int	next_val;
	int	top_val;
	int	bot_val;

	next_pos = get_index_down(data->a, data->a.curr_top);
	next_val = data->a.nums[next_pos];
	top_val = data->a.nums[data->a.curr_top];
	bot_val = data->a.nums[data->a.curr_bot];
	if ((!is_in_lookup(data, top_val) != (!is_in_lookup(data, next_val))
			&& check_consec(data, data->a.curr_top, next_pos, -1)))
		add_both_to_lookup(data, top_val, next_val, 2);
	next_pos = get_index_up(data->a, data->a.curr_bot);
	next_val = data->a.nums[next_pos];
	if ((!is_in_lookup(data, top_val)) != (!is_in_lookup(data, bot_val))
		&& check_consec(data, data->a.curr_top, data->a.curr_bot, 1))
		add_both_to_lookup(data, top_val, bot_val, 2);
	if (!is_in_lookup(data, bot_val) != (!is_in_lookup(data, next_val))
		&& check_consec(data, next_pos, data->a.curr_bot, -1))
		add_both_to_lookup(data, bot_val, next_val, 2);
}
