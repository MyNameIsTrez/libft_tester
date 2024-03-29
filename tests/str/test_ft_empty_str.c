/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_empty_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 20:13:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:16:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_empty_str)
{
	m_safe_string_assert_free(ft_empty_str(), "", true);
}
