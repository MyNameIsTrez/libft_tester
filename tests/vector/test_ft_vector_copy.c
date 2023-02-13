/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_copy.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/09/01 15:45:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_copy)
{
	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	int i = 0;
	while (i < 3)
	{
		if (!was_malloc_unstable)
		{
			v = i;
			m_safe_assert(t_status, ft_vector_push(&ints, &v), OK, ERROR, false);
			if (!was_malloc_unstable)
				massert(ints[i], i);
		}
		i++;
	}

	if (!was_malloc_unstable)
	{
		int	*ints2;
		m_safe_assert(void *, ints2 = ft_vector_copy(ints), ints2, NULL, false);

		if (!was_malloc_unstable)
		{
			massert(ints2[0], 0);
			massert(ints2[1], 1);
			massert(ints2[2], 2);

			massert(ft_vector_get_size(ints2), (size_t)3);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
