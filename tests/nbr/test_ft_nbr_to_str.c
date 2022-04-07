/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_nbr_to_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:56:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_nbr_to_str)
{
	m_safe_string_assert(ft_nbr_to_str(42, 10), "42");
	m_safe_string_assert(ft_nbr_to_str(-42, 10), "-42");
	m_safe_string_assert(ft_nbr_to_str(0, 10), "0");
	m_safe_string_assert(ft_nbr_to_str(-2147483648, 10), "-2147483648");

	m_safe_string_assert(ft_nbr_to_str(9, 10), "9");
	m_safe_string_assert(ft_nbr_to_str(10, 10), "10");
	m_safe_string_assert(ft_nbr_to_str(-9, 10), "-9");
	m_safe_string_assert(ft_nbr_to_str(-10, 10), "-10");

	m_safe_string_assert(ft_nbr_to_str(15, 16), "f");
	m_safe_string_assert(ft_nbr_to_str(-15, 16), "-f");
	m_safe_string_assert(ft_nbr_to_str(16, 16), "10");
	m_safe_string_assert(ft_nbr_to_str(-16, 16), "-10");
}

////////////////////////////////////////////////////////////////////////////////
