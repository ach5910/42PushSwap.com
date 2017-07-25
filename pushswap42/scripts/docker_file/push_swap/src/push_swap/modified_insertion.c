/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_insertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:48:41 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 15:11:52 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** sort_three will sort stack a and assign the max and min values to the stack.
*/

static int	sort_three(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
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
			return ((execute_command(clst, stack, si, SA)) == FALSE ?
					FALSE : TRUE);
		else
			return ((execute_command(clst, stack, si, SS)) == FALSE ?
					FALSE : TRUE);
	}
	return (TRUE);
}

static int	initialize_b(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
{
	si->stflag = -1;
	if ((execute_command(clst, stack, si, PB)) == FALSE)
		return (FALSE);
	if ((execute_command(clst, stack, si, PB)) == FALSE)
		return (FALSE);
	if (((int*)B.arr)[0] > ((int*)B.arr)[1])
	{
		si->max_i = 0;
		si->min_i = 1;
	}
	else
	{
		si->max_i = 1;
		si->min_i = 0;
	}
	si->max = ((int*)B.arr)[si->max_i];
	si->min = ((int*)B.arr)[si->min_i];
	si->stflag = 1;
	return (TRUE);
}

static int	push_a_to_b(t_stacks *stack, t_cmdlst *clst, size_t remainder,
		t_stackinfo *si)
{
	t_rotcnt	count;

	if (A.len > 4)
		if ((initialize_b(stack, si, clst)) == FALSE)
			return (FALSE);
	while (A.len > 3)
	{
		if (A.len > remainder)
		{
			choose_insertion(stack, si, &count);
			if ((rotate_stacks(stack, clst, &count, si)) == FALSE)
				return (FALSE);
		}
		if ((execute_command(clst, stack, si, PB)) == FALSE)
			return (FALSE);
	}
	si->stflag = 0;
	return (TRUE);
}

int			insertion(t_stacks *stack, t_cmdlst *clst, size_t remainder)
{
	t_stackinfo	si;
	t_rotcnt	count;
	int			last_rotation;

	if ((push_a_to_b(stack, clst, remainder, &si)) == FALSE)
		return (FALSE);
	if (A.len > 2)
		if ((sort_three(stack, &si, clst)) == FALSE)
			return (FALSE);
	while (A.len < A.total)
	{
		choose_insertion(stack, &si, &count);
		if ((rotate_stacks(stack, clst, &count, &si)) == FALSE)
			return (FALSE);
		if ((execute_command(clst, stack, &si, PA)) == FALSE)
			return (FALSE);
	}
	if (si.min_i < A.len / 2)
		last_rotation = RRA;
	else
		last_rotation = RA;
	while (!(check_stack(&A, 0, A.len - 1, 0)))
		if ((execute_command(clst, stack, &si, last_rotation)) == FALSE)
			return (FALSE);
	return (TRUE);
}
