/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_repeat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:44:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/06 16:22:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_repeat)
{
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 0), "", true);
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 0), "", true);
	}
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 1), "", true);
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 1), "foo", true);
	}
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 2), "", true);
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 2), "foofoo", true);
	}
}

////////////////////////////////////////////////////////////////////////////////
