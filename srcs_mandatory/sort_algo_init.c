/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:18:30 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:51 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int	get_best_pos(int *what, int size)
{
	int	i;
	int	best;

	i = 1;
	best = 0;
	while (i < size)
	{
		if (what[i] > what[best])
			best = i;
		i++;
	}
	return (best);
}

static void	set_lis_marks(t_data *data, int start, int best_pos, int size)
{
	int	i;
	int	curr_pos;

	i = data->aux_nums[best_pos];
	curr_pos = best_pos;
	while (i--)
	{
		data->lookup[data->a.nums[(curr_pos + start) % size]] = 1;
		curr_pos = data->b.nums[curr_pos];
	}
}

static int	get_circ_lis_seq_pos(t_data *data, int start, int size)
{
	int	i;
	int	j;
	int	curr_pos;
	int	prev_pos;

	i = 0;
	while (++i < size)
	{
		j = -1;
		curr_pos = (i + start) % size;
		while (++j < i)
		{
			prev_pos = (j + start) % size;
			if (data->a.nums[prev_pos] < data->a.nums[curr_pos]
				&& data->aux_nums[i] < data->aux_nums[j] + 1)
			{
				data->aux_nums[i] = data->aux_nums[j] + 1;
				data->b.nums[i] = j;
			}
		}
	}
	return (get_best_pos(data->aux_nums, size));
}

int	circ_lis_len(t_data *data, int start, int size)
{
	int	i;
	int	j;
	int	curr_pos;
	int	prev_pos;

	i = 0;
	while (++i < size)
	{
		j = -1;
		curr_pos = (i + start) % size;
		while (++j < i)
		{
			prev_pos = (j + start) % size;
			if (data->a.nums[prev_pos] < data->a.nums[curr_pos]
				&& data->aux_nums[i] < data->aux_nums[j] + 1)
				data->aux_nums[i] = data->aux_nums[j] + 1;
		}
	}
	return (data->aux_nums[get_best_pos(data->aux_nums, size)]);
}

void	sort_algo_init(t_data *data, int size)
{
	int	curr;
	int	best_start_pos;
	int	best_seq_pos;

	curr = size;
	while (curr--)
	{
		int_set(data->aux_nums, 1, size);
		data->b.nums[curr] = circ_lis_len(data, curr, size);
	}
	best_start_pos = get_best_pos(data->b.nums, size);
	int_set(data->aux_nums, 1, size);
	int_set(data->lookup, 0, size);
	int_set(data->b.nums, -1, size);
	best_seq_pos = get_circ_lis_seq_pos(data, best_start_pos, size);
	set_lis_marks(data, best_start_pos, best_seq_pos, size);
	int_set(data->b.nums, -1, size);
	set_chunk_size(data, size);
}
