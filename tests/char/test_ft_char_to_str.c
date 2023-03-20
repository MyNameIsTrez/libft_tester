/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_char_to_str.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:34:17 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:14:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_char_to_str)
{
	m_safe_string_assert_free(ft_char_to_str('c'), "c", true);
	// massert((bool)(ft_char_to_str('\0') != NULL), true);
	m_safe_string_assert_free(ft_char_to_str('\0'), "", true);
}
