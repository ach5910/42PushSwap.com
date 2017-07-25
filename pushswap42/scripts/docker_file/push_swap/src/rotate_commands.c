/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:16:37 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/09 16:43:15 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** Main body for the shift up function
*/

void	ps_r(t_vec *a)
{
	long	*m2src;
	long	*m2dst;
	int		lindex;
	int		size;
	int		tmp;

	size = a->len - 1;
	m2src = (long*)a->arr;
	m2dst = (long*)((int*)a->arr + 1);
	tmp = *((int*)a->arr + size);
	lindex = size / 2;
	if (size % 2)
		((int*)a->arr)[size] = ((int*)a->arr)[size - 1];
	while (lindex-- > 0)
		m2dst[lindex] = m2src[lindex];
	*(int*)a->arr = tmp;
}

void	ps_ra(t_vec *a, t_vec *b)
{
	(void)b;
	if (a->len > 1)
		ps_r(a);
}

void	ps_rb(t_vec *a, t_vec *b)
{
	(void)a;
	if (b->len > 1)
		ps_r(b);
}

void	ps_rr(t_vec *a, t_vec *b)
{
	ps_r(a);
	ps_r(b);
}
