/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_unsigned_nbr_to_str.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 15:58:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/25 17:17:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_unsigned_nbr_to_str)
{
	#ifndef linux
	m_safe_string_assert(ft_unsigned_nbr_to_str((uintmax_t)-42, 10), "18446744073709551574");
	#endif
	m_safe_string_assert(ft_unsigned_nbr_to_str(42, 10), "42");
}

////////////////////////////////////////////////////////////////////////////////
