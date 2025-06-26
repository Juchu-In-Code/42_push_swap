/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_ii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:17:33 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:34:21 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	get_chunk_index(int number, int size, int div)
{
	int	base;
	int	mod;

	base = size / div;
	mod = size % div;
	if (number < base * 2 + mod)
		return (0);
	return (((number - (base * 2 + mod)) / base) + 1);
}

t_bool	is_chunk_finished(t_data *data, int index, int size, int div)
{
	int	base;
	int	mod;
	int	start;
	int	end;

	base = size / div;
	mod = size % div;
	start = 0;
	end = (base * 2) + mod - 1;
	if (index)
	{
		start = index * base + mod + base;
		end = start + base - 1;
	}
	if (start >= size)
		start = size - 1;
	if (end >= size)
		end = size - 1;
	while (start <= end)
	{
		if (!data->aux_nums[start])
			return (f);
		start++;
	}
	return (t);
}

void	update_chunks(t_data *data, int curr, int *active, int chunk_index)
{
	if (chunk_index == active[0] || chunk_index == active[1])
		data->aux_nums[curr]++;
	if (is_chunk_finished(data, active[0], data->a.capacity, data->chunk))
		active[0] += 2;
	if (is_chunk_finished(data, active[1], data->a.capacity, data->chunk))
		active[1] += 2;
}

void	set_chunk_size(t_data *data, int size)
{
	if (is_reversed(data, data->a.curr_top) || size <= 3)
	{
		data->chunk = 1;
		return ;
	}
	if (size >= 5)
		data->chunk = 2;
	if (size >= 49)
		data->chunk = 5;
	if (size >= 99)
		data->chunk = 5;
	if (size >= 300)
		data->chunk = 12;
}
