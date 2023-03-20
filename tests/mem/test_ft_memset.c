/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:20:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/16 16:52:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_memset)
{
	char	str[] = "foo";
	void	*ft_memset_result;

	ft_memset_result = ft_memset(str, 'c', 2);

	massert(str[0], (char)'c');
	massert(str[1], (char)'c');
	massert(str[2], (char)'o');
	massert(str[3], (char)'\0');

	massert(ft_memset_result, memset(str, 'c', 2));
}
