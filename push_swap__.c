/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:24:57 by soubella          #+#    #+#             */
/*   Updated: 2022/11/27 16:57:14 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "stacks.h"

int	a_at(t_stacks *stacks, size_t index)
{
	return (stacks->a->elements[index].value);
}

int	b_at(t_stacks *stacks, size_t index)
{
	return (stacks->b->elements[index].value);
}

size_t	min_amongst(t_int_element *nums, size_t size)
{
	size_t	min_index;
	size_t	index;

	min_index = 0;
	index = -1;
	while (++index < size)
		if (nums[index].value < nums[min_index].value)
			min_index = index;
	return (min_index);
}
 