#include "shell.h"

/**
 * exec_line - This finds builtins and commands
 *
 * @datash: Data Relevant (args)
 * Return: 1 if success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell * datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
