#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cassert>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< vb >        vvb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = 1<<21;
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

void check( ll& ans, ll& target, ll cur ) {
  if( cur >= target ) {
    if( ans == 0 ) {
      ans = cur;
    }
    else {
      ans = min( ans, cur );
    }
  }
}

void go( int& n, ll& target, vll& hose, ll& ans, int id, ll flow ) {
  if( n == 1 ) {
    return ;
  }
  if( id == n ) {
    check( ans, target, flow );
    return ;
  }
  if( id == 0 ) {
    go( n, target, hose, ans, id+2, hose[ 0 ]+hose[ 1 ] );
    if( hose[ 0 ] >= hose[ 1 ] ) {
      go( n, target, hose, ans, id+2, hose[ 0 ]-hose[ 1 ] );
    }
    go( n, target, hose, ans, id+2, hose[ 0 ]*hose[ 1 ] );
    if( hose[ 1 ] != 0 && hose[ 0 ]%hose[ 1 ] == 0 ) {
      go( n, target, hose, ans, id+2, hose[ 0 ]/hose[ 1 ] );
    }
  }
  else {
    go( n, target, hose, ans, id+1, flow );
    go( n, target, hose, ans, id+1, flow+hose[ id ] );
    if( flow >= hose[ id ] ) {
      go( n, target, hose, ans, id+1, flow-hose[ id ] );
    }
    go( n, target, hose, ans, id+1, flow*hose[ id ] );
    if( hose[ id ] != 0 && flow%hose[ id ] == 0 ) {
      go( n, target, hose, ans, id+1, flow/hose[ id ] );
    }
  }
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  string line;

  while( getline( cin, line ) && line != "0" ) {
    stringstream in( line );
    ll ans = 0;
    ll target, h;
    in >> target;
    int n = 0;
    vll hose;
    while( in >> h ) {
      n++;
      hose.PB( h );
      check( ans, target, ll( h ) );
    }
    sort( hose.begin( ), hose.end( ) );
    do {
      go( n, target, hose, ans, 0, 0 );
    } while( next_permutation( hose.begin( ), hose.end( ) ) );
    cout << ans << "\n";
  }

  return 0;
}