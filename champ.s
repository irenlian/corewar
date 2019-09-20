.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1
zalupa:
live:   sti2 %0
        ld %0, r2
        zjmp %:loop