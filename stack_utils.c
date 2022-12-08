/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:00:10 by soubella          #+#    #+#             */
/*   Updated: 2022/10/22 12:08:35 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "ft_string_utils.h"
#include "ft_utilities.h"
#include "ft_atoi.h"
#include "stdlib.h"
#include "stack.h"

static void	check_existence(t_stack *stack, size_t max, int number)
{
	size_t	index;

	index = 0;
	while (index < max)
		if (stack->elements[index++].value == number)
			error();
}

static void	___(t_stack *stack, char **numbers, size_t *index)
{
	int		number;

	while (*numbers)
	{
		ft_atoi(*numbers, &number);
		check_existence(stack, *index, number);
		stack->elements[*index].value = number;
		*index += 1;
		numbers++;
	}
}

void	stack_fill(t_stack *stack, char **numbers, size_t size, size_t fsize)
{
	size_t	findex;
	size_t	index;
	char	**split;
	char	**temp;

	findex = 0;
	index = -1;
	while (++index < size)
	{
		split = string_split(numbers[index], ' ');
		___(stack, split, &findex);
		temp = split;
		while (*temp)
			free(*temp++);
		free(split);
	}
	stack->size = fsize;
}
