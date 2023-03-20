/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_unsigned_nbr_to_str.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 15:58:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:54:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_unsigned_nbr_to_str)
{
	#ifndef linux
	m_safe_string_assert_free(ft_unsigned_nbr_to_str((uintmax_t)-42, 10), "18446744073709551574", true);
	#endif

	m_safe_string_assert_free(ft_unsigned_nbr_to_str(42, 10), "42", true);
}
