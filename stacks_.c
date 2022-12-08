/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:13:43 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 12:12:58 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	ra(t_stacks *stacks)
{
	stack_rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	stack_rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rra(t_stacks *stacks)
{
	stack_reverse_rotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	stack_reverse_rotate(stacks->b);
}
