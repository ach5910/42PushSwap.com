/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:25:17 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/09 16:59:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ps_max(int n1, int n2, int n3)
{
	if (n1 > n2 && n1 > n3)
		return (n1);
	else if (n2 > n3)
		return (n2);
	return (n3);
}

int	ps_min(int n1, int n2, int n3)
{
	if (n1 < n2 && n1 < n3)
		return (n1);
	else if (n2 < n3)
		return (n2);
	return (n3);
}
