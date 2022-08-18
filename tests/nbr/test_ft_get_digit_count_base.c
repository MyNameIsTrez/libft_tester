/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_get_digit_count_base.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:20:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 14:05:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_get_digit_count_base)
{
	massert(ft_get_digit_count_base(0, 2), (size_t)1);
	massert(ft_get_digit_count_base(0, 10), (size_t)1);
	{
		massert(ft_get_digit_count_base(1, 2), (size_t)1);
		massert(ft_get_digit_count_base(46, 2), (size_t)6);
		massert(ft_get_digit_count_base(1, 10), (size_t)1);
		massert(ft_get_digit_count_base(123, 10), (size_t)3);
		massert(ft_get_digit_count_base(1, 16), (size_t)1);
		massert(ft_get_digit_count_base(0x123, 16), (size_t)3);
	}
	{
		massert(ft_get_digit_count_base(-1, 2), (size_t)1);
		massert(ft_get_digit_count_base(-46, 2), (size_t)6);
		massert(ft_get_digit_count_base(-1, 10), (size_t)1);
		massert(ft_get_digit_count_base(-123, 10), (size_t)3);
		massert(ft_get_digit_count_base(-1, 16), (size_t)1);
		massert(ft_get_digit_count_base(-0x123, 16), (size_t)3);
	}
}

////////////////////////////////////////////////////////////////////////////////
