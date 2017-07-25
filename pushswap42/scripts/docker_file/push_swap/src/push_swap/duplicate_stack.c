/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:33:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/02 14:05:25 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_stacks	*duplicate_stack(t_stacks *src)
{
	t_stacks *ret;

	if (!(ret = (t_stacks*)ft_memalloc(sizeof(t_stacks))))
		return (NULL);
	if (!(ft_initialize_vec(&ret->a, src->a.size, src->a.total, src->a.len)))
	{
		ft_memdel((void*)&ret);
		return (NULL);
	}
	if (!(ft_initialize_vec(&ret->b, src->b.size, src->b.total, src->b.len)))
	{
		ft_memdel((void*)&ret->a);
		ft_memdel((void*)&ret);
		return (NULL);
	}
	ft_memmove((void*)ret->a.arr, (void*)src->a.arr, src->a.len * src->a.size);
	ft_memmove((void*)ret->b.arr, (void*)src->b.arr, src->b.len * src->b.size);
	return (ret);
}
