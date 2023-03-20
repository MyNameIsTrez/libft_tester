/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_replace.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:45:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:14:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_replace)
{
	m_safe_string_assert_free(ft_str_replace("foo\nbar", "\n", "\\n", "test ft_str_replace"), "foo\\nbar", true);
}
