START_CYCLE=0
STEP=1000
NUM_TESTS=25000
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

helpFunction()
{
   echo ""
   echo "Usage: $0 -r champPath1 -w champPath2"
   exit 1 # Exit script after printing help
}

while getopts "r:w:" opt
do
   case "$opt" in
      r ) PLAYER1="$OPTARG" ;;
      w ) PLAYER2="$OPTARG" ;;
	  ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Print helpFunction in case parameters are empty
if [ -z "$PLAYER1" ] && [ -z "$PLAYER2" ]
then
   echo "Input at least one champ";
   helpFunction
fi

for (( i = $START_CYCLE; i < $NUM_TESTS; i += $STEP )); do
    $DIR/../corewar $PLAYER1 $PLAYER2  -dump $i > mine
	$DIR/../vm_champs/corewar $PLAYER1 $PLAYER2 -d $i > his
    if (( $i % 5 == 0 ))
        then
        echo "$i"
        fi
    diff mine his > res
    if [ -s res ] ; then
        echo "$i Stop"; exit 0
        fi
done
rm -rf mine
rm -rf his
rm -rf res
echo "Success!!!";