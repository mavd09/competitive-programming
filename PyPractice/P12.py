from sys import stdin

def readLine():
  return stdin.readline();

def main():
  while True:
    n = int(readLine());
    a = readLine();
    b = readLine();
    both = 0;
    onlyA = 0; onlyB = 0;
    for i in range(2*n):
      if a[i] == '1' and b[i] == '1':
        both += 1;
      elif a[i] == '1':
        onlyA += 1;
      elif b[i] == '1':
        onlyB += 1;
    A = 0; B = 0;
    for i in range(n):
      if both:
        A += 1;
        both -= 1;
      elif onlyA:
        A += 1;
        onlyA -= 1;
      elif onlyB:
        onlyB -= 1;
      if both:
        B += 1;
        both -= 1;
      elif onlyB:
        B += 1;
        onlyB -= 1;
      elif onlyA:
        onlyA -= 1;
    if A > B:
      print( "First" );
    elif A < B:
      print( "Second" );
    else:
      print( "Draw" );
    break;

main();
