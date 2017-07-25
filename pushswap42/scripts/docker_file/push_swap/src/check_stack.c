/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:17:06 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:37:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** check_stack will check to make sure that stack a has been sorted after
** it went through all of the instructions.
*/

int	check_stack(t_vec *a, size_t start, size_t end, int sflag)
{
	size_t	i;
	size_t	limit;
	int		*array;

	i = end;
	limit = start + 1;
	array = (int*)a->arr;
	while (i >= limit)
	{
		if (sflag == FALSE && array[i] >= array[i - 1])
			return (FALSE);
		i -= 1;
	}
	return (TRUE);
}
