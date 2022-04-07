/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_repeat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:44:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_repeat)
{
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 0), "");
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 0), "");
	}
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 1), "");
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 1), "foo");
	}
	{
		m_safe_string_assert(ft_str_repeat(strdup(""), 2), "");
		m_safe_string_assert(ft_str_repeat(strdup("foo"), 2), "foofoo");
	}
}

////////////////////////////////////////////////////////////////////////////////
