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

#include "libft_tests.h"

Test(ft_remalloc_existing)
{
	char	*str;

	m_safe_malloc_assert(str = ft_malloc(2, sizeof(char), "test ft_remalloc_existing 1"), false);
	if (!was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = '\0';

		massert(str[0], (char)'a');
		massert(str[1], (char)'\0');

		char	*str_new;

		m_safe_malloc_assert(str_new = ft_remalloc(&str, 4), false);
		if (!was_malloc_unstable)
		{
			str_new[2] = 'c';
			str_new[3] = 'd';

			massert(str_new[2], (char)'c');
			massert(str_new[3], (char)'d');

			massert(str, (char *)NULL);
		}
	}
}

Test(ft_remalloc_no_new)
{
	char	*str;

	m_safe_malloc_assert(str = ft_remalloc(NULL, 2), false);
	if (!was_malloc_unstable)
		massert(str, (char *)NULL);
}

Test(ft_remalloc_count_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_malloc(2, sizeof(char), "test ft_remalloc_count_zero 1"), false);
	if (!was_malloc_unstable)
	{
		str[0] = 'a';
		str[1] = '\0';

		massert(str[0], (char)'a');
		massert(str[1], (char)'\0');
	}
	massert(ft_remalloc(&str, 0), NULL);
}

Test(ft_remalloc_new_and_count_zero)
{
	char	*str;

	m_safe_malloc_assert(str = ft_remalloc(NULL, 0), false);
	massert(ft_remalloc(&str, 0), NULL);
}
