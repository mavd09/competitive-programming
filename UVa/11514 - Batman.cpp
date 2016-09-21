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
typedef vector< double >    vd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = int( 1e5+1 );
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int p, v, e;

  while( ( cin >> p >> v >> e ) && !( p == 0 && v == 0 && e == 0 ) ) {
    map< string, int > id_power;
    vi power_attack( p+1 ), power_energy( p+1 );
    for( int i = 1; i <= p; i++ ) {
      string power_name;
      cin >> power_name >> power_attack[ i ] >> power_energy[ i ];
      id_power[ power_name ] = i;
    }
    vvi dp( v+1, vi( p+1, oo ) );
    vi seen( p+1, -1 );
    for( int j = 0; j <= p; j++ ) {
      dp[ 0 ][ j ] = 0;
    }
    for( int i = 0; i < v; i++ ) {
      int cur = i, nxt = i+1;
      string villain_name, powers, power;
      int defense;
      cin >> villain_name >> defense >> powers;
      for( auto& c : powers ) {
        if( c == ',' ) {
          c = ' ';
        }
      }
      stringstream ss( powers );
      while( ss >> power ) {
        seen[ id_power[ power ] ] = i;
      }
      for( int j = 1; j <= p; j++ ) {
        dp[ nxt ][ j ] = dp[ nxt ][ j-1 ];
        if( seen[ j ] == i && defense <= power_attack[ j ] ) {
          dp[ nxt ][ j ] = min( dp[ nxt ][ j ], dp[ cur ][ j-1 ]+power_energy[ j ] );
        }
      }
    }
    if( dp[ v ][ p ] <= e )
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}