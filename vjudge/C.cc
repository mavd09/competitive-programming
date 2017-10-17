#include <stdio.h>

const int N = 20;
long long fact[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};

long long get_sum( int mask ) {
  long long sum = 0;
  for( int i = 0; i < N; ++i ) {
    if( (mask>>i)&1 ) {
      sum += fact[i];
    }
  }
  return sum;
}

main( ) {

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    long long n; scanf( "%lld", &n );
    printf( "Case %d: ", tc );
    if( n == 0 ) {
      printf( "impossible\n" );
      continue;
    }
    int lo = 1, hi = (1<<N)-1;
    while( lo <= hi ) {
      int mi = (lo+hi)>>1;
      long long sum = get_sum( mi );
      if( sum > n ) hi = mi-1;
      else lo = mi+1;
    }
    long long sum = get_sum( hi );
    if( n == sum ) {
      int fst = 1, mask = hi;
      for( int i = 0; i < N; ++i ) {
        if( (mask>>i)&1 ) {
          if( fst == 0 ) printf( "+" );
          fst = 0;
          printf( "%d!", i );
        }
      }
      printf( "\n" );
    } else {
      printf( "impossible\n" );
    }
  }

}