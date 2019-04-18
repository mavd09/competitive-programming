from sys import stdin

inputIdx = 0;
input = stdin.read().strip().split();

def nextToken():
  global inputIdx, input;
  if inputIdx == len(input):
    exit();
  token = input[inputIdx];
  inputIdx += 1;
  return token;

def main():
  while True:
    n = int(nextToken());
    s = set( [ int(nextToken()) for i in range(n) ] );
    ans = [];
    d1 = -1; d2 = -1; d3 = -1;
    for x in s:
      if x == 0 or x == 100:
        ans.append(x);
      elif 1 <= x and x <= 9:
        d1 = x;
      elif (x%10) == 0:
        d2 = x;
      else:
        d3 = x;
    if d1 != -1 and d2 != -1:
      ans += [ d1, d2 ];
    else:
      if d1 != -1:
        ans.append(d1);
      elif d2 != -1:
        ans.append(d2);
      elif d3 != -1:
        ans.append(d3);
    if len(ans) == 0:
      ans.append( tmp );
    print( len(ans) );
    print( " ".join(map(str,ans)) );

main();
