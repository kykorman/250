#/bin/bash/!
gcc tmp2.c -o b.out
gcc a6_h779.c
for ((i=0;i<9;i++));do
	./b.out>"in"$i
	cat "in"$i
	./a.out< "in"$i > "out"$i
	cat "out"$i
	sleep 2
done
rm in?
