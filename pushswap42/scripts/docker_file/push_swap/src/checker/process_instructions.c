/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:17:11 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:38:52 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

/*
** The following functions are used for reading the commands given, and applying
** the commands to the stacks for both a and b. Will return 0 if there is an
** invalid instruction given.
*/

static int	command_dispatcher(t_stacks *stack, t_commands *clst, char *cmd,
		t_cflags *flags)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!(ft_strcmp(clst[i].name, cmd)))
		{
			clst[i].swap(&stack->a, &stack->b);
			flags->count++;
			if (flags->v)
				print_stack(stack, cmd);
			return (1);
		}
		i++;
	}
	return (0);
}

int			process_instructions(t_stacks *stack, char **commands,
		t_commands *clst, t_cflags *f)
{
	int		i;

	i = 0;
	while (commands[i])
	{
		if (!(command_dispatcher(stack, clst, commands[i], f)))
			return (0);
		i++;
	}
	return (1);
}
