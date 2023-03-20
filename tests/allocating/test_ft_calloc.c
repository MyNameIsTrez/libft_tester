/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_calloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 18:27:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_calloc)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 2, "test ft_calloc"), true);
	if (str != NULL)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
		massert(str[2], (char)'\0');
		massert(str[3], (char)'\0');
	}
}

Test(ft_calloc_count_and_size)
{
	massert(ft_calloc(0, 2, "test ft_calloc_count_and_size 1"), NULL);
	massert(ft_calloc(2, 0, "test ft_calloc_count_and_size 2"), NULL);
	massert(ft_calloc(0, 0, "test ft_calloc_count_and_size 3"), NULL);

	// massert(ft_calloc(SIZE_MAX, 1), NULL);

	massert(ft_calloc(SIZE_MAX, 2, "test ft_calloc_count_and_size 4"), NULL);
	massert(ft_calloc(2, SIZE_MAX, "test ft_calloc_count_and_size 5"), NULL);
	massert(ft_calloc(SIZE_MAX, SIZE_MAX, "test ft_calloc_count_and_size 6"), NULL);
}
