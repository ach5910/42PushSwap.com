/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:48:14 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:39:40 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** double_check checks the array to ensure that there are no duplicate values.
*/

static int	double_check(int *array, int value, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (array[i] == value)
			return (0);
		i++;
	}
	return (1);
}

/*
** load_stack loads the stack for a, it also checks that all input is valid
** (i.e. valid int and not a duplicate value)
*/

static int	load_stack(t_vec *a, char **argv)
{
	long	temp;
	int		i;
	int		j;

	i = a->len - 1;
	while (i >= 0)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		temp = ft_atol(argv[i]);
		if (temp > FT_S32_MAX || temp < FT_S32_MIN)
			return (0);
		j = a->len - (i + 1);
		((int*)a->arr)[j] = (int)temp;
		if (!(double_check((int*)a->arr, (int)temp, j)))
			return (0);
		i--;
	}
	return (1);
}

/*
** load_data is responsible for loading the arguments into the
** perspective stacks as well as check for input error.
** If there is only one argument, split the argument into substrings
** delimited by spaces.
*/

int			load_data(t_stacks *stack, int argc, char **argv)
{
	char	**altv;

	altv = NULL;
	if (argc == 1)
	{
		if (!(altv = ft_strsplit(argv[0], ' ')))
			return (cleanup(0, &stack->a, &stack->b, altv));
		argc = 0;
		while (altv[argc])
			argc++;
	}
	if (argc == 0)
		return (cleanup(-2, &stack->a, &stack->b, altv));
	if (!(ft_initialize_vec(&stack->a, sizeof(int), argc, argc)))
		return (cleanup(0, &stack->a, &stack->b, altv));
	if (!(ft_initialize_vec(&stack->b, sizeof(int), argc, 0)))
		return (cleanup(0, &stack->a, &stack->b, altv));
	if (argv)
		if (!(load_stack(&stack->a, (altv ? altv : argv))))
			return (cleanup(0, &stack->a, &stack->b, altv));
	return (cleanup(1, NULL, NULL, altv));
}
