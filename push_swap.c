/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:51:38 by soubella          #+#    #+#             */
/*   Updated: 2022/12/04 16:56:01 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#include "ft_utilities.h"
#include "push_swap.h"
#include "stacks.h"

static void	mark_sequence(t_stacks *stacks, size_t sequence_index)
{
	size_t	prev_index;
	size_t	index;

	stacks->a->elements[sequence_index].flag = 1;
	prev_index = sequence_index;
	index = sequence_index + 1;
	while (a_at(stacks, sequence_index) != a_at(stacks, index))
	{
		if (a_at(stacks, prev_index) < a_at(stacks, index))
		{
			stacks->a->elements[index].flag = 1;
			prev_index = index;
		}
		index = (index + 1) % stacks->a->size;
	}
}

static int	push_non_sequence_elements_to_b(t_stacks *stacks, size_t index)
{
	size_t		jndex;

	index = -1;
	if (stacks->a->elements[0].flag == 0)
		apply_and_print(pb, stacks, "pb\n");
	else if (has_only_true_elements(stacks->a->elements, stacks->a->size))
		return (0);
	else
	{
		while (++index < stacks->a->size)
		{
			if (stacks->a->elements[index].flag == 0)
			{
				jndex = -1;
				if (index > stacks->a->size / 2)
					while (++jndex < stacks->a->size - index)
						apply_and_print(rra, stacks, "rra\n");
				else
					while (++jndex < index)
						apply_and_print(ra, stacks, "ra\n");
				break ;
			}
		}
	}
	return (1);
}

static void	find_apply_best_move_for_stack_b(t_stacks *stacks)
{
	t_moves_log	best_logs;
	t_moves_log	logs;
	size_t		index;

	while (stacks->b->size)
	{
		moves_log_zero_init(&best_logs);
		best_logs.moves_count = SIZE_T_MAX;
		index = -1;
		while (++index < stacks->b->size)
		{
			logs = find_moves_for(stacks, index);
			if (best_logs.moves_count > logs.moves_count)
				best_logs = logs;
		}
		apply_moves_for(stacks, &best_logs);
	}
}

static void	rotate_stack_a(t_stacks *stacks)
{
	size_t	min_index;
	int		min_value;

	min_index = min_amongst(stacks->a->elements, stacks->a->size);
	min_value = a_at(stacks, min_index);
	while (a_at(stacks, 0) != min_value)
	{
		if (min_index > stacks->a->size / 2)
			apply_and_print(rra, stacks, "rra\n");
		else
			apply_and_print(ra, stacks, "ra\n");
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = stacks_new(argv + 1, argc - 1);
	if (is_sorted(stacks->a->elements, stacks->a->size))
	{
		stacks_free(&stacks);
		return (0);
	}
	if (stacks->a->size <= 2)
		return (hardcoded_swapes_for_two(stacks));
	if (stacks->a->size <= 3)
		return (hardcoded_swapes_for_three(stacks));
	if (stacks->a->size <= 4)
		return (optimization_for_four(stacks));
	if (stacks->a->size <= 5)
		return (optimization_for_five(stacks));
	mark_sequence(stacks, find_longest_sequence_index(stacks));
	while (push_non_sequence_elements_to_b(stacks, -1))
	 	;
	for (size_t i = 0; i < stacks->a->size; i++) {
		fprintf(stderr, "%d\n", a_at(stacks, i));
	}
	find_apply_best_move_for_stack_b(stacks);
	rotate_stack_a(stacks);
	stacks_free(&stacks);
	return (0);
}
