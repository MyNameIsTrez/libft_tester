/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memset_struct.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:20:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/16 17:12:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_memset_struct)
{
	t_u8	pixels[6];
	void	*ft_memset_struct_result;

	ft_memset_struct_result = ft_memset_struct(pixels, (t_u8 []){255, 0, 100}, 3 * sizeof(t_u8), 6);

	massert(pixels[0], (t_u8)255);
	massert(pixels[1], (t_u8)0);
	massert(pixels[2], (t_u8)100);
	massert(pixels[3], (t_u8)255);
	massert(pixels[4], (t_u8)0);
	massert(pixels[5], (t_u8)100);

	massert(ft_memset_struct_result, memset(pixels, 'c', 2));
}

////////////////////////////////////////////////////////////////////////////////
