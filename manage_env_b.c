#include "shell.h"

/**
 * _getenv - gets the value of an environ variable
 * @info: contains simulated arguments for a function pointer,
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(information_s *info, const char *name)
{
	char *p;
	list_stru *node = info->env;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * check_setenv - Checks if an environment variable has been set.
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 *
 * Return: 0 if set, else 1.
 */

int check_setenv(information_s *info)
{
	if (info->argc != 3)
	{
		puts_err("Incorrect number of arguements\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * check_unsetenv - Remove an environment variable
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int check_unsetenv(information_s *info)
{
	int i;

	if (info->argc == 1)
	{
		puts_err("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * gather_env - populates env linked list
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int gather_env(information_s *info)
{
	list_stru *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _printenv - prints the current environment
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int _printenv(information_s *info)
{
	print_list_strutr(info->env);
	return (0);
}
