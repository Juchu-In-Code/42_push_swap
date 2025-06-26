/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:29:15 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:25:15 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_bool	is_sorted(t_data *data, int start)
{
	int	sorted_i;

	sorted_i = -1;
	while (++sorted_i < data->a.curr_size)
		if (get_value_from(data->a, start, sorted_i) != sorted_i)
			return (f);
	return (t);
}

t_bool	is_reversed(t_data *data, int start)
{
	int	reversed_i;
	int	i;

	reversed_i = data->a.curr_size;
	i = -1;
	while (reversed_i--)
		if (get_value_from(data->a, start, ++i) != reversed_i)
			return (f);
	return (t);
}

t_bool	is_sorted_around(t_data *data)
{
	int	i;
	int	n;
	int	count;
	int	current;
	int	next;

	n = data->a.curr_size;
	count = 0;
	i = -1;
	while (n--)
	{
		current = get_value_from(data->a, data->a.curr_top, ++i);
		while (current < 0)
			current = get_value_from(data->a, data->a.curr_top, ++i);
		next = get_value_from(data->a, data->a.curr_top, i + 1);
		while (next < 0)
			next = get_value_from(data->a, data->a.curr_top, ++i + 1);
		if (current > next)
		{
			count++;
			if (count > 1)
				return (f);
		}
	}
	return (t);
}
