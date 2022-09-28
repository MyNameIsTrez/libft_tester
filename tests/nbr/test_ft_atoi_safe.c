/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_safe.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:30:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/09/01 14:40:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_atoi_safe)
{
	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("-12345", &nbr), true);
			massert(nbr, -12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("+12345", &nbr), true);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(".12345", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("a12345", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(" 12345 ", &nbr), true);
			massert(nbr, 12345);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("- 12345", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("+ 12345", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(". 12345", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("a 12345", &nbr), false);
			massert(nbr, 420);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("123-45", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123+45", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123.45", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123a45", &nbr), false);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345-", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345+", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345.", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345a", &nbr), false);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("2147483647", &nbr), true);
			massert(nbr, 2147483647);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("2147483648", &nbr), false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("-2147483648", &nbr), true);
			massert(nbr, (int)-2147483648);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("-2147483649", &nbr), false);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
