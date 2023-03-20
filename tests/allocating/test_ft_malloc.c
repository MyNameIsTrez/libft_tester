/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_malloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:25:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_malloc)
{
	char	*str;

	m_safe_malloc_assert(str = ft_malloc(4, sizeof(char), "test ft_malloc"), true);
	if (str != NULL)
	{
		str[0] = 'a';
		str[1] = 'b';
		str[2] = 'c';
		str[3] = '\0';

		massert(str[0], (char)'a');
		massert(str[1], (char)'b');
		massert(str[2], (char)'c');
		massert(str[3], (char)'\0');
	}
}

Test(ft_malloc_count_and_size)
{
	massert(ft_malloc(0, 1, "test ft_malloc_count_and_size 1"), NULL);
	massert(ft_malloc(1, 0, "test ft_malloc_count_and_size 2"), NULL);
	massert(ft_malloc(0, 0, "test ft_malloc_count_and_size 3"), NULL);

	// massert(ft_malloc(SIZE_MAX, 1), NULL);

	massert(ft_malloc(SIZE_MAX, 2, "test ft_malloc_count_and_size 4"), NULL);
	massert(ft_malloc(2, SIZE_MAX, "test ft_malloc_count_and_size 5"), NULL);
	massert(ft_malloc(SIZE_MAX, SIZE_MAX, "test ft_malloc_count_and_size 6"), NULL);
}
