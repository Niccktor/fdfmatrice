/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:10:28 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/19 16:21:34 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int			ft_atoi_base(char *str, int base)
{
	int result;
	int sign;

	result = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r'
			|| *str == '\t' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'A' >= 0)
			result = result * base + (*str - 'A' + 10);
		else
			result = result * base + (*str - '0');
		str++;
	}
	return (result * sign);
}
