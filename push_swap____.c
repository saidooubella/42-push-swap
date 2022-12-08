/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap____.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:30:19 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 10:39:57 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "push_swap.h"
#include "stacks.h"

static size_t	find_sequnce_length(t_stacks *stacks, size_t start_index)
{
	size_t	prev_index;
	size_t	sequence;
	size_t	index;

	sequence = 1;
	prev_index = start_index;
	index = start_index + 1;
	while (a_at(stacks, start_index) != a_at(stacks, index))
	{
		if (a_at(stacks, prev_index) < a_at(stacks, index))
		{
			prev_index = index;
			sequence++;
		}
		index = (index + 1) % stacks->a->size;
	}
	return (sequence);
}

size_t	find_longest_sequence_index(t_stacks *stacks)
{
	size_t	lognest_sequence_index;
	size_t	lognest_sequence;
	size_t	sequence;
	size_t	index;

	lognest_sequence_index = 0;
	lognest_sequence = 0;
	index = 0;
	while (index < stacks->a->size)
	{
		sequence = find_sequnce_length(stacks, index);
		if (sequence > lognest_sequence)
		{
			lognest_sequence_index = index;
			lognest_sequence = sequence;
		}
		index++;
	}
	return (lognest_sequence_index);
}
