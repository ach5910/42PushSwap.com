/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:49:17 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/23 15:47:38 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <unistd.h>

void	print_stack(t_stacks *stack, char *command)
{
	int		*a;
	int		*b;
	int		i;
	char	c;

	a = (int*)stack->a.arr;
	b = (int*)stack->b.arr;
	ft_printf("\033[2J\033[0mcommand: %s\n", command);
	ft_printf("a.len:%d b.len:%d\n", stack->a.len, stack->b.len);
	i = (stack->a.len > stack->b.len ? stack->a.len : stack->b.len) - 1;
	while (i >= 0)
	{
		if (i > (int)(stack->b.len - 1))
			ft_printf("%4d %4.d\n", a[i], 0);
		else if (i > (int)(stack->a.len - 1))
			ft_printf("%4.d %4d\n", 0, b[i]);
		else
			ft_printf("%4d %4d\n", a[i], b[i]);
		i--;
	}
	ft_printf("%4c %4c\n", '-', '-');
	ft_printf("%4c %4c\n", 'a', 'b');
	read(1, &c, 1);
}
