import java.io.*;
import java.util.*;
import java.math.*;

public class Main3 {
  static BigInteger TWO = BigInteger.valueOf( 2 );
  public static void main(String[] args) throws IOException {
    BufferedReader cin = new BufferedReader( new InputStreamReader( System.in ) );
    ArrayList< Integer > primes = sieve( 1000010 );
    int n_test = Integer.parseInt( cin.readLine( ) );
    while( n_test-- > 0 ) {
      StringTokenizer st = new StringTokenizer( cin.readLine( ) );
      long n = Long.parseLong( st.nextToken( ) );
      long a = Long.parseLong( st.nextToken( ) );
      long b = Long.parseLong( st.nextToken( ) );
      ArrayList< Long > nd = number_decomposition( primes, n );
      BigInteger aa = BigInteger.valueOf( a );
      BigInteger bb = BigInteger.valueOf( b );
      aa = aa.multiply( aa.subtract( BigInteger.ONE ) ).divide( TWO );
      bb = bb.multiply( bb.add( BigInteger.ONE ) ).divide( TWO );
      BigInteger ans = bb.subtract( aa );
      ans = ans.subtract( f( nd, b ) ).add( f( nd, a-1 ) );
      System.out.println( ans );
    }
  }
  static ArrayList< Integer > sieve( int mx ) {
    boolean[ ] is_prime = new boolean[ mx ];
    is_prime[ 0 ] = is_prime[ 1 ] = true;
    for( int i = 2; i*i < mx; i++ ) {
      if( !is_prime[ i ] ) {
        for( int j = i*i; j < mx; j += i ) {
          is_prime[ j ] = true;
        }
      }
    }
    ArrayList< Integer > primes = new ArrayList< >( );
    for( int i = 0; i < mx; i++ ) {
      if( !is_prime[ i ] ) {
        primes.add( i );
      }
    }
    return primes;
  } 
  static ArrayList< Long > number_decomposition( ArrayList< Integer > primes, long n ) {
    ArrayList< Long > ret = new ArrayList< >( );
    for( int p : primes ) {
      boolean flag = false;
      while( n%p == 0 ) {
        flag = true;
        n /= p;
      }
      if( flag ) {
        ret.add( p*1L );
      }
    }
    if( n != 1 ) {
      ret.add( n );
    }
    return ret;
  }

  static BigInteger f( ArrayList< Long > nd, long x ) {
    BigInteger r = BigInteger.ZERO;
    int sz = nd.size( );
    for( int mask = 1; mask < ( 1<<sz ); mask++ ) {
      long num = 1;
      for( int i = mask; i > 0; i -= ( i&(-i) ) ) {
        int j = Integer.numberOfTrailingZeros( i&(-i) );
        num *= nd.get( j );
      }
      BigInteger t = BigInteger.valueOf( x/num );
      t = t.multiply( t.add( BigInteger.ONE ) ).divide( TWO ).multiply( BigInteger.valueOf( num ) );
      if( Integer.bitCount( mask )%2 == 0 ) {
        r = r.subtract( t ); 
      }
      else {
        r = r.add( t );
      }
    }
    return r;
  }
}