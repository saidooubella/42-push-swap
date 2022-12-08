/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:33 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 10:38:13 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_string_utils.h"
#include "ft_utilities.h"
#include "stacks.h"
#include "stack.h"

static size_t	count_numbers(char **numbers, size_t size)
{
	size_t		full_size;
	size_t		index;

	full_size = 0;
	index = 0;
	while (index < size)
		full_size += calc_words_count(numbers[index++], ' ');
	return (full_size);
}

void	stacks_free(t_stacks **stacks)
{
	free((*stacks)->a->elements);
	free((*stacks)->b->elements);
	free((*stacks)->a);
	free((*stacks)->b);
	free((*stacks));
	*stacks = 0;
}

void	apply_and_print(void block(t_stacks *), t_stacks *stacks, char *string)
{
	block(stacks);
	write(STDOUT_FILENO, string, string_length(string));
}

t_stacks	*stacks_new(char **numbers, size_t size)
{
	t_stacks	*stacks;
	size_t		full_size;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == 0)
		error();
	full_size = count_numbers(numbers, size);
	stacks->a = stack_new(full_size);
	if (stacks->a == 0)
		error();
	stack_fill(stacks->a, numbers, size, full_size);
	stacks->b = stack_new(full_size);
	if (stacks->b == 0)
		error();
	return (stacks);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
