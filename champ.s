.name       "Batman"
.comment    "This city needs me"

zjmp%:loop
loop:sti r1, %:live, %1
		ld   %0,r3		
label:		zjmp %:avantdebut
		zjmp %0				# pour eviter ecrasement
						# de l'instruction suivante
code:		live %42			# 5
loop:
        sti r1, %:live, %1

avantdebut:	sti   r1,%:code,%1  # 		#7	


live:   live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop
        live %0
        ld %0, r2
        zjmp %:loop

live100:	live	%42
live101:	live	%42
		zjmp	%:live101

label1:
label2:
label3:
label4:
label5:
label6:
label7:
label8:
label9:
label0:
label123:
label125:
label12567:
label1265:
		ld %0, r2
