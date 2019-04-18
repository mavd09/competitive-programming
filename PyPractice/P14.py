from sys import stdin, stdout
from fractions import gcd

inputIdx = 0;
input = stdin.read().strip().split();

def nextToken():
  global inputIdx, input;
  if inputIdx == len(input):
    exit();
  token = input[inputIdx];
  inputIdx += 1;
  return token;

def simplify( p, q ):
  g = gcd(p,q);
  return p//g, q//g;

def main():
  while True:
    p = int(nextToken()); q = int(nextToken());
    p, q = simplify(p,q);
    n = int(nextToken());
    a = [ int(nextToken()) for i in range(n) ];
    a = a[::-1];
    num = a[0]; den = 1;
    for i in range(1, n):
      num, den = den, num;
      num = num + den*a[i];
      num, den = simplify(num, den);
    if p == num and q == den:
      print( "YES" );
    else:
      print( "NO" );

main();
