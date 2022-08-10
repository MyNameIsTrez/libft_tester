/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_swap_remove.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 13:00:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

// TODO: Remove
t_metadata	*get_metadata_ptr(void *vector);

Test(ft_vector_swap_remove_out_of_bounds)
{
	int	*ints;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	if (NOT was_malloc_unstable)
	{
		ft_vector_swap_remove(&ints, 0);
		m_safe_assert(t_ft_error, ft_get_error(), FT_ERROR_OUT_OF_BOUNDS, FT_ERROR_MALLOC, false);
	}
}

Test(ft_vector_swap_remove)
{
	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	int i = 0;
	while (i < 1000)
	{
		if (NOT was_malloc_unstable)
		{
			v = i;
			m_safe_assert(t_status, ft_vector_push(&ints, &v), OK, ERROR, false);
			if (NOT was_malloc_unstable)
				massert(ints[i], i);
		}
		i++;
	}

	if (NOT was_malloc_unstable)
		m_safe_assert(t_status, ft_vector_swap_remove(&ints, 0), OK, ERROR, false);

	if (NOT was_malloc_unstable)
		m_safe_assert(t_status, ft_vector_swap_remove(&ints, 0), OK, ERROR, false);

	if (NOT was_malloc_unstable)
		massert(ft_vector_get_size(ints), (size_t)998);
}

////////////////////////////////////////////////////////////////////////////////
