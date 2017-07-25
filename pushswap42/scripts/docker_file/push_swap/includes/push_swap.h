/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:01:53 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 19:50:33 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_vector.h>
# include <libft.h>

# define FALSE 0
# define TRUE 1
# define A stack->a
# define B stack->b
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef	struct	s_commands
{
	void		(*swap)(t_vec *, t_vec *);
	char		name[5];
}				t_commands;

typedef	struct	s_cmdlst
{
	t_commands	cmd[11];
	t_vec		result;
	int			count;
	int			print;
}				t_cmdlst;

typedef struct	s_stacks
{
	t_vec		a;
	t_vec		b;
}				t_stacks;

typedef struct	s_stackinfo
{
	size_t		max_i;
	size_t		min_i;
	int			max;
	int			min;
	int			stflag;
}				t_stackinfo;

typedef struct	s_rotationcount
{
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			ttl_rot;
}				t_rotcnt;

/*
** Min max functions
*/

int				ps_max(int n1, int n2, int n3);
int				ps_min(int n1, int n2, int n3);

/*
** Data loading and stack checking
*/

int				load_data(t_stacks *stack, int argc, char **argv);
int				check_stack(t_vec *a, size_t start, size_t end, int sflag);

/*
** Push_swap sorting functions
*/

int				insertion(t_stacks *stack, t_cmdlst *clst, size_t push_over);
int				choose_insertion(t_stacks *stack,
				t_stackinfo *si, t_rotcnt *cnt);
int				rotate_stacks(t_stacks *stack, t_cmdlst *clst,
				t_rotcnt *rot, t_stackinfo *si);
int				execute_command(t_cmdlst *clst, t_stacks *stack,
					t_stackinfo *si, int command);
/*
** command functions:
*/
void			initialize_commands(t_commands *list);
void			ps_sa(t_vec *a, t_vec *b);
void			ps_sb(t_vec *a, t_vec *b);
void			ps_ss(t_vec *a, t_vec *b);
void			ps_pa(t_vec *a, t_vec *b);
void			ps_pb(t_vec *a, t_vec *b);
void			ps_ra(t_vec *a, t_vec *b);
void			ps_rb(t_vec *a, t_vec *b);
void			ps_rr(t_vec *a, t_vec *b);
void			ps_rra(t_vec *a, t_vec *b);
void			ps_rrb(t_vec *a, t_vec *b);
void			ps_rrr(t_vec *a, t_vec *b);

/*
** cleanup functions:
*/
int				cleanup(int ret, t_vec *a, t_vec *b, char **argv);

#endif
