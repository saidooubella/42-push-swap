/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:43:58 by soubella          #+#    #+#             */
/*   Updated: 2022/10/22 12:07:42 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>

#include "ft_utilities.h"
#include "stack.h"

t_stack	*stack_new(size_t size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == 0)
		error();
	stack->elements = malloc(sizeof(t_int_element) * size);
	if (stack->elements == 0)
		error();
	fill_zero(stack->elements, sizeof(t_int_element) * size);
	stack->capacity = size;
	stack->size = 0;
	return (stack);
}

void	stack_swap(t_stack *stack)
{
	t_int_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->elements[0];
	stack->elements[0] = stack->elements[1];
	stack->elements[1] = temp;
}

void	stack_rotate(t_stack *stack)
{
	size_t			index;
	t_int_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->elements[0];
	index = 1;
	while (index < stack->size)
	{
		stack->elements[index - 1] = stack->elements[index];
		index++;
	}
	stack->elements[stack->size - 1] = temp;
}

void	stack_reverse_rotate(t_stack *stack)
{
	ssize_t			index;
	t_int_element	temp;

	if (stack->size < 2)
		return ;
	temp = stack->elements[stack->size - 1];
	index = stack->size - 2;
	while (index >= 0)
	{
		stack->elements[index + 1] = stack->elements[index];
		index--;
	}
	stack->elements[0] = temp;
}

void	stack_push(t_stack *dest, t_stack *src)
{
	ssize_t			index1;
	size_t			index2;
	t_int_element	temp;

	if (src->size == 0)
		return ;
	temp = src->elements[0];
	index2 = 1;
	while (index2 < src->size)
	{
		src->elements[index2 - 1] = src->elements[index2];
		index2++;
	}
	src->size--;
	index1 = dest->size - 1;
	while (index1 >= 0)
	{
		dest->elements[index1 + 1] = dest->elements[index1];
		index1--;
	}
	dest->elements[0] = temp;
	dest->size++;
}
