/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:04:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 14:48:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Rotate_stacks executes all the rotation commands queded in the rotcnt struct
*/

int	rotate_stacks(t_stacks *stack, t_cmdlst *clst, t_rotcnt *rot,
		t_stackinfo *si)
{
	while (rot->ra-- > 0)
		if ((execute_command(clst, stack, si, RA)) == FALSE)
			return (FALSE);
	while (rot->rb-- > 0)
		if ((execute_command(clst, stack, si, RB)) == FALSE)
			return (FALSE);
	while (rot->rr-- > 0)
		if ((execute_command(clst, stack, si, RR)) == FALSE)
			return (FALSE);
	while (rot->rra-- > 0)
		if ((execute_command(clst, stack, si, RRA)) == FALSE)
			return (FALSE);
	while (rot->rrb-- > 0)
		if ((execute_command(clst, stack, si, RRB)) == FALSE)
			return (FALSE);
	while (rot->rrr-- > 0)
		if ((execute_command(clst, stack, si, RRR)) == FALSE)
			return (FALSE);
	return (TRUE);
}
