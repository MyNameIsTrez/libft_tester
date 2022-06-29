/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_safe.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:30:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 12:31:22 by sbos          ########   odam.nl         */
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
			massert_success(ft_atoi_safe("-12345", &nbr), OK);
			massert(nbr, -12345);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("+12345", &nbr), OK);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe(".12345", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("a12345", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe(" 12345 ", &nbr), OK);
			massert(nbr, 12345);
		}
	}

	{
		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("- 12345", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("+ 12345", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe(". 12345", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("a 12345", &nbr), ERROR);
			massert(nbr, 420);
		}
	}

	{
		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("123-45", &nbr), OK);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("123+45", &nbr), OK);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("123.45", &nbr), OK);
			massert(nbr, 123);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("123a45", &nbr), OK);
			massert(nbr, 123);
		}
	}

	{
		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("12345-", &nbr), OK);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("12345+", &nbr), OK);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("12345.", &nbr), OK);
			massert(nbr, 12345);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("12345a", &nbr), OK);
			massert(nbr, 12345);
		}
	}

	{
		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("2147483647", &nbr), OK);
			massert(nbr, 2147483647);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("2147483648", &nbr), ERROR);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("-2147483648", &nbr), OK);
			massert(nbr, (int)-2147483648);
		}

		{
			int	nbr = 420;
			massert_success(ft_atoi_safe("-2147483649", &nbr), ERROR);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
