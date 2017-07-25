/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:29:23 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:38:20 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

void	parse_flags(int arc, char **arv, t_cflags *flags)
{
	int	offset;

	offset = 1;
	if (arc > 1)
	{
		if (ft_strequ(arv[1], "-v") == 1)
			flags->v = 1;
		else if (ft_strequ(arv[1], "-n") == 1)
			flags->n = 1;
		if (flags->n || flags->v)
			offset += 1;
	}
	if (arc > 2)
	{
		if (flags->v == 0 && ft_strequ(arv[2], "-v") == 1)
			flags->v = 1;
		else if (flags->n == 0 && ft_strequ(arv[2], "-n") == 1)
			flags->n = 1;
		if (flags->n && flags->v)
			offset += 1;
	}
	flags->argc = arc - offset;
	flags->argv = arv + offset;
}

int		main(int argc, char **argv)
{
	t_commands	cmd[11];
	t_stacks	stack;
	t_cflags	flags;
	int			ret;

	if (argc < 2)
		return (0);
	ret = 0;
	ft_bzero((void*)&stack, sizeof(stack));
	ft_bzero((void*)&flags, sizeof(flags));
	initialize_commands(cmd);
	parse_flags(argc, argv, &flags);
	ret = checker(&stack, cmd, &flags);
	if (ret == 0)
		ft_putendl("KO");
	else if (ret == 1)
		ft_putendl("OK");
	if (flags.n && ret == 1)
		ft_printf("Total commands executed: %d\n", flags.count);
	return (0);
}
