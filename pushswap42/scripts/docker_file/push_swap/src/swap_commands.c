/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:11:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/26 13:13:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** ps_s is the body function for swapping the top two values..
*/

void	ps_s(t_vec *a)
{
	int	*top;

	if (a->len < 2)
		return ;
	top = (int*)a->arr + a->len - 1;
	ft_xorswapi(top, top - 1);
}

/*
**  Swaps the top two values of stack a
*/

void	ps_sa(t_vec *a, t_vec *b)
{
	(void)b;
	ps_s(a);
}

/*
**  Swaps the top two values of stack b
*/

void	ps_sb(t_vec *a, t_vec *b)
{
	(void)a;
	ps_s(b);
}

/*
** Swaps the top two values of stack a and b
*/

void	ps_ss(t_vec *a, t_vec *b)
{
	ps_s(a);
	ps_s(b);
}
