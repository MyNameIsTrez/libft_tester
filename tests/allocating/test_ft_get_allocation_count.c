/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_get_allocation_count.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 14:42:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:24:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_get_allocation_count)
{
	massert(ft_get_allocation_count(), (size_t)0);

	char	*str;

	m_safe_malloc_assert(str = ft_malloc(4, sizeof(char)), true);
	if (str != NULL)
	{
		massert(ft_get_allocation_count(), (size_t)1);

		ft_free(&str);

		massert(ft_get_allocation_count(), (size_t)0);
	}
}

////////////////////////////////////////////////////////////////////////////////
