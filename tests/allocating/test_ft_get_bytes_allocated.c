/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_get_bytes_allocated.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 14:42:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:24:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_get_bytes_allocated)
{
	massert(ft_get_bytes_allocated(), (size_t)0);

	char	*str;

	m_safe_malloc_assert(str = ft_malloc(4, sizeof(char), "test ft_get_bytes_allocated 1"), true);
	if (str != NULL)
	{
		massert(ft_get_bytes_allocated(), (size_t)4);

		char	*str2;
		m_safe_malloc_assert(str2 = ft_malloc(5, sizeof(char), "test ft_get_bytes_allocated 2"), true);
		if (str2 != NULL)
		{
			massert(ft_get_bytes_allocated(), (size_t)9);

			ft_free(&str2);

			massert(ft_get_bytes_allocated(), (size_t)4);
		}

		ft_free(&str);

		massert(ft_get_bytes_allocated(), (size_t)0);
	}
}

Test(ft_get_bytes_allocated2)
{
	massert(ft_get_bytes_allocated(), (size_t)0);

	char	*str;

	m_safe_malloc_assert(str = ft_malloc(4, sizeof(char), "test ft_get_bytes_allocated2 1"), true);
	if (str != NULL)
	{
		massert(ft_get_bytes_allocated(), (size_t)4);

		char	*str2;
		m_safe_malloc_assert(str2 = ft_malloc(5, sizeof(char), "test ft_get_bytes_allocated2 2"), true);
		if (str2 != NULL)
		{
			massert(ft_get_bytes_allocated(), (size_t)9);

			ft_free(&str);

			massert(ft_get_bytes_allocated(), (size_t)5);

			ft_free(&str2);

			massert(ft_get_bytes_allocated(), (size_t)0);
			return ;
		}

		ft_free(&str);

		massert(ft_get_bytes_allocated(), (size_t)0);
	}
}
