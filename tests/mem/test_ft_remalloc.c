/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_remalloc.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 13:40:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_remalloc_existing)
{
	char	*str;

	m_safe_string_assert(str = ft_malloc(2), str, false);
	if (NOT was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = 'b';

		massert(str[0], (char)'a');
		massert(str[1], (char)'b');
	}

	// Since ft_recalloc() callocs a new string, it is fine if the previous
	// ft_malloc call failed.
	was_malloc_unstable = false;

	m_safe_string_assert(str = ft_remalloc(str, 2, 4), str, false);
	if (NOT was_malloc_unstable)
	{
		str[2] = 'c';
		str[3] = 'd';

		massert(str[2], (char)'c');
		massert(str[3], (char)'d');
	}
}

Test(ft_remalloc_new)
{
	char	*str;

	m_safe_string_assert(str = ft_remalloc(NULL, 0, 2), str, false);
	if (NOT was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = 'b';

		massert(str[0], (char)'a');
		massert(str[1], (char)'b');
	}
}

Test(ft_remalloc_size_zero)
{
	char	*str;

	m_safe_string_assert(str = ft_malloc(2), str, false);
	if (NOT was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = 'b';

		massert(str[0], (char)'a');
		massert(str[1], (char)'b');
	}
	massert(ft_remalloc(str, 0, 0), NULL);
}

Test(ft_remalloc_new_and_size_zero)
{
	char	*str;

	m_safe_string_assert(str = ft_remalloc(NULL, 0, 0), str, false);
	massert(ft_remalloc(str, 0, 0), NULL);
}

////////////////////////////////////////////////////////////////////////////////
