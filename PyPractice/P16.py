from sys import stdin, stdout

def main():
  inputIdx = 0;
  input = stdin.read().strip().split();
  while inputIdx < len(input):
    n = int( input[inputIdx] );
    inputIdx += 1;
    m = int( input[inputIdx] );
    inputIdx += 1;
    maskA = 0;
    for i in range(n):
      x = int( input[inputIdx] );
      inputIdx += 1;
      maskA |= (1<<x);
    maskB = 0;
    for i in range(m):
      x = int( input[inputIdx] );
      inputIdx += 1;
      maskB |= (1<<x);
    if (maskA&maskB) != 0:
      for i in range(10):
        if ((maskA&maskB)&(1<<i)) != 0:
          print( i );
          break;
    else:
      d1 = 0;
      for i in range(10):
        if (maskA&(1<<i)) != 0:
          d1 = i;
          break;
      d2 = 0;
      for i in range(10):
        if (maskB&(1<<i)) != 0:
          d2 = i;
          break;
      ans = min(d1,d2)*10 + max(d1,d2);
      print( ans );

main();
