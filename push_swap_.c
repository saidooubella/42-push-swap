/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:19:27 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 10:23:02 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	moves_log_zero_init(t_moves_log *logs)
{
	logs->insertion_index = 0;
	logs->moves_count = 0;
	logs->a_moves = 0;
	logs->b_moves = 0;
	logs->a_mode = 0;
	logs->b_mode = 0;
}

size_t	max_value(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

size_t	min_value(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

int	has_only_true_elements(t_int_element *elements, size_t size)
{
	size_t	index;

	index = -1;
	while (++index < size)
		if (elements[index].flag == 0)
			return (0);
	return (1);
}

int	is_sorted(t_int_element *numbers, size_t size)
{
	size_t	index;

	index = -1;
	if (index < 2)
		return (1);
	while (++index < size - 1)
		if (numbers[index].value > numbers[index + 1].value)
			return (0);
	return (1);
}
