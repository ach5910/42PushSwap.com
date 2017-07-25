/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:18:36 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 15:23:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Main body for shift down function.
** Moves the array two elements at a time (except for the first element
** if the array has an odd number of elements).
*/

void	ps_dr(t_vec *a)
{
	long	*m2src;
	long	*m2dst;
	int		offset;
	int		size;
	int		tmp;

	size = a->len - 1;
	offset = size % 2;
	tmp = *(int*)a->arr;
	m2src = (long*)((int*)a->arr + 1 + offset);
	m2dst = (long*)((int*)a->arr + offset);
	if (offset)
		*(int*)a->arr = *((int*)a->arr + 1);
	offset = size / 2;
	while (offset-- > 0)
		*m2dst++ = *m2src++;
	((int*)a->arr)[size] = tmp;
}

void	ps_rra(t_vec *a, t_vec *b)
{
	if (a->len > 1)
		ps_dr(a);
	(void)b;
}

void	ps_rrb(t_vec *a, t_vec *b)
{
	if (b->len > 1)
		ps_dr(b);
	(void)a;
}

void	ps_rrr(t_vec *a, t_vec *b)
{
	ps_dr(a);
	ps_dr(b);
}
