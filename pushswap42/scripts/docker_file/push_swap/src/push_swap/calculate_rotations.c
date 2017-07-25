/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:31:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 15:12:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Calculate the number of rotations needed to access ai and bi.
*/

static int	calculate_rotations(t_rotcnt *cnt, size_t ai, size_t bi,
		t_stacks *stack)
{
	cnt->ra = A.len - 1 - ai;
	cnt->rb = B.len - 1 - bi;
	cnt->rr = (cnt->ra < cnt->rb ? cnt->ra : cnt->rb);
	cnt->rra = ai + 1;
	cnt->rrb = bi + 1;
	cnt->rrr = (cnt->rra < cnt->rrb ? cnt->rra : cnt->rrb);
	cnt->ttl_rot = ps_min(cnt->ra + cnt->rrb, cnt->rb + cnt->rra,
			cnt->ra + cnt->rb - cnt->rr);
	if (cnt->ttl_rot > cnt->rra + cnt->rrb - cnt->rrr)
		cnt->ttl_rot = cnt->rra + cnt->rrb - cnt->rrr;
	cnt->rr = (cnt->ttl_rot != cnt->ra + cnt->rb - cnt->rr ? -1 : cnt->rr);
	cnt->rrr = (cnt->ttl_rot != cnt->rra + cnt->rrb - cnt->rrr ? -1 : cnt->rrr);
	cnt->ra = ((cnt->ttl_rot != cnt->ra + cnt->rrb && cnt->rr == -1) ||
			cnt->rrr != -1 ? 0 : cnt->ra);
	cnt->rb = ((cnt->ttl_rot != cnt->rb + cnt->rra && cnt->rr == -1) ||
			cnt->rrr != -1 ? 0 : cnt->rb);
	cnt->rrb = ((cnt->ttl_rot != cnt->ra + cnt->rrb && cnt->rrr == -1) ||
			cnt->rb != 0 ? 0 : cnt->rrb);
	cnt->rra = ((cnt->ttl_rot != cnt->rb + cnt->rra && cnt->rrr == -1) ||
			cnt->ra != 0 ? 0 : cnt->rra);
	cnt->ra -= (cnt->rr == -1 ? 0 : cnt->rr);
	cnt->rb -= (cnt->rr == -1 ? 0 : cnt->rr);
	cnt->rra -= (cnt->rrr == -1 ? 0 : cnt->rrr);
	cnt->rrb -= (cnt->rrr == -1 ? 0 : cnt->rrr);
	return (cnt->ttl_rot);
}

/*
** rotation_count_a and rotation_count_b will calculate the position of the
** insertion point for the given insert. They then use calculate rotation to
** caluclate the mininum number of rotations needed to access both the insert
** and the insertion position. Seperate functions because A and B should be
** sorted anti-parallel to each other.
*/

static int	rotation_count_a(t_stacks *stack, t_stackinfo *si, t_rotcnt *cnt,
			size_t insert_index)
{
	size_t			i;
	int				insert_value;
	int				rot_count;

	insert_value = ((int*)B.arr)[insert_index];
	if (insert_value > si->max || insert_value < si->min)
		i = (si->max_i == 0 ? A.len : si->max_i) - 1;
	else
	{
		i = A.len - 1;
		if (!(insert_value < ((int*)A.arr)[i] &&
			insert_value > ((int*)A.arr)[0]))
		{
			i--;
			while (!(insert_value > ((int*)A.arr)[i + 1] &&
						insert_value < ((int*)A.arr)[i]))
				i--;
		}
	}
	rot_count = calculate_rotations(cnt, i, insert_index, stack);
	return (rot_count);
}

static int	rotation_count_b(t_stacks *stack, t_stackinfo *si, t_rotcnt *cnt,
			size_t insert_index)
{
	size_t			i;
	int				insert_value;
	int				rot_count;

	insert_value = ((int*)A.arr)[insert_index];
	if (insert_value > si->max || insert_value < si->min)
		i = (si->min_i == 0 ? B.len : si->min_i) - 1;
	else
	{
		i = B.len - 1;
		if (!(insert_value > ((int*)B.arr)[i] &&
			insert_value < ((int*)B.arr)[0]))
		{
			i--;
			while (!(insert_value < ((int*)B.arr)[i + 1] &&
						insert_value > ((int*)B.arr)[i]))
				i--;
		}
	}
	rot_count = calculate_rotations(cnt, insert_index, i, stack);
	return (rot_count);
}

/*
** Choose the insert index in the stack you are pushing from that requires the
** least number of rotations to place into its corresponding location in the
** receiving stack.
*/

int			choose_insertion(t_stacks *stack, t_stackinfo *si,
		t_rotcnt *cnt)
{
	t_rotcnt	trot;
	long long	i;
	int			ttl_rotations;
	int			temp_count;

	i = (si->stflag == 0 ? B.len : A.len) - 1;
	ttl_rotations = (si->stflag == 0 ? A.total : B.total);
	ft_bzero((void*)&trot, sizeof(trot));
	while (i >= 0)
	{
		if (si->stflag == 0)
			temp_count = rotation_count_a(stack, si, &trot, i);
		else
			temp_count = rotation_count_b(stack, si, &trot, i);
		if (temp_count < ttl_rotations)
		{
			ttl_rotations = temp_count;
			ft_memmove((void*)cnt, (void*)&trot, sizeof(trot));
		}
		i--;
	}
	return (temp_count);
}
