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

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_calloc)
{
	char	*str;

	m_safe_malloc_assert(str = ft_calloc(2, 2), true);
	if (str != NULL)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
		massert(str[2], (char)'\0');
		massert(str[3], (char)'\0');
	}
}

Test(ft_calloc_count_0)
{
	massert(ft_calloc(0, 2), NULL);
}

Test(ft_calloc_size_0)
{
	massert(ft_calloc(2, 0), NULL);
}

Test(ft_calloc_count_and_size_0)
{
	massert(ft_calloc(0, 0), NULL);
}

////////////////////////////////////////////////////////////////////////////////
