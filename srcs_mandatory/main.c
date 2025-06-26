/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:39:21 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:10:37 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (--ac == 0)
		return (1);
	if (!parse_input(&data, ac, av))
		return (2);
	if (!init_data(&data, ac))
		return (3);
	if (!(ac == 1 || is_sorted(&data, data.a.curr_top)))
	{
		sort_algo_init(&data, ac);
		sort_algo_phase_one(&data);
		sort_algo_phase_two(&data);
		sort_algo_phase_three(&data);
	}
	cleanup(&data);
	return (0);
}
