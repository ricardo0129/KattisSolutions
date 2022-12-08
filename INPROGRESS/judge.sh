cd ./secret
right=0
total=0
for filename in ./*.in; do
    [ -e "$filename" ] || continue
    v2=${filename%??}
    v2="${v2}ans"
    echo "$filename"
    cc=$(time cat ./$filename | ../a.out | diff $v2 - | wc -l)

    total=$((total+1))
    if [ $cc = 0 ]
    then
      right=$((right+1)) 
      echo "✓"
    else
      echo "✕"
      echo "$o1 $o2"
#      echo "$filename"
    fi
    # ... rest of the loop body
done
echo "$right/$total"
