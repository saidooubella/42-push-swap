/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_____.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:33:01 by soubella          #+#    #+#             */
/*   Updated: 2022/12/04 16:54:41 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "push_swap.h"
#include "stacks.h"

static void	apply_normal_common_rotation(
	t_stacks *stacks, t_moves_log *logs, size_t max)
{
	size_t	index;

	index = -1;
	while (++index < max)
		apply_and_print(rr, stacks, "rr\n");
	index = -1;
	if (logs->a_moves > logs->b_moves)
	{
		max = logs->a_moves - logs->b_moves;
		while (++index < max)
			apply_and_print(ra, stacks, "ra\n");
	}
	else
	{
		max = logs->b_moves - logs->a_moves;
		while (++index < max)
			apply_and_print(rb, stacks, "rb\n");
	}
}

static void	apply_reverse_common_rotation(
	t_stacks *stacks, t_moves_log *logs, size_t max)
{
	size_t	index;

	index = -1;
	while (++index < max)
		apply_and_print(rrr, stacks, "rrr\n");
	index = -1;
	if (logs->a_moves > logs->b_moves)
	{
		max = logs->a_moves - logs->b_moves;
		while (++index < max)
			apply_and_print(rra, stacks, "rra\n");
	}
	else
	{
		max = logs->b_moves - logs->a_moves;
		while (++index < max)
			apply_and_print(rrb, stacks, "rrb\n");
	}		
}

static void	apply_non_common_rotation(t_stacks *stacks, t_moves_log *logs)
{
	size_t	index;

	index = -1;
	if (logs->a_mode == NORMAL_ROT)
		while (++index < logs->a_moves)
			apply_and_print(ra, stacks, "ra\n");
	else
		while (++index < logs->a_moves)
			apply_and_print(rra, stacks, "rra\n");
	index = -1;
	if (logs->b_mode == NORMAL_ROT)
		while (++index < logs->b_moves)
			apply_and_print(rb, stacks, "rb\n");
	else
		while (++index < logs->b_moves)
			apply_and_print(rrb, stacks, "rrb\n");
}

void	apply_moves_for(t_stacks *stacks, t_moves_log *logs)
{
	size_t	max;

	if (logs->a_mode == logs->b_mode)
	{
		max = min_value(logs->a_moves, logs->b_moves);
		if (logs->a_mode == NORMAL_ROT)
			apply_normal_common_rotation(stacks, logs, max);
		else
			apply_reverse_common_rotation(stacks, logs, max);
	}
	else
		apply_non_common_rotation(stacks, logs);
	apply_and_print(pa, stacks, "pa\n");
}
