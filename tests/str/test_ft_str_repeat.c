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

#include "libft_tests.h"

#define m_safe_repeat_string_assert_free(str, rep, expected, description)\
{\
	char	*str_local = str;\
	m_safe_string_assert_free(ft_str_repeat(str_local, rep, description), expected, true);\
	free(str_local);\
}

Test(ft_str_repeat)
{
	{
		m_safe_repeat_string_assert_free(strdup(""), 0, "", "test ft_str_repeat 1");
		m_safe_repeat_string_assert_free(strdup("foo"), 0, "", "test ft_str_repeat 2");
	}
	{
		m_safe_repeat_string_assert_free(strdup(""), 1, "", "test ft_str_repeat 3");
		m_safe_repeat_string_assert_free(strdup("foo"), 1, "foo", "test ft_str_repeat 4");
	}
	{
		m_safe_repeat_string_assert_free(strdup(""), 2, "", "test ft_str_repeat 5");
		m_safe_repeat_string_assert_free(strdup("foo"), 2, "foofoo", "test ft_str_repeat 6");
	}
}
