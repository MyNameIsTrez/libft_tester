/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcpy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:13:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

#include <string.h>	// memcpy()

Test(ft_memcpy)
{
	char	dst_ft[] = "foo";
	char	dst_original[] = "foo";
	char	src[] = "bar";
	size_t	n;

	n = 2;
	massert((char *)ft_memcpy(dst_ft, src, n), "bao");
	massert((char *)memcpy(dst_original, src, n), "bao");
	massert((char *)ft_memcpy(dst_ft, src, n), (char *)memcpy(dst_original, src, n));
}
