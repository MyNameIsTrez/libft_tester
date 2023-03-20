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

#include "libft_tests.h"

Test(ft_recalloc_existing)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 1, "test ft_recalloc_existing 1"), false);
	if (!was_malloc_unstable)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');

		char	*str_new;

		m_safe_string_assert(str_new = ft_recalloc(&str, 4), str_new, false);
		if (!was_malloc_unstable)
		{
			massert(str_new[2], (char)'\0');
			massert(str_new[3], (char)'\0');

			massert(str, (char *)NULL);
		}
	}
}

Test(ft_recalloc_no_new)
{
	char	*str;

	m_safe_malloc_assert(str = ft_recalloc(NULL, 2), false);
	if (!was_malloc_unstable)
		massert(str, (char *)NULL);
}

Test(ft_recalloc_count_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 1, "test ft_recalloc_count_zero 1"), false);
	if (!was_malloc_unstable)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
	}
	massert(ft_recalloc(&str, 0), NULL);
}

Test(ft_recalloc_new_and_count_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_recalloc(NULL, 0), false);
	massert(ft_recalloc(&str, 0), NULL);
}
