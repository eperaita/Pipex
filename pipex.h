/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:50:47 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/29 10:27:05 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

typedef struct s_args
{
	char	*outfile;
	char	*infile;
	char	**env;
	char	**env_paths;
	int		**fd;
	int		*pid;
	int		nchild;
	int		npipes;
	int		doc;
	char	**commands;
}	t_args;

void	ft_free_paths(t_args *com);
void	ft_free_pipes(t_args *com);
void	ft_error(t_args *com);
void	ft_close(t_args *com);
void	ft_isdoc(char **argv, t_args *com);

#endif
