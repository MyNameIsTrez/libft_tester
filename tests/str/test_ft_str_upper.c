/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_upper.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:56:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:01:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_upper)
{
	m_safe_string_assert_free(ft_str_upper(strdup("")), "", true);
	m_safe_string_assert_free(ft_str_upper(strdup("foo")), "FOO", true);
	m_safe_string_assert_free(ft_str_upper(strdup("BAR")), "BAR", true);
	m_safe_string_assert_free(ft_str_upper(strdup("$")), "$", true);
}

////////////////////////////////////////////////////////////////////////////////
