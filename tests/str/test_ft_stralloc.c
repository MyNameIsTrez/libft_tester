/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_stralloc.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:48:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 18:29:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_stralloc)
{
	char	*str;

	m_safe_malloc_assert(str = ft_stralloc(5, "test ft_stralloc"), false);
	if (!was_malloc_unstable)
	{
		str[0] = 'h';
		str[1] = 'e';
		str[2] = 'l';
		str[3] = 'l';
		str[4] = 'o';
		massert(str, "hello");
	}
}
