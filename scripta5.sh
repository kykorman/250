#/bin/bash/!
gcc tmp.c -o b.out
gcc a5_h779.c
for((i=0;i<9;i++));do
	./b.out >"in"$i
	./a.out "in"$i >"out"$i
	sleep 1
done
cat out?
