/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:18 by soubella          #+#    #+#             */
/*   Updated: 2022/10/24 17:50:57 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "ft_utilities.h"

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == ' ' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

void	ft_atoi(const char *str, int *result)
{
	long long	res;
	long long	new;
	int			sign;

	sign = 1;
	res = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	if (*str == 0)
		error();
	while (is_digit(*str))
	{
		new = (res * 10) + (*str++ - 48);
		if (new < res)
			error();
		res = new;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN || *str != 0)
		error();
	*result = res;
}
