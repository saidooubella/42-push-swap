/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:26:53 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 10:29:00 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "push_swap.h"
#include "stacks.h"

static size_t	find_insertion_index(t_stacks *stacks, size_t index_at)
{
	size_t	insertion_index;
	size_t	start;
	size_t	index;
	int		first;

	start = min_amongst(stacks->a->elements, stacks->a->size);
	insertion_index = start;
	first = 0;
	index = start;
	while (1)
	{
		if (first == 0)
			first = 1;
		else if (index == start)
			break ;
		if (a_at(stacks, index) > b_at(stacks, index_at))
		{
			insertion_index = index;
			break ;
		}
		index = (index + 1) % stacks->a->size;
	}
	return (insertion_index);
}

static void	find_needed_stack_a_rotations(
	t_stacks *stacks, t_moves_log *logs, size_t index)
{
	logs->insertion_index = find_insertion_index(stacks, index);
	if (logs->insertion_index > stacks->a->size / 2)
	{
		logs->a_moves = stacks->a->size - logs->insertion_index;
		logs->a_mode = REVERSE_ROT;
	}
	else
	{
		logs->a_moves = logs->insertion_index;
		logs->a_mode = NORMAL_ROT;
	}
}

static void	find_needed_stack_b_rotations(
	t_stacks *stacks, t_moves_log *logs, size_t index)
{
	if (index > stacks->b->size / 2)
	{
		logs->b_moves = stacks->b->size - index;
		logs->b_mode = REVERSE_ROT;
	}
	else
	{
		logs->b_moves = index;
		logs->b_mode = NORMAL_ROT;
	}
}

t_moves_log	find_moves_for(t_stacks *stacks, size_t index)
{
	t_moves_log	logs;

	moves_log_zero_init(&logs);
	find_needed_stack_a_rotations(stacks, &logs, index);
	find_needed_stack_b_rotations(stacks, &logs, index);
	if (logs.a_mode == logs.b_mode)
		logs.moves_count += max_value(logs.a_moves, logs.b_moves);
	else
		logs.moves_count += logs.a_moves + logs.b_moves;
	logs.moves_count += 1;
	return (logs);
}
