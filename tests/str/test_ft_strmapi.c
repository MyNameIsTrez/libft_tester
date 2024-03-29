/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strmapi.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:30:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:05:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

static char	increase_by_index(unsigned int i, char c)
{
	return (char)((unsigned)c + i);
}

Test(ft_strmapi)
{
	m_safe_string_assert_free(ft_strmapi("foo", increase_by_index, "test ft_strmapi"), "fpq", true);
}
