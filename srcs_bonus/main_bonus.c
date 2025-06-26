/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:39:21 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:56:46 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (--ac == 0)
		return (1);
	if (!parse_input(&data, ac, av))
		return (2);
	if (!init_data(&data, ac))
		return (3);
	if (read_ops(&data))
	{
		if (is_sorted(&data, data.a.curr_top))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	cleanup(&data);
	return (0);
}
