/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main__debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:32:39 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/10 12:23:18 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	debug_inits(t_data pswap, int ac, char **av)
{
	int	i;

	i = 0;
	ft_printf("\n");
	ft_printf("\tINIT STACKS!\n");
	ft_printf("\n");
	while (i < ac)
	{
		ft_printf("\t[ %d ]\t[\t%s\t|\t%d\t]", i, av[i + 1], pswap.aux_nums[i]);
		ft_printf(" -> [ %d ]\n", pswap.a.nums[i]);
		i++;
	}
	i = 0;

	ft_printf("\n");
}

void	debug_stack_snapshot(t_data pswap)
{
	int	ac = pswap.a.capacity;
	int	i;
	int	a;
	int	b;

	i = -1;
	ft_printf("\n");

	while (++i < ac)
	{
		ft_printf("\t[ %d ]\t", i);
		a = pswap.a.nums[i];
		if (a >= 0)
		{
			if(!pswap.lookup[a])
				ft_printf("|\t%d\t|", a);
			else if (pswap.lookup[a] == 1)
				ft_printf("|\e[34m\t%d\t\e[0m|", a);
			else
				ft_printf("|\e[32m\t%d\t\e[0m|", a);
			if (pswap.a.curr_top == i && pswap.a.curr_bot == i)
				ft_printf(" <-T/B");
			else if (pswap.a.curr_top == i)
				ft_printf(" <-T");
			else if (pswap.a.curr_bot == i)
				ft_printf(" <-B");
		}
		else
			ft_printf("|\t-\t|");
		b = pswap.b.nums[i];
		if (b >= 0)
		{
			if(!pswap.lookup[b])
				ft_printf("\t|\t%d\t|", b);
			else
				ft_printf("|\e[34m\t%d\t\e[0m|", b);
			if (pswap.b.curr_top == i && pswap.b.curr_bot == i)
				ft_printf(" <-T/B");
			else if (pswap.b.curr_top == i)
				ft_printf(" <-T");
			else if (pswap.b.curr_bot == i)
				ft_printf(" <-B");
		}
		else
			ft_printf("\t|\t-\t|");
		ft_printf("\n");
	}
	ft_printf("\t|===============================================|\n");
	ft_printf("\t\t|\tA\t|");
	ft_printf("\t|\tB\t|\n");
	ft_printf("\n");
	ft_printf("\t[STACK A] TOP: %d ( %d ) - BOT: %d ( %d ) - SIZE: %d\n", pswap.a.curr_top, get_value_from(pswap.a, pswap.a.curr_top, 0), pswap.a.curr_bot, get_value_from(pswap.a, pswap.a.curr_bot, 0), pswap.a.curr_size);
	ft_printf("\t[STACK B] TOP: %d ( %d ) - BOT: %d ( %d ) - SIZE: %d\n", pswap.b.curr_top, get_value_from(pswap.b, pswap.b.curr_top, 0), pswap.b.curr_bot, get_value_from(pswap.b, pswap.b.curr_bot, 0), pswap.b.curr_size);
	ft_printf("\tCAPACITY: %d\n", ac);
	if (is_sorted(&pswap, pswap.a.curr_top))
		ft_printf("\tSorted!\n");
	else
		ft_printf("\tNot sorted!\n");
	if (is_sorted_around(&pswap))
		ft_printf("\tSorted around!\n");
	else
		ft_printf("\tNot sorted around!\n");
	ft_printf("\n");
	ft_printf("\t|===============================================|\n");
	ft_printf("\n");
}

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
			debug_inits(data, ac,av);
		sort_algo_init(&data, ac);
			debug_stack_snapshot(data);
		sort_algo_phase_one(&data);
			debug_stack_snapshot(data);
		sort_algo_phase_two(&data);
			debug_stack_snapshot(data);
		sort_algo_phase_three(&data);
			debug_stack_snapshot(data);
	}
	cleanup(&data);
	return (0);
}

