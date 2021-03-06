/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:25:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector)
{
	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(int, (int)ft_vector_reserve(&ints, 1), OK, ERROR, false);
	}

	int i = 0;
	while (i < 1000)
	{
		if (NOT was_malloc_unstable)
		{
			v = i;
			m_safe_assert(int, (int)ft_vector_push(&ints, &v), OK, ERROR, false);
			if (NOT was_malloc_unstable)
				massert(ints[i], i);
		}
		i++;
	}

	if (NOT was_malloc_unstable)
	{
		massert(ft_vector_get_size(ints), (size_t)1000);
	}
}

////////////////////////////////////////////////////////////////////////////////
