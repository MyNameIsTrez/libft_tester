/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_repeat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:44:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:47:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

#define m_safe_repeat_string_assert_free(str, rep, expected)\
{\
	char	*str_local = str;\
	m_safe_string_assert_free(ft_str_repeat(str_local, rep), expected, true);\
	free(str_local);\
}

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_repeat)
{
	{
		m_safe_repeat_string_assert_free(strdup(""), 0, "");
		m_safe_repeat_string_assert_free(strdup("foo"), 0, "");
	}
	{
		m_safe_repeat_string_assert_free(strdup(""), 1, "");
		m_safe_repeat_string_assert_free(strdup("foo"), 1, "foo");
	}
	{
		m_safe_repeat_string_assert_free(strdup(""), 2, "");
		m_safe_repeat_string_assert_free(strdup("foo"), 2, "foofoo");
	}
}

////////////////////////////////////////////////////////////////////////////////
