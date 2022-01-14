#include "pipex.h"

char **check_if_cmd1_exist(t_util *ptr_util)
{
	ptr_util->cmd_option1 = ft_split(ptr_util->arg[2], ' ');

	if (ptr_util->cmd_option1 == NULL)
		ft_cmd_error(ptr_util->cmd_option1);
		
	return (ptr_util->cmd_option1);
}
	
char **check_if_cmd2_exist(t_util *ptr_util)
{
	ptr_util->cmd_option2 = ft_split(ptr_util->arg[3], ' ');

	if (ptr_util->cmd_option2 == NULL)
		ft_cmd_error(ptr_util->cmd_option2);
	
	return (ptr_util->cmd_option2);
}
