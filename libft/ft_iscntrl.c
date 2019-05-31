/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:32:13 by archid-           #+#    #+#             */
/*   Updated: 2019/04/07 09:44:00 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iscntrl(int c)
{
	return ((c >= 0x00 && c <= 0x07) ||
			(c >= 0x08 && c <= 0x0F) ||
			(c >= 0x10 && c <= 0x1F) ||
			(c == 0x7F));
}
