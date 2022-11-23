/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strjoin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:11:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:57:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_strjoin)
{
	m_safe_string_assert_free(ft_strjoin("lorem ipsum", "dolor sit amet"), "lorem ipsumdolor sit amet", true);
	massert((void *)ft_strjoin("foo", NULL), NULL);
	massert((void *)ft_strjoin(NULL, "bar"), NULL);
}

Test(ft_strjoin_partial)
{
	char	*str = ft_stralloc(3);
	if (str != NULL)
	{
		str[0] = 'a';
		str[1] = 'b';
		str[2] = 'c';

		m_safe_string_assert_free(ft_strjoin("foo", str + 1), "foobc", true);
	}
}

////////////////////////////////////////////////////////////////////////////////
