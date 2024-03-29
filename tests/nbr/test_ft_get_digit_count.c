/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_get_digit_count.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 18:02:48 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_get_digit_count)
{
	massert(ft_get_digit_count_base(1, 10), (size_t)1);
	massert(ft_get_digit_count_base(123, 10), (size_t)3);
	massert(ft_get_digit_count_base(-1, 10), (size_t)1);
	massert(ft_get_digit_count_base(-123, 10), (size_t)3);
}
