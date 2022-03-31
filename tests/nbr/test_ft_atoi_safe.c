/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_safe.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:30:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/31 17:54:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_atoi_safe)
{
	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("-12345", &nbr), (bool)true);
			massert(nbr, -12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("+12345", &nbr), (bool)true);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(".12345", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("a12345", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(" 12345 ", &nbr), (bool)true);
			massert(nbr, 12345);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("- 12345", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("+ 12345", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe(". 12345", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("a 12345", &nbr), (bool)false);
			massert(nbr, 420);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("123-45", &nbr), (bool)true);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123+45", &nbr), (bool)true);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123.45", &nbr), (bool)true);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("123a45", &nbr), (bool)true);
			massert(nbr, 123);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345-", &nbr), (bool)true);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345+", &nbr), (bool)true);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345.", &nbr), (bool)true);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("12345a", &nbr), (bool)true);
			massert(nbr, 12345);
		}
	}

	{
		{
			int	nbr = 420;
			massert(ft_atoi_safe("2147483647", &nbr), (bool)true);
			massert(nbr, 2147483647);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("2147483648", &nbr), (bool)false);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("-2147483648", &nbr), (bool)true);
			massert(nbr, (int)-2147483648);
		}

		{
			int	nbr = 420;
			massert(ft_atoi_safe("-2147483649", &nbr), (bool)false);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
