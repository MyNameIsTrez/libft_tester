/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_free_split.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 12:44:57 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/06 16:24:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_free_split)
{
	char	*str = "AB1ABAB2AB3";
	char	*sep = "AB";
	char	**split_str;

	m_safe_assert(void *, split_str = ft_split_str(str, sep, "test ft_free_split"), split_str, NULL, true);

	if (split_str != NULL)
	{
		ft_free_split(&split_str);
		massert((void *)split_str, NULL);
	}
}
