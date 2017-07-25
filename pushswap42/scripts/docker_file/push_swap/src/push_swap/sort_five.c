/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:09:33 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 17:51:39 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sort_three will sort stack a and assign the max and min values to the stack.
*/

static void	sort_three(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
{
	size_t	i;

	si->max = ps_max(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	si->min = ps_min(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	i = A.len - 3;
	while (i < A.len)
	{
		if (((int*)A.arr)[i] == si->max)
			si->max_i = i;
		else if (((int*)A.arr)[i] == si->min)
			si->min_i = i;
		i++;
	}
	if ((si->max_i == 2 && si->min_i == 0) || si->max_i == (si->min_i - 1))
	{
		if (B.len > 1 && ((int*)B.arr)[B.len - 1] > ((int*)B.arr)[B.len - 2])
			execute_command(clst, stack, si, SA);
		else
			execute_command(clst, stack, si, SS);
	}
}
