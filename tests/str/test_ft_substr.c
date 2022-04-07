/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_substr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:44:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_substr)
{
	m_safe_string_assert(ft_substr("lorem ipsum dolor sit amet", 400, 20), "");
	m_safe_string_assert(ft_substr("lorem ipsum dolor sit amet", 5, 0), "");
	m_safe_string_assert(ft_substr("lorem ipsum dolor sit amet", 0, 0), "");
	m_safe_string_assert(ft_substr(" a", 1, 1), "a");
}

////////////////////////////////////////////////////////////////////////////////
