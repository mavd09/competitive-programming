from sys import stdin

def read():
  line = stdin.readline();
  if line == "":
    exit();
  return line;

def main():
  while True:
    n, k = map(int, read().split());
    m = read();
    dp = [0]*n;
    dp[0] = 1; cnt = 1;
    for i in range(1,n):
      dp[i] = 1 if cnt > 0 and m[i] == '.' else 0;
      cnt += dp[i];
      if i-k >= 0:
        cnt -= dp[i-k];
    if dp[n-1] == 1:
      print( "YES" );
    else:
      print( "NO" );

main();
