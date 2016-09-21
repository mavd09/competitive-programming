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

const int MAX = int( 1e4 );
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int a, b, c, d;

  while( cin >> a >> b >> c >> d ) {
    if( a == b || c == d || b == 1 || c%a != 0 ) {
      cout << -1 << "\n";
      continue;
    }
    int ans = -1;
    for( int i = a; i <= c; i += a ) {
      if( c%i == 0 && d%i != 0 && i%b != 0 ) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}