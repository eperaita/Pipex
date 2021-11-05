/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:39:20 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/28 17:09:26 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../pipex.h"
#include <fcntl.h>

static void	ft_here_doc(char **argv)
{
	char	*line;
	char	*limit;
	int		fd;

	limit = ft_strjoin(argv[2], "\n");
	fd = open("here_doc.txt", O_RDWR | O_CREAT | O_APPEND, 0755);
	if (fd < 0)
	{
		free(limit);
		exit (0);
	}
	while (1)
	{
		line = get_next_line(0);
		if (ft_strcmp(line, limit))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
		line = NULL;
	}
	free(limit);
	close(fd);
}

void	ft_isdoc(char **argv, t_args *com)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		ft_here_doc(argv);
		com->doc = 1;
		com->npipes--;
		com->nchild--;
	}
	else
		return ;
}
