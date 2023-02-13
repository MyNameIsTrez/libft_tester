/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_recalloc.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 16:01:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_recalloc_existing)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 1), false);
	if (!was_malloc_unstable)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
	}

	// Since ft_recalloc() callocs a new string, it is fine if the previous
	// ft_calloc call failed.
	was_malloc_unstable = false;

	char	*str_new;

	m_safe_string_assert(str_new = ft_recalloc(&str, 2, 4, sizeof(char)), str_new, false);
	if (!was_malloc_unstable)
	{
		massert(str_new[2], (char)'\0');
		massert(str_new[3], (char)'\0');

		massert(str, (char *)NULL);
	}
}

Test(ft_recalloc_no_new)
{
	char	*str;

	m_safe_malloc_assert(str = ft_recalloc(NULL, 0, 2, sizeof(char)), false);
	if (!was_malloc_unstable)
		massert(str, (char *)NULL);
}

Test(ft_recalloc_size_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 1), false);
	if (!was_malloc_unstable)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
	}
	massert(ft_recalloc(&str, 0, 0, sizeof(char)), NULL);
}

Test(ft_recalloc_new_and_size_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_recalloc(NULL, 0, 0, sizeof(char)), false);
	massert(ft_recalloc(&str, 0, 0, sizeof(char)), NULL);
}

////////////////////////////////////////////////////////////////////////////////
