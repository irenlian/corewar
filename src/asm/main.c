#include "corewar.h"

t_str   *read_file(char *path)
{
    t_str *str;
    t_str *tmp;
    char *line;
    int fd;

    str = NULL;
    line = NULL;
    fd = open(path, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        tmp = create_tstr(line);
        if (!str)
            str = tmp;
        tmp = tmp->next;
    }
    return (str);
}

void set_magic(int fd)
{
    int magic = COREWAR_EXEC_MAGIC;
    write(fd, &magic, 4);
}

void set_name(int fd, char *name)
{
    
    write(fd, &name, PROG_NAME_LENGTH);
    
}

int     main(int argc, char **argv)
{
    // t_bytes *cor;
    t_str *champ;
    int fd;
    
    // cor = set_magic();
    
    fd = open("champ.cor", O_WRONLY);
    set_magic(fd);
    champ = read_file(argv[1]);
    set_name(fd, "testit");
    // printf("%d", COREWAR_EXEC_MAGIC);
    return (0);
}