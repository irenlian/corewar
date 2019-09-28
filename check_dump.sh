START_CYCLE=0
STEP=1000
NUM_TESTS=24367
PLAYER1="bigzork"
PLAYER2="fluttershy"
THRED=1
# START_CYCLE=0
# STEP=100
# NUM_TESTS=24367
# PLAYER1="bigzork"
# PLAYER2="helltrain"
# THRED=2

for (( i = $START_CYCLE; i < $NUM_TESTS; i += $STEP )); do
    ./corewar "vm_champs/champs/my_cor/$PLAYER1.cor" "vm_champs/champs/my_cor/$PLAYER2.cor"  -dump $i > mine$THRED
    ./vm_champs/corewar "vm_champs/champs/examples/$PLAYER1.cor" "vm_champs/champs/examples/$PLAYER2.cor" -d $i > his$THRED
    if (( $i % 5 == 0 ))
        then
        echo "$i"
        fi
    diff mine$THRED his$THRED > res$THRED
    if [ -s res$THRED ] ; then
        echo "$i Stop"; exit 0
        fi
    # $STEP = $i * 0.1;
    # if (( $STEP < 1 ))
    #     then
    #     $STEP = 1;
    #     fi
done