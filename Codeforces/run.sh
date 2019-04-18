brute=$task-brute

g++ -std=c++17 $task.cpp -o $task
g++ -std=c++17 $brute.cpp -o $brute

for (( i=27343; ; i++ )) do
  echo "Test case #$i"
  python2 randomB.py $i > in
  ./$task < in > $task-out
  ./$brute < in > $brute-out
  diff $task-out $brute-out || break
done