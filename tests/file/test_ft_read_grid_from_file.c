/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read_grid_from_file.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:37:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/23 15:21:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_read_grid_from_file)
{
	{
		t_grid		grid;
		t_success	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/empty");
		massert_success(success, SUCCESS);
		massert(grid.width, (size_t)0);
		massert(grid.height, (size_t)0);
		massert(grid.cells[0], (char *)NULL);
		free(grid.cells);
	}

	{
		t_grid		grid;
		t_success	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/no_trailing_newline");
		massert_success(success, SUCCESS);
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
		m_safe_string_assert_free(grid.cells[0], "1111111111111", true);
		m_safe_string_assert_free(grid.cells[1], "10010000000C1", true);
		m_safe_string_assert_free(grid.cells[2], "1000011111001", true);
		m_safe_string_assert_free(grid.cells[3], "1P0011E000001", true);
		m_safe_string_assert_free(grid.cells[4], "1111111111111", true);
		free(grid.cells);
	}

	{
		t_grid		grid;
		t_success	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/not_rectangular");
		massert_success(success, ERROR_NONRECTANGULAR_GRID);
	}

	{
		t_grid		grid;
		t_success	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/trailing_newline");
		massert_success(success, SUCCESS);
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
		m_safe_string_assert_free(grid.cells[0], "1111111111111", true);
		m_safe_string_assert_free(grid.cells[1], "10010000000C1", true);
		m_safe_string_assert_free(grid.cells[2], "1000011111001", true);
		m_safe_string_assert_free(grid.cells[3], "1P0011E000001", true);
		m_safe_string_assert_free(grid.cells[4], "1111111111111", true);
		free(grid.cells);
	}
}

////////////////////////////////////////////////////////////////////////////////
