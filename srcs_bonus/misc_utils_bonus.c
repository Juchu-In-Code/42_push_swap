/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:54:59 by jgalizio          #+#    #+#             */
/*   Updated: 2025/03/11 16:52:11 by jgalizio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	int_set(int *arr, int x, size_t n)
{
	while (n)
		arr[--n] = x;
}

int	*int_alloc(size_t nmemb, int x)
{
	int	*mem;

	mem = malloc(nmemb * sizeof(int));
	if (!mem)
		return (NULL);
	int_set(mem, x, nmemb);
	return (mem);
}

int	int_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
