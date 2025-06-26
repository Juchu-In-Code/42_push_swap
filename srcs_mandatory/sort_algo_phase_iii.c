/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_phase_iii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:36:19 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/05 02:40:06 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	sort_algo_phase_three(t_data *data)
{
	int	dir_to_sort;

	dir_to_sort = dist_to_top(data->a, get_pos_of_val(data->a, 0));
	while (!is_sorted(data, data->a.curr_top))
	{
		if (dir_to_sort < 0)
			op_print(op_rev_rotate(data, rra));
		else
			op_print(op_rotate(data, ra));
	}
}
