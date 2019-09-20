.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1

live:   live %0
        ld %0, r2
        zjmp %:loop

live100:	live	%42
live101:	live	%42
		zjmp	%:live101