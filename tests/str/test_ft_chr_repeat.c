/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_chr_repeat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 19:14:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_chr_repeat)
{
	m_safe_string_assert(ft_chr_repeat('\0', 0), "");
	m_safe_string_assert(ft_chr_repeat('a', 0), "");

	m_safe_string_assert(ft_chr_repeat('\0', 1), "");
	m_safe_string_assert(ft_chr_repeat('a', 1), "a");

	m_safe_string_assert(ft_chr_repeat('\0', 2), "");
	m_safe_string_assert(ft_chr_repeat('a', 2), "aa");
}

////////////////////////////////////////////////////////////////////////////////
