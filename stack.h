/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:44:00 by soubella          #+#    #+#             */
/*   Updated: 2022/10/23 19:21:41 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <sys/types.h>

typedef struct s_int_element
{
	int	value;
	int	flag;
}	t_int_element;

typedef struct s_stack {
	t_int_element	*elements;
	size_t			capacity;
	size_t			size;
}	t_stack;

t_stack	*stack_new(size_t size);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
void	stack_push(t_stack *dest, t_stack *src);
void	stack_fill(t_stack *stack, char **numbers, size_t size, size_t fsize);

#endif
