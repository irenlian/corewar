#include "../../includes/corewar.h"

t_vm	*create_game()
{
	t_vm	*vm;
	char *arena;
    int pl_dist;

	vm = (t_vm*)ft_memalloc(sizeof(t_vm));
	vm->cycles_to_die = CYCLE_TO_DIE;
	// pl_dist = MEM_SIZE * 2 / (get_quantity_players(champ) - 1);
    // arena = ft_memalloc(MEM_SIZE * 2 + 1);
    // arena = ft_memset(arena, '0', MEM_SIZE * 2);
	return (vm);
}