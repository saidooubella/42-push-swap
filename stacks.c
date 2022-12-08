/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:11:10 by soubella          #+#    #+#             */
/*   Updated: 2022/10/18 11:22:01 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	sa(t_stacks *stacks)
{
	stack_swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	stack_swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	stack_push(stacks->a, stacks->b);
}

void	pb(t_stacks *stacks)
{
	stack_push(stacks->b, stacks->a);
}
