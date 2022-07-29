/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_get_element_size.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:35:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:41:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_get_element_size)
{
	void	*ints;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(size_t, (size_t)ft_vector_get_element_size(ints), sizeof(int), 0, false);
	}
}

////////////////////////////////////////////////////////////////////////////////
