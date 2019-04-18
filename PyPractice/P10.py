from sys import stdin

def read():
  line = stdin.readline();
  if line == "":
    exit();
  return line;

def main():
  while True:
    read();
    a = list( map( int, read().split() ) );
    x = min( a );
    for y in a:
      if (y%x) > 0:
        x = -1
        break;
    print( x );

main();
