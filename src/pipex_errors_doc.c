/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:34:33 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/27 16:05:50 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_free_paths(t_args *com)
{
	while (*com->env_paths)
		free(*(com->env_paths)++);
	free(com->env_paths);
}

void	ft_free_pipes(t_args *com)
{
	int	i;

	i = 0;
	while (i < com->npipes)
		free(com->fd[i++]);
	free(com->fd);
}

void	ft_error(t_args *com)
{
	ft_free_pipes(com);
	ft_free_paths(com);
	perror("Error");
	exit (1);
}

void	ft_close(t_args *com)
{
	int	i;
	int	j;

	i = 0;
	while (i < com->npipes)
	{
		j = 0;
		while (j < 2)
		{
			close(com->fd[i][j]);
			j++;
		}
		i++;
	}
}
