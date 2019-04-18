from sys import stdin, stdout

inputIdx = 0;
input = stdin.read().strip().split();

def nextToken():
  global inputIdx, input;
  token = input[inputIdx];
  inputIdx += 1;
  return token;

def main():
  global inputIdx, input;
  while inputIdx < len(input):
    n = int( nextToken() );
    arr = [ int( nextToken() ) for i in range(n) ];
    diff = 0;
    cur = -1; cnt = 0;
    i = 0;
    ans = max(arr);
    while i < n or cur != -1:
      ans = max( ans, cur );
      if ( i < n and cur != -1 and arr[i] == cur ) or ( cur == -1 ):
        j = i;
        while j < n and arr[i] == arr[j]:
          j += 1;
        cnt += j-i;
        cur = arr[i];
        i = j;
      if (cnt&1) == 1:
        diff += 1;
      cur += 1;
      cnt //= 2;
      if cnt == 0:
        cur = -1;
    ans -= diff-1;
    print( int(ans) );

main();
