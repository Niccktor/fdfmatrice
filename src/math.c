/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:51:56 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/21 22:43:39 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9!
**	(fact + fact) * step * (step + step + 1);
**	(1 + 1) * 1 *(1 + 1 + 1); step = 1 fact = 6
** (6 + 6) * 2 * (2 + 2 + 1); step = 2 fact = 12
*/

static double	ft_taylor_sin(double x)
{
	int		step;
	double	fact;
	double	square_x;
	double	ret;

	square_x = x * x;
	step = 1;
	fact = 1;
	ret = x;
	while (step < 10)
	{
		fact = (step + step + 1) * step * (fact + fact);
		x = -x * square_x;
		ret = ret + x / fact;
		step++;
	}
	return (ret);
}

double			ft_sin(double x)
{
	int		sign;
	double	pi;

	pi = 3.14159265359;
	sign = 1;
	if (x < 0)
	{
		x = -x;
		sign = -1;
	}
	if (x == 0)
		return (x);
	else if (x == pi / 2)
		return (1);
	else if (x > pi / 2)
		x = pi - x;
	return (ft_taylor_sin(x) * sign);
}

static double	ft_taylor_cos(double x)
{
	int		step;
	double	fact;
	double	square_x;
	double	ret;

	square_x = x * x;
	x = 1;
	step = 1;
	fact = 1;
	ret = 1;
	while (step < 10)
	{
		fact = (fact + fact) * step * (step + step - 1);
		x = -x * square_x;
		ret = ret + x / fact;
		step++;
	}
	return (ret);
}

double			ft_cos(double x)
{
	int		sign;
	double	pi;

	pi = 3.14159265359;
	sign = 1;
	if (x < 0)
		x = -x;
	if (x == 0)
		return (1);
	else if (x == pi / 2)
		return (0);
	else if (x > pi / 2)
	{
		x = pi - x;
		sign = -1;
	}
	return (ft_taylor_cos(x) * sign);
}

double			ft_tan(double x)
{
	return (ft_sin(x) / ft_cos(x));
}
