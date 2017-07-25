/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:37:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/02 16:17:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** initalize_commands takes a command list and assigns a name for the command
** along with a corresponding function pointer
*/

void	initialize_commands(t_commands *list)
{
	ft_strncpy(list[SA].name, "sa", sizeof(list[SA].name));
	ft_strncpy(list[SB].name, "sb", sizeof(list[SB].name));
	ft_strncpy(list[SS].name, "ss", sizeof(list[SS].name));
	ft_strncpy(list[PA].name, "pa", sizeof(list[PA].name));
	ft_strncpy(list[PB].name, "pb", sizeof(list[PB].name));
	ft_strncpy(list[RA].name, "ra", sizeof(list[RA].name));
	ft_strncpy(list[RB].name, "rb", sizeof(list[RB].name));
	ft_strncpy(list[RR].name, "rr", sizeof(list[RR].name));
	ft_strncpy(list[RRA].name, "rra", sizeof(list[RRA].name));
	ft_strncpy(list[RRB].name, "rrb", sizeof(list[RRB].name));
	ft_strncpy(list[RRR].name, "rrr", sizeof(list[RRR].name));
	list[SA].swap = ps_sa;
	list[SB].swap = ps_sb;
	list[SS].swap = ps_ss;
	list[PA].swap = ps_pa;
	list[PB].swap = ps_pb;
	list[RA].swap = ps_ra;
	list[RB].swap = ps_rb;
	list[RR].swap = ps_rr;
	list[RRA].swap = ps_rra;
	list[RRB].swap = ps_rrb;
	list[RRR].swap = ps_rrr;
}
