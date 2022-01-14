/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:02:47 by hphanixa          #+#    #+#             */
/*   Updated: 2022/01/14 20:47:18 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_arg(void)
{
	ft_putstr(USAGE);
	exit(EXIT_FAILURE);
}

void	ft_error(const char *arg)
{
	if (errno == 0 || arg == NULL)
		write(STDERR_FILENO, "Error\n", 6);
	else
		perror(arg);
	exit(EXIT_FAILURE);
}

void	ft_cmd_error(char **cmd)
{
	write(STDERR_FILENO, "Command not found:", 18);
	if (cmd != NULL && cmd[0] != NULL)
	{
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
	}
	write(STDERR_FILENO, "\n", 1);
	exit(42);
}

void	free_after_split(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}
