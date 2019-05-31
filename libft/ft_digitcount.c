/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 05:22:36 by archid-           #+#    #+#             */
/*   Updated: 2019/04/07 06:58:54 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_byte	ft_digitcount(int n)
{
	t_byte count;
	t_uint u;

	if (n == 0)
		return (1);
	u = (n < 0) ? -n : n;
	count = 1 + (n < 0);
	while (u / 10)
	{
		u /= 10;
		count++;
	}
	return (count);
}