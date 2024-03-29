/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlcpy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:26:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

#ifndef linux
Test(ft_strlcpy)
{
	{
		char	ft_dst[] = "rrrrrr\0\0\0\0\0\0\0\0";
		char	dst[] = "rrrrrr\0\0\0\0\0\0\0\0";

		size_t ft_cpy = ft_strlcpy(ft_dst, "lorem ipsum dolor sit amet", 15);
		size_t cpy = strlcpy(dst, "lorem ipsum dolor sit amet", 15);
		massert(ft_cpy, cpy);
		massert(ft_dst, dst);
	}
	{
		char	ft_dst[] = "rrrrrr\0\0\0\0\0\0\0\0";
		char	dst[] = "rrrrrr\0\0\0\0\0\0\0\0";

		size_t ft_cpy = ft_strlcpy(ft_dst, "lorem ipsum dolor sit amet", 0);
		size_t cpy = strlcpy(dst, "lorem ipsum dolor sit amet", 0);
		massert(ft_cpy, cpy);
		massert(ft_dst, dst);
	}
}
#endif
