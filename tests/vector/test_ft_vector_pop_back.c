/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_pop_back.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 13:26:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_pop_back)
{
	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	int i = 0;
	while (i < 10)
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
		ft_vector_pop_back(&ints);
	if (!was_malloc_unstable)
		ft_vector_pop_back(&ints);

	if (!was_malloc_unstable)
		massert(ft_vector_get_size(ints), (size_t)8);
}

////////////////////////////////////////////////////////////////////////////////
