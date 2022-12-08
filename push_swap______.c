/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap______.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:32:56 by soubella          #+#    #+#             */
/*   Updated: 2022/11/23 09:37:02 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "push_swap.h"
#include "stacks.h"

int	hardcoded_swapes_for_two(t_stacks *stacks)
{
	if (a_at(stacks, 0) > a_at(stacks, 1))
		apply_and_print(sa, stacks, "sa\n");
	return (0);
}

int	hardcoded_swapes_for_three(t_stacks *stacks)
{
	if (a_at(stacks, 1) < a_at(stacks, 0) && a_at(stacks, 0) < a_at(stacks, 2))
		apply_and_print(sa, stacks, "sa\n");
	else if (a_at(stacks, 2) < a_at(stacks, 0) && a_at(stacks, 0) < a_at(stacks, 1))
		apply_and_print(rra, stacks, "rra\n");
	else if (a_at(stacks, 1) < a_at(stacks, 2) && a_at(stacks, 2) < a_at(stacks, 0))
		apply_and_print(ra, stacks, "ra\n");
	else if (a_at(stacks, 0) < a_at(stacks, 2) && a_at(stacks, 2) < a_at(stacks, 1))
	{
		apply_and_print(rra, stacks, "rra\n");
		apply_and_print(sa, stacks, "sa\n");
	}
	else if (a_at(stacks, 2) < a_at(stacks, 1) && a_at(stacks, 1) < a_at(stacks, 0))
	{
		apply_and_print(sa, stacks, "sa\n");
		apply_and_print(rra, stacks, "rra\n");
	}
	return (0);
}

static void	push_the_smallest_to_b(t_stacks *stacks)
{
	size_t	index;
	size_t	min;
	size_t	max;

	min = min_amongst(stacks->a->elements, stacks->a->size);
	index = -1;
	if (min > stacks->a->size / 2)
	{
		max = stacks->a->size - min;
		while (++index < max)
			apply_and_print(rra, stacks, "rra\n");
	}
	else
	{
		while (++index < min)
			apply_and_print(ra, stacks, "ra\n");
	}
	apply_and_print(pb, stacks, "pb\n");
}

int	optimization_for_four(t_stacks *stacks)
{
	push_the_smallest_to_b(stacks);
	push_the_smallest_to_b(stacks);
	hardcoded_swapes_for_two(stacks);
	apply_and_print(pa, stacks, "pa\n");
	apply_and_print(pa, stacks, "pa\n");
	return (0);
}

int	optimization_for_five(t_stacks *stacks)
{
	push_the_smallest_to_b(stacks);
	push_the_smallest_to_b(stacks);
	hardcoded_swapes_for_three(stacks);
	apply_and_print(pa, stacks, "pa\n");
	apply_and_print(pa, stacks, "pa\n");
	return (0);
}
