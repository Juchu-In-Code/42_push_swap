/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_phase_ii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:31:53 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/10 11:32:08 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int	dist_to_insert(t_data *data, int curr)
{
	int	next[2];
	int	prev[2];

	prev[1] = INT_MIN;
	next[1] = INT_MIN;
	prev[0] = get_pos_of_val(data->a, curr - 1);
	next[0] = get_pos_of_val(data->a, curr + 1);
	if (next[0] == INT_MIN && prev[0] == INT_MIN)
		return (INT_MIN);
	if (prev[0] != INT_MIN)
		prev[1] = dist_to_bot(data->a, prev[0]);
	if (next[0] != INT_MIN)
		next[1] = dist_to_top(data->a, next[0]);
	if (next[1] == INT_MIN && prev[1] == INT_MIN)
		return (INT_MIN);
	if (prev[1] == INT_MIN)
		return (next[1]);
	if (next[1] == INT_MIN)
		return (prev[1]);
	if (int_abs(prev[1]) == int_abs(next[1]))
		return (prev[1]);
	if (int_abs(prev[1]) > int_abs(next[1]))
		return (next[1]);
	return (prev[1]);
}

static void	get_best_moves(t_data *data, t_moves *best, int stack_size)
{
	t_moves	curr;
	int		pos;
	int		curr_score;
	int		best_score;

	pos = -1;
	best_score = INT_MAX;
	while (++pos < stack_size)
	{
		curr.val = get_value_from(data->b, data->b.curr_top, pos);
		curr.moves_a = dist_to_insert(data, curr.val);
		curr.moves_b = dist_to_top(data->b, pos);
		if (curr.moves_a == INT_MIN || curr.moves_b == INT_MIN)
			continue ;
		curr_score = calc_moves(curr.moves_a, curr.moves_b);
		if (best_score < curr_score)
			continue ;
		best_score = curr_score;
		best->moves_a = curr.moves_a;
		best->moves_b = curr.moves_b;
		best->val = curr.val;
		if ((!best->moves_a && !best->moves_b)
			|| (int_abs(best->moves_a) + int_abs(best->moves_b) == 1))
			break ;
	}
}

void	sort_algo_phase_two(t_data *data)
{
	t_moves		moves;

	while (data->b.curr_size)
	{
		get_best_moves(data, &moves, data->b.curr_size);
		optimized_rots(data, &moves);
		op_print(op_push(data, pa));
	}
}
