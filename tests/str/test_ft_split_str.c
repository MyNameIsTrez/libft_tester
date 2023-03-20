/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_split_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 12:59:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:30:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_split_str)
{
	{
		char	*str = "AB1ABAB2AB3";
		char	*sep = "AB";
		char	**split_str;

		m_safe_assert(void *, split_str = ft_split_str(str, sep, "test ft_split_str 1"), split_str, NULL, true);
		if (split_str != NULL)
		{
			m_safe_string_assert(split_str[0], "", true);
			m_safe_string_assert(split_str[1], "1", true);
			m_safe_string_assert(split_str[2], "", true);
			m_safe_string_assert(split_str[3], "2", true);
			m_safe_string_assert(split_str[4], "3", true);
			massert((void *)split_str[5], NULL);
			ft_free_split(&split_str);
		}
	}

	{
		char	*str = "4ABABAB5AB6AB";
		char	*sep = "AB";
		char	**split_str;

		m_safe_assert(void *, split_str = ft_split_str(str, sep, "test ft_split_str 2"), split_str, NULL, true);
		if (split_str != NULL)
		{
			m_safe_string_assert(split_str[0], "4", true);
			m_safe_string_assert(split_str[1], "", true);
			m_safe_string_assert(split_str[2], "", true);
			m_safe_string_assert(split_str[3], "5", true);
			m_safe_string_assert(split_str[4], "6", true);
			m_safe_string_assert(split_str[5], "", true);
			massert((void *)split_str[6], NULL);
			ft_free_split(&split_str);
		}
	}

	{
		char	*str = "";
		char	*sep = "";
		char	**split_str;

		m_safe_assert(void *, split_str = ft_split_str(str, sep, "test ft_split_str 3"), split_str, NULL, true);
		if (split_str != NULL)
		{
			m_safe_string_assert(split_str[0], "", true);
			massert((void *)split_str[1], NULL);
			ft_free_split(&split_str);
		}
	}

	{
		// massert(ft_split_str("", ""), NULL)
		// massert(ft_split_str("foo", "x"), NULL)
		// ft_free_split(&split_str);
	}
}
