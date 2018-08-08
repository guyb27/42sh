/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 01:18:16 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/08 02:36:32 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/execute.h"
#include "../../include/stdin.h"

int		ft_check_source(char *source)
{
	struct stat sb;

	if (lstat(source, &sb) == -1)
	{
		ft_putendl("ERROR\n");
		return (-1);
	}
	return (0);
}

int			ft_redirect_heredoc(t_op *t_exec, int flag)
{
	char *tmp_bin;
	pid_t pid;
	int stat;

	tmp_bin = ft_search_bin(t_exec->cmd[0]);
	if ((pid = fork()) < 0)
		exit(1);
	else if (pid == 0)
	{
		if (ft_heredoc(t_exec, tmp_bin, flag, -12) == 0)
			;
		else
			return (2);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
		{
			if (WEXITSTATUS(stat) != 0)
				return (0);
		}
		return (0);
	}
	return (0);
}

int		ft_solver(t_op *t_exec, int fd)
{
	ft_get_bin();
	char *tmp_bin;
	int ok;
	int flag;

	flag = ft_return_flag(t_exec);
	//Si il y a <
	if (flag == O_RDONLY)
		if (ft_check_source(t_exec->redirect->file) == -1)
			return (2);
	//Si il y a <<
	if (flag == HEREDOC)
	{

		if (ft_redirect_heredoc(t_exec, flag) == 0)
			return (0);
		else
			return (2);
	}
	//Si il y a pas < ou <<, passe en dessous
	if ((ok = ft_check_command(t_exec->cmd[0])) != 0)
	{
		if (ft_builtins(t_exec, ok, flag) == 0)
			return (0);
		else
			return (2);
	}
	else
	{
		tmp_bin = ft_search_bin(t_exec->cmd[0]);
		if (ft_exec(t_exec, tmp_bin, flag, fd) == 0)
			return (0);
		else
			return (2);
	}
	return (0);
}
