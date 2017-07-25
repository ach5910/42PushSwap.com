/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:10:57 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:41:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	choose_remainder_size(t_stacks *stack, t_cmdlst *clst, int arc, char **arv)
{
	int	i;
	int	min_count;
	int	min_i;

	i = 4;
	min_i = 4;
	min_count = FT_S32_MAX;
	while (i < (int)(A.total / 2))
	{
		clst->count = 0;
		if ((load_data(stack, arc, arv)) == FALSE)
			return (cleanup(-1, &A, &B, NULL));
		if ((insertion(stack, clst, i)) == FALSE)
			return (cleanup(-1, &A, &B, NULL));
		cleanup(0, &A, &B, NULL);
		if (clst->count < min_count)
		{
			min_count = clst->count;
			min_i = i;
		}
		i *= 2;
	}
	clst->count = 0;
	clst->print = 1;
	return (min_i);
}

int	main(int argc, char **argv)
{
	t_cmdlst	clst;
	t_stacks	raw_stack;
	int			remain_a;

	ft_bzero((void*)&raw_stack, sizeof(raw_stack));
	ft_bzero((void*)&clst, sizeof(clst));
	initialize_commands(clst.cmd);
	if (!(remain_a = load_data(&raw_stack, argc - 1, argv + 1)))
		return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
	if (argc < 2 || remain_a < 0)
		return (0);
	if ((check_stack(&raw_stack.a, 0, raw_stack.a.len - 1, 0)))
		return (cleanup(0, &raw_stack.a, &raw_stack.b, NULL));
	cleanup(0, &raw_stack.a, &raw_stack.b, NULL);
	remain_a = choose_remainder_size(&raw_stack, &clst, argc - 1, argv + 1);
	if (remain_a < 0)
		return (-1);
	if (!(load_data(&raw_stack, argc - 1, argv + 1)))
		return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
	if ((insertion(&raw_stack, &clst, remain_a)) == TRUE)
		ft_putstr((char *)clst.result.arr);
	else
		ft_putendl_fd("Error", 2);
	ft_memdel(&clst.result.arr);
	return (cleanup(0, &raw_stack.a, &raw_stack.b, NULL));
}
