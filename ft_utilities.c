/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:09:10 by soubella          #+#    #+#             */
/*   Updated: 2022/10/25 09:57:32 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void	fill_zero(void *pointer, size_t size)
{
	char	*bytes;

	bytes = (char *) pointer;
	while ((size_t)((void *) bytes - pointer) < size)
		*bytes++ = 0;
}

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
