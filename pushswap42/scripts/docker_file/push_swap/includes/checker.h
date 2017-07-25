/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:30:01 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 19:39:11 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <push_swap.h>

typedef	struct	s_checker_flags
{
	int			argc;
	char		**argv;
	int			count;
	char		n;
	char		v;
}				t_cflags;

int				checker(t_stacks *stack, t_commands *clst, t_cflags *flags);
int				process_instructions(t_stacks *stack, char **commands,
				t_commands *clst, t_cflags *flags);
void			print_stack(t_stacks *stack, char *command);

#endif
