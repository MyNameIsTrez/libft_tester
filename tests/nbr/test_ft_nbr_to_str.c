/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_nbr_to_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:56:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:13:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_nbr_to_str)
{
	m_safe_string_assert_free(ft_nbr_to_str(42, 10), "42", true);
	m_safe_string_assert_free(ft_nbr_to_str(-42, 10), "-42", true);
	m_safe_string_assert_free(ft_nbr_to_str(0, 10), "0", true);
	m_safe_string_assert_free(ft_nbr_to_str(-2147483648, 10), "-2147483648", true);

	m_safe_string_assert_free(ft_nbr_to_str(9, 10), "9", true);
	m_safe_string_assert_free(ft_nbr_to_str(10, 10), "10", true);
	m_safe_string_assert_free(ft_nbr_to_str(-9, 10), "-9", true);
	m_safe_string_assert_free(ft_nbr_to_str(-10, 10), "-10", true);

	m_safe_string_assert_free(ft_nbr_to_str(15, 16), "f", true);
	m_safe_string_assert_free(ft_nbr_to_str(-15, 16), "-f", true);
	m_safe_string_assert_free(ft_nbr_to_str(16, 16), "10", true);
	m_safe_string_assert_free(ft_nbr_to_str(-16, 16), "-10", true);
}

////////////////////////////////////////////////////////////////////////////////
