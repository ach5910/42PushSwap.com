/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:39 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:41:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	shift_min_max(t_stackinfo *si, t_vec *stack, int command, int sf)
{
	if (command == SA + sf || command == SS)
	{
		if (si->max_i == stack->len - 1 || si->max_i == stack->len - 2)
			si->max_i += (si->max_i == stack->len - 1 ? -1 : 1);
		if (si->min_i == stack->len - 1 || si->min_i == stack->len - 2)
			si->min_i += (si->min_i == stack->len - 1 ? -1 : 1);
	}
	else if (command == PA + sf && ((int*)stack->arr)[stack->len - 1] > si->max)
	{
		si->max = ((int*)stack->arr)[stack->len - 1];
		si->max_i = stack->len - 1;
	}
	else if (command == PA + sf && ((int*)stack->arr)[stack->len - 1] < si->min)
	{
		si->min = ((int*)stack->arr)[stack->len - 1];
		si->min_i = stack->len - 1;
	}
	if (command == RA + sf || command == RR)
		si->max_i = (si->max_i == stack->len - 1 ? 0 : si->max_i + 1);
	if (command == RA + sf || command == RR)
		si->min_i = (si->min_i == stack->len - 1 ? 0 : si->min_i + 1);
	if (command == RRA + sf || command == RRR)
		si->max_i = (si->max_i == 0 ? stack->len : si->max_i) - 1;
	if (command == RRA + sf || command == RRR)
		si->min_i = (si->min_i == 0 ? stack->len : si->min_i) - 1;
}

static int	append_command(t_cmdlst *clst, int command)
{
	size_t	cmnd_len;
	char	*dst;

	cmnd_len = ft_strlen(clst->cmd[command].name) + 1;
	if (!(clst->result.arr))
	{
		if ((ft_initialize_vec(&clst->result, sizeof(char),
						BUFF_SIZE, 0)) == FALSE)
		{
			return (FALSE);
		}
	}
	if ((ft_grow_vec(&clst->result, clst->result.len + cmnd_len + 1)) == FALSE)
		return (FALSE);
	dst = (char*)(clst->result.arr + clst->result.len);
	ft_strcpy(dst, clst->cmd[command].name);
	dst[cmnd_len - 1] = '\n';
	clst->result.len += cmnd_len;
	return (TRUE);
}

int			execute_command(t_cmdlst *clst, t_stacks *stack,
			t_stackinfo *si, int command)
{
	clst->cmd[command].swap(&A, &B);
	if (clst->print)
		if ((append_command(clst, command)) == FALSE)
			return (FALSE);
	if (si->stflag == 0)
		shift_min_max(si, &A, command, si->stflag);
	else if (si->stflag == 1)
		shift_min_max(si, &B, command, si->stflag);
	clst->count++;
	return (TRUE);
}
