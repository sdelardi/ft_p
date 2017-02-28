/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:51:42 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/26 17:58:25 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(unsigned int power, int n)
{
	int cpy;

	cpy = n;
	while (power)
	{
		n = n * cpy;
		power--;
	}
	return (n);
}
