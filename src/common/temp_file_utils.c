/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:20:35 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 16:37:18 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <fcntl.h>

int	file_open(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(1, "Error: file open failed\n", 24);
		exit(1);
	}
	return (fd);
}

int	file_open_old(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		write(1, "Error: file open failed\n", 24);
		exit(1);
	}
	return (fd);
}

void	output_from_file(void)
{
	int		fd;
	char	*cmd;

	fd = file_open_old("temp_cmds.txt");
	cmd = ft_get_next_line(fd);
	while (cmd != NULL)
	{
		ft_putstr_fd(cmd, 1);
		free(cmd);
		cmd = ft_get_next_line(fd);
	}
	close(fd);
}
