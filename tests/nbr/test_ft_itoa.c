/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_itoa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 15:24:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:13:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_itoa)
{
	m_safe_string_assert_free(ft_itoa(42), "42", true);
	m_safe_string_assert_free(ft_itoa(-42), "-42", true);
	m_safe_string_assert_free(ft_itoa(0), "0", true);
	m_safe_string_assert_free(ft_itoa(-2147483648), "-2147483648", true);
}
