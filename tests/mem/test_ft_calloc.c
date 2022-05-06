/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_calloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:23:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/06 16:22:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_calloc)
{
	char	*str;

	str = NULL;
	m_safe_string_assert(str = ft_calloc(2, 2), str, true);
	if (str != NULL)
	{
		massert(str[0], (char)'\0');
		massert(str[1], (char)'\0');
		massert(str[2], (char)'\0');
		massert(str[3], (char)'\0');
		free(str);
	}
}

////////////////////////////////////////////////////////////////////////////////
