#include "pipex.h"

void error_arg(void)
{
	ft_putstr(USAGE);
	exit(EXIT_FAILURE);
}

void ft_error(const char *arg)
{
	if (errno == 0 || arg == NULL)
		write(STDERR_FILENO, "Error\n", 6);
	else
		perror(arg);
	exit(EXIT_FAILURE);
}

void ft_cmd_error(char **cmd)
{
// si cmd commence par . ou /, no such file or directory	
	write(STDERR_FILENO, "Command not found:", 18);
	if (cmd != NULL && cmd[0] != NULL)
	{
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
	}
		write(STDOUT_FILENO, "\n", 1);
//	free_after_split(&cmd);
//	exit(SIGINT + EXIT_NUMBER);

}

void free_after_split(char ***str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while ((*str)[i])
		{
			free((*str)[i]);
			i++;
		}
		free(*str);
		*str = NULL;
	}
}
