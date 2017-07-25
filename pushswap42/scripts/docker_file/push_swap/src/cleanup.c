/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:21:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/04 13:39:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** cleanup is responsible for freeing all allocations made and returning the
** result to main.
*/

int	cleanup(int ret, t_vec *a, t_vec *b, char **argv)
{
	size_t	i;

	if (a && a->arr)
		ft_memdel(&a->arr);
	if (b && b->arr)
		ft_memdel(&b->arr);
	i = 0;
	if (argv)
	{
		while (argv[i])
			ft_memdel((void*)&argv[i++]);
		ft_memdel((void*)&argv);
	}
	if (ret == -1)
		ft_putendl_fd("Error", 2);
	return (ret);
}
