/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:00:39 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 14:44:00 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_string_utils.h"
#include "get_next_line.h"
#include "ft_utilities.h"
#include "push_swap.h"
#include "stacks.h"

int	string_equals(char *s1, char *s2)
{
	size_t	s1_length;
	size_t	s2_length;

	s1_length = string_length(s1);
	s2_length = string_length(s2);
	if (s1_length == s2_length)
		return (string_compare(s1, s2, s1_length) == 0);
	return (0);
}

void	apply_command(t_stacks *stacks, char *command)
{
	if (string_equals(command, "rra\n"))
		rra(stacks);
	else if (string_equals(command, "rrb\n"))
		rrb(stacks);
	else if (string_equals(command, "rrr\n"))
		rrr(stacks);
	else if (string_equals(command, "sa\n"))
		sa(stacks);
	else if (string_equals(command, "sb\n"))
		sb(stacks);
	else if (string_equals(command, "ss\n"))
		ss(stacks);
	else if (string_equals(command, "pa\n"))
		pa(stacks);
	else if (string_equals(command, "pb\n"))
		pb(stacks);
	else if (string_equals(command, "ra\n"))
		ra(stacks);
	else if (string_equals(command, "rb\n"))
		rb(stacks);
	else if (string_equals(command, "rr\n"))
		rr(stacks);
	else
		error();
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*line;

	if (argc < 2)
		return (0);
	stacks = stacks_new(argv + 1, argc - 1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == 0)
			break ;
		apply_command(stacks, line);
		free(line);
	}
	if (stacks->b->size == 0 && is_sorted(stacks->a->elements, stacks->a->size))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	return (0);
}
