/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:24:07 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/10 12:16:35 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static t_bool	check_valid(char *arg, long *valid_num)
{
	long	num;
	int		i;

	i = 0;
	if (!*arg || ft_strlen(arg) > 11)
		return (f);
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
		if (!arg[i] || arg[i] == '0')
			return (f);
	}
	if (arg[i] == '0' && arg[i + 1])
		return (f);
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (f);
	num = ft_atol(arg);
	if (INT_MIN < num && num > INT_MAX)
		return (f);
	*valid_num = num;
	return (t);
}

static t_bool	not_repeated(int *valid_list, int num_to_check, int size)
{
	int	i;

	i = 0;
	if (!size)
		return (t);
	while (i < size)
		if (valid_list[i++] == num_to_check)
			return (f);
	return (t);
}

static t_bool	init_by_index(int *indexed_nums, int *aux_nums, int size)
{
	int	i;
	int	j;
	int	count_smaller_nums;

	i = 0;
	if (!size || !indexed_nums || !aux_nums)
		return (f);
	while (i < size)
	{
		j = 0;
		count_smaller_nums = 0;
		while (j < size)
			if (aux_nums[j++] < aux_nums[i])
				count_smaller_nums++;
		indexed_nums[i++] = count_smaller_nums;
	}
	return (t);
}

t_bool	parse_input(t_data *data, int ac, char **input)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	data->aux_nums = ft_calloc(ac, sizeof(int));
	if (!data->aux_nums)
		return (f);
	while (i < ac)
	{
		if (check_valid(input[i + 1], &num))
		{
			if (!not_repeated(data->aux_nums, num, i))
				return (free(data->aux_nums), ft_fprintf(2, "Error\n"), f);
			data->aux_nums[i++] = num;
		}
		else
			return (free(data->aux_nums), ft_fprintf(2, "Error\n"), f);
	}
	return (t);
}

t_bool	init_data(t_data *data, int ac)
{
	data->lookup = ft_calloc(ac, sizeof(int));
	if (!data->lookup)
		return (free(data->aux_nums), f);
	data->a.nums = ft_calloc(ac, sizeof(int));
	if (!data->a.nums || !init_by_index(data->a.nums, data->aux_nums, ac))
		return (free(data->aux_nums), free(data->lookup), f);
	data->a.curr_top = 0;
	data->a.curr_bot = ac - 1;
	data->a.curr_size = ac;
	data->a.capacity = ac;
	data->b.nums = int_alloc(ac, -1);
	if (!data->b.nums)
	{
		free(data->a.nums);
		return (free(data->aux_nums), free(data->lookup), f);
	}
	data->b.curr_top = -1;
	data->b.curr_bot = -1;
	data->b.curr_size = 0;
	data->b.capacity = ac;
	return (t);
}
