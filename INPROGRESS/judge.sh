cd ./secret
right=0
total=0
for filename in ./*.in; do
    [ -e "$filename" ] || continue
    v2=${filename%??}
    v2="${v2}ans"
    cc=$(cat ./$filename | ../a.out | diff $v2 - | wc -l)

    total=$((total+1))
    if [ $cc = 0 ]
    then
      right=$((right+1)) 
      echo "✓"
    else
      echo "✕"
      o1=$(cat ./$filename | ../a.out)
      o2=$(cat $v2)
      e=$(echo "$o1 - $o2" | bc)
      echo "$filename"
      echo "$e"
#      echo "$filename"
    fi
    # ... rest of the loop body
done
echo "$right/$total"
