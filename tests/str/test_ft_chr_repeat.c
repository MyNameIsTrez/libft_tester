/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_chr_repeat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 19:14:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:13:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_chr_repeat)
{
	m_safe_string_assert_free(ft_chr_repeat('\0', 0, "test ft_chr_repeat 1"), "", true);
	m_safe_string_assert_free(ft_chr_repeat('a', 0, "test ft_chr_repeat 2"), "", true);

	m_safe_string_assert_free(ft_chr_repeat('\0', 1, "test ft_chr_repeat 3"), "", true);
	m_safe_string_assert_free(ft_chr_repeat('a', 1, "test ft_chr_repeat 4"), "a", true);

	m_safe_string_assert_free(ft_chr_repeat('\0', 2, "test ft_chr_repeat 5"), "", true);
	m_safe_string_assert_free(ft_chr_repeat('a', 2, "test ft_chr_repeat 6"), "aa", true);
}
