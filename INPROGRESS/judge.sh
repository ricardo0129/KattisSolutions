./comp.sh
cd ./secret
right=0
total=0
for filename in ./*.in; do
    [ -e "$filename" ] || continue
    v2=${filename%??}
    v2="${v2}ans"
    res=$(cat ./$filename | ../a.out)
	diff=$(echo "$res" | diff $v2 - | head)
	cc=$(echo "$res" | diff $v2 - | wc -l)


    total=$((total+1))
    if [ $cc = 0 ]
    then
      right=$((right+1)) 
      #echo "✓"
    else
      #echo "✕"
	  cat "$v2"
	  echo "\n"
	  echo "$res"
	  echo "---------"
    fi
    # ... rest of the loop body
done
echo "$right/$total"
sol=$(ls -Art | find ../ -type f -name "*.cpp" | tail -n 1)
#cat "$var" | pbcopy
#if [ $right == $total ]
#then
python3 ~/Desktop/kattis-cli/submit.py "$sol"
#fi

