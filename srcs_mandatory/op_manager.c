/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:51:24 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 19:33:53 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	conditional_rot(t_data *data, int *flag)
{
	if (*flag)
	{
		op_print(op_rotate(data, rr));
		*flag = 0;
	}
	else
		op_print(op_rotate(data, ra));
}

void	op_print(t_ops op)
{
	const char	*ops[] = {
		"ERRORRRR", "pa", "pb",
		"sa", "sb", "ss",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr" };

	ft_printf("%s\n", ops[op]);
}

static void	auto_rot_combined(t_data *data, int loop, int op)
{
	while (loop--)
	{
		if (op == ROT)
			op_print(op_rotate(data, rr));
		else
			op_print(op_rev_rotate(data, rrr));
	}
}

static void	auto_rot(t_data *data, int loop, int stack, int op)
{
	int	loop_a;
	int	loop_b;

	loop_a = loop;
	loop_b = loop;
	if (stack & A)
	{
		while (loop_a--)
		{
			if (op == ROT)
				op_print(op_rotate(data, ra));
			else
				op_print(op_rev_rotate(data, rra));
		}
	}
	if (stack & B)
	{
		while (loop_b--)
		{
			if (op == ROT)
				op_print(op_rotate(data, rb));
			else
				op_print(op_rev_rotate(data, rrb));
		}
	}
}

void	optimized_rots(t_data *data, t_moves *moves)
{
	int	abs_a;
	int	abs_b;
	int	diff;
	int	overlap;

	abs_a = int_abs(moves->moves_a);
	abs_b = int_abs(moves->moves_b);
	if ((moves->moves_a < 0) == (moves->moves_b < 0))
	{
		overlap = int_min(abs_a, abs_b);
		diff = abs_a - abs_b;
		auto_rot_combined(data, overlap, moves->moves_a < 0);
		if (diff > 0)
			auto_rot(data, diff, A, moves->moves_a < 0);
		else
			auto_rot(data, -diff, B, moves->moves_a < 0);
	}
	else
	{
		if (moves->moves_a)
			auto_rot(data, abs_a, A, moves->moves_a < 0);
		if (moves->moves_b)
			auto_rot(data, abs_b, B, moves->moves_b < 0);
	}
}
