/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset_struct.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:20:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 16:18:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_memset_struct_of_bytes)
{
	t_u8	pixels[6];
	void	*ft_memset_struct_result;

	ft_memset_struct_result = ft_memset_struct(pixels, (t_u8 []){255, 0, 100}, 3 * sizeof(t_u8), 6 * sizeof(t_u8));

	massert(pixels[0], (t_u8)255);
	massert(pixels[1], (t_u8)0);
	massert(pixels[2], (t_u8)100);
	massert(pixels[3], (t_u8)255);
	massert(pixels[4], (t_u8)0);
	massert(pixels[5], (t_u8)100);

	massert(ft_memset_struct_result, memset(pixels, 'c', 2));
}

Test(ft_memset_struct_of_ints)
{
	int		pixels[6];
	void	*ft_memset_struct_result;

	ft_memset_struct_result = ft_memset_struct(pixels, (int []){420, 1337, 21}, 3 * sizeof(int), 6 * sizeof(int));

	massert(pixels[0], 420);
	massert(pixels[1], 1337);
	massert(pixels[2], 21);
	massert(pixels[3], 420);
	massert(pixels[4], 1337);
	massert(pixels[5], 21);

	massert(ft_memset_struct_result, memset(pixels, 'c', 2));
}

////////////////////////////////////////////////////////////////////////////////
