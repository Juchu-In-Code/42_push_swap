/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:39:32 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 17:34:26 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

/*	==============================	*/
/*	========== Macros ============	*/
/*	==============================	*/

# define ROT 0
# define REV 1
# define A 1
# define B 2
# define C 3

/*	==============================	*/
/*	========== Structs ===========	*/
/*	==============================	*/

typedef struct s_moves
{
	int	val;
	int	moves_a;
	int	moves_b;
}		t_moves;

typedef struct s_stack
{
	int		*nums;
	int		curr_top;
	int		curr_bot;
	int		curr_size;
	int		capacity;
}			t_stack;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	int			*lookup;
	int			*aux_nums;
	int			chunk;
}				t_data;

typedef enum e_ops
{
	error,
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_ops;

/*	==============================	*/
//				FUNCS
/*	==============================	*/

t_bool	parse_input(t_data *data, int ac, char **input);
t_bool	init_data(t_data *data, int ac);

int		get_index_up(t_stack stack, int pos);
int		get_index_down(t_stack stack, int pos);
int		get_value_from(t_stack stack, int pos, int dir);

int		dist_to_top(t_stack stack, int i);
int		dist_to_bot(t_stack stack, int i);
int		get_pos_of_val(t_stack stack, int val);
void	add_to_lookup(t_data *data, int pos, int val);
int		calc_moves(int x, int y);

t_bool	push(t_stack *from, t_stack *dest);
t_bool	swap(t_stack *stack);
t_bool	rotate(t_stack *stack);
t_bool	rev_rotate(t_stack *stack);

void	op_print(t_ops op);
void	optimized_rots(t_data *data, t_moves *moves);
void	conditional_rot(t_data *data, int *flag);

t_ops	op_push(t_data *data, t_ops op);
t_ops	op_swap(t_data *data, t_ops op);
t_ops	op_rotate(t_data *data, t_ops op);
t_ops	op_rev_rotate(t_data *data, t_ops op);

t_bool	is_sorted(t_data *data, int start);
t_bool	is_reversed(t_data *data, int start);
t_bool	is_sorted_around(t_data *data);

int		int_abs(int x);
int		int_min(int a, int b);
int		int_max(int a, int b);
int		*int_alloc(size_t nmemb, int x);
void	int_set(int *arr, int x, size_t n);

int		circ_lis_len(t_data *data, int start, int size);

int		check_consec(t_data *data, int x, int y, int flag);
void	check_adding_to_lookup(t_data *data);
int		is_in_lookup(t_data *data, int value);

int		get_chunk_index(int number, int size, int div);
void	update_chunks(t_data *data, int curr, int *active, int chunk_index);
t_bool	is_chunk_finished(t_data *data, int index, int size, int div);
void	set_chunk_size(t_data *data, int size);

void	sort_algo_init(t_data *data, int size);
void	sort_algo_phase_one(t_data *data);
void	sort_algo_phase_two(t_data *data);
void	sort_algo_phase_three(t_data *data);

void	cleanup(t_data *data);

#endif
