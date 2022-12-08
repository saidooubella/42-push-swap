/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:11:33 by soubella          #+#    #+#             */
/*   Updated: 2022/10/25 09:53:54 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "stacks.h"

# define NORMAL_ROT 0
# define REVERSE_ROT 1

typedef struct s_moves_log
{
	size_t	insertion_index;
	size_t	moves_count;
	size_t	a_moves;
	size_t	b_moves;
	int		a_mode;
	int		b_mode;
}	t_moves_log;

int			has_only_true_elements(t_int_element *elements, size_t size);
void		apply_moves_for(t_stacks *stacks, t_moves_log *logs);
int			is_sorted(t_int_element *numbers, size_t size);
t_moves_log	find_moves_for(t_stacks *stacks, size_t index);
size_t		find_longest_sequence_index(t_stacks *stacks);
size_t		min_amongst(t_int_element *nums, size_t size);
int			hardcoded_swapes_for_three(t_stacks *stacks);
int			hardcoded_swapes_for_two(t_stacks *stacks);
int			optimization_for_four(t_stacks *stacks);
int			optimization_for_five(t_stacks *stacks);
void		moves_log_zero_init(t_moves_log *logs);
int			a_at(t_stacks *stacks, size_t index);
int			b_at(t_stacks *stacks, size_t index);
size_t		max_value(size_t x, size_t y);
size_t		min_value(size_t x, size_t y);

#endif
