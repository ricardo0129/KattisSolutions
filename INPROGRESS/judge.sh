cd ./secret
right=0
total=0
for filename in ./*.in; do
    [ -e "$filename" ] || continue
    v2=${filename%??}
    v2="${v2}ans"
    start=`date +%s%N`
    cc=$(cat ./$filename | ../a.out | diff $v2 - | wc -l)
    end=`date +%s%N`

    total=$((total+1))
    if [ $cc = 0 ]
    then
      right=$((right+1)) 
      delta=$(((end-start)/1000000))
      echo "✓ $delta"
    else
      echo "✕"
      echo "$filename"
    fi
    # ... rest of the loop body
done
echo "$right/$total"
