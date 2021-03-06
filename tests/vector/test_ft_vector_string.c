/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_string.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:25:30 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:25:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_string)
{
	char	**strings;
	char	*string;

	m_safe_malloc_assert(strings = ft_vector_new(sizeof(char *)), false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(int, (int)ft_vector_reserve(&strings, 1), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		string = strdup("foo");
		m_safe_assert(int, (int)ft_vector_push(&strings, &string), OK, ERROR, false);
		if (NOT was_malloc_unstable)
			m_safe_string_assert(strings[0], "foo", false);
		ft_free(&string);
	}
	if (NOT was_malloc_unstable)
	{
		string = strdup("bar");
		m_safe_assert(int, (int)ft_vector_push(&strings, &string), OK, ERROR, false);
		if (NOT was_malloc_unstable)
			m_safe_string_assert(strings[1], "bar", false);
		ft_free(&string);
	}
	if (NOT was_malloc_unstable)
	{
		string = strdup("baz");
		m_safe_assert(int, (int)ft_vector_push(&strings, &string), OK, ERROR, false);
		if (NOT was_malloc_unstable)
			m_safe_string_assert(strings[2], "baz", false);
		ft_free(&string);
	}
}

////////////////////////////////////////////////////////////////////////////////
