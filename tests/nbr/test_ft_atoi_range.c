/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_range.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:30:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/21 18:07:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_atoi_range)
{
	{
		{
			bool out_of_range = true;
			massert(ft_atoi_range("-12345", &out_of_range), atoi("-12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("+12345", &out_of_range), atoi("+12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range(".12345", &out_of_range), atoi(".12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("a12345", &out_of_range), atoi("a12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range(" 12345 ", &out_of_range), atoi(" 12345 "));
			massert(out_of_range, false);
		}
	}

	{
		{
			bool out_of_range = true;
			massert(ft_atoi_range("- 12345", &out_of_range), atoi("- 12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("+ 12345", &out_of_range), atoi("+ 12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range(". 12345", &out_of_range), atoi(". 12345"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("a 12345", &out_of_range), atoi("a 12345"));
			massert(out_of_range, false);
		}
	}

	{
		{
			bool out_of_range = true;
			massert(ft_atoi_range("123-45", &out_of_range), atoi("123-45"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("123+45", &out_of_range), atoi("123+45"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("123.45", &out_of_range), atoi("123.45"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("123a45", &out_of_range), atoi("123a45"));
			massert(out_of_range, false);
		}
	}

	{
		{
			bool out_of_range = true;
			massert(ft_atoi_range("12345-", &out_of_range), atoi("12345-"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("12345+", &out_of_range), atoi("12345+"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("12345.", &out_of_range), atoi("12345."));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("12345a", &out_of_range), atoi("12345a"));
			massert(out_of_range, false);
		}
	}

	{
		{
			bool out_of_range = true;
			massert(ft_atoi_range("2147483647", &out_of_range), atoi("2147483647"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = false;
			massert(ft_atoi_range("2147483648", &out_of_range), atoi("2147483648"));
			massert(out_of_range, true);
		}

		{
			bool out_of_range = true;
			massert(ft_atoi_range("-2147483648", &out_of_range), atoi("-2147483648"));
			massert(out_of_range, false);
		}

		{
			bool out_of_range = false;
			massert(ft_atoi_range("-2147483649", &out_of_range), atoi("-2147483649"));
			massert(out_of_range, true);
		}
	}
}
