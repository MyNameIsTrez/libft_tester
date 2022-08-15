/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_remalloc.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:23:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_remalloc_existing)
{
	char	*str;

	m_safe_malloc_assert(str = ft_malloc(2, sizeof(char)), false);
	if (NOT was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = '\0';

		massert(str[0], (char)'a');
		massert(str[1], (char)'\0');
	}

	// Since ft_remalloc() mallocs a new string, it is fine if the previous
	// ft_malloc call failed.
	was_malloc_unstable = false;

	char	*str_new;

	m_safe_malloc_assert(str_new = ft_remalloc(&str, 2, 4, sizeof(char)), false);
	if (NOT was_malloc_unstable)
	{
		str_new[2] = 'c';
		str_new[3] = 'd';

		massert(str_new[2], (char)'c');
		massert(str_new[3], (char)'d');

		massert(str, (char *)NULL);
	}
}

Test(ft_remalloc_no_new)
{
	char	*str;

	m_safe_malloc_assert(str = ft_remalloc(NULL, 0, 2, sizeof(char)), false);
	if (NOT was_malloc_unstable)
		massert(str, (char *)NULL);
}

Test(ft_remalloc_size_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_malloc(2, sizeof(char)), false);
	if (NOT was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = '\0';

		massert(str[0], (char)'a');
		massert(str[1], (char)'\0');
	}
	massert(ft_remalloc(&str, 0, 0, sizeof(char)), NULL);
}

Test(ft_remalloc_new_and_size_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_remalloc(NULL, 0, 0, sizeof(char)), false);
	massert(ft_remalloc(&str, 0, 0, sizeof(char)), NULL);
}

////////////////////////////////////////////////////////////////////////////////
