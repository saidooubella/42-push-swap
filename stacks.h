/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:11:30 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 10:28:01 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "stack.h"

typedef struct s_stacks {
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

void		apply_and_print(
				void block(t_stacks *), t_stacks *stacks, char *string);
t_stacks	*stacks_new(char **numbers, size_t size);
void		stacks_free(t_stacks **stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);

#endif
