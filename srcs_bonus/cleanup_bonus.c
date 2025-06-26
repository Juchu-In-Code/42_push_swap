/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:15:19 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 16:51:43 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	cleanup(t_data *data)
{
	free(data->a.nums);
	data->a.nums = NULL;
	free(data->b.nums);
	data->b.nums = NULL;
	free(data->lookup);
	data->lookup = NULL;
	free(data->aux_nums);
	data->aux_nums = NULL;
}
