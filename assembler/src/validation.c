#include "corewar.h"

int			show_error(const char *error)
{
    // system("leaks asm");
	ft_printf("%t%s%t\n", B_RED, error, EOC);
	exit(0);
}

int valid_magic(char *magic)
{
    if (magic[0] == '0' && (magic[1] == 'x' || magic[1] == 'X'))
        return (1);
    return (0);
}