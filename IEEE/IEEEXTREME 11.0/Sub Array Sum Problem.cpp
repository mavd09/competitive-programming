#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int d;
int dim[ 5 ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  cin >> d;
  for( int i = 0; i < d; ++i ) {
    cin >> dim[i];
    dim[i]++;
  }

  if( d == 1 ) {
    ll acc[ dim[0] ];
    memset( acc, 0, sizeof(acc) );
    vi c( d );
    for( c[0] = 1; c[0] < dim[0]; ++c[0] ) {
      cin >> acc[ c[0] ];
      for( int mask = 1; mask < (1<<d); ++mask ) {
        vi cur = c;
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p]--;
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? -1 : +1 );
        acc[ c[0] ] += sgn*acc[ cur[0] ];
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      vi l(d); for( auto& e : l ) cin >> e;
      vi r(d); for( auto& e : r ) cin >> e;
      ll sum = 0;
      for( int mask = 0; mask < (1<<d); ++mask ) {
        vi cur(d);
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p] = l[p]-1;
          } else {
            cur[p] = r[p];
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? +1 : -1 );
        sum += sgn*acc[ cur[0] ];
      }
      cout << sum << '\n';
    }
  }
  if( d == 2 ) {
    ll acc[ dim[0] ][ dim[1] ];
    memset( acc, 0, sizeof(acc) );
    vi c( d );
    for( c[0] = 1; c[0] < dim[0]; ++c[0] ) {
      for( c[1] = 1; c[1] < dim[1]; ++c[1] ) {
        cin >> acc[ c[0] ][ c[1] ];
        for( int mask = 1; mask < (1<<d); ++mask ) {
          vi cur = c;
          for( int p = 0; p < d; ++p ) {
            if( (mask>>p)&1 ) {
              cur[p]--;
            }
          }
          int t = __builtin_popcount( mask );
          ll sgn = ( t%2 == 0 ? -1 : +1 );
          acc[ c[0] ][ c[1] ] += sgn*acc[ cur[0] ][ cur[1] ];
        }
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      vi l(d); for( auto& e : l ) cin >> e;
      vi r(d); for( auto& e : r ) cin >> e;
      ll sum = 0;
      for( int mask = 0; mask < (1<<d); ++mask ) {
        vi cur(d);
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p] = l[p]-1;
          } else {
            cur[p] = r[p];
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? +1 : -1 );
        sum += sgn*acc[ cur[0] ][ cur[1] ];
      }
      cout << sum << '\n';
    }
  }
  if( d == 3 ) {
    ll acc[ dim[0] ][ dim[1] ][ dim[2] ];
    memset( acc, 0, sizeof(acc) );
    vi c( d );
    for( c[0] = 1; c[0] < dim[0]; ++c[0] ) {
      for( c[1] = 1; c[1] < dim[1]; ++c[1] ) {
        for( c[2] = 1; c[2] < dim[2]; ++c[2] ) {
          cin >> acc[ c[0] ][ c[1] ][ c[2] ];
          for( int mask = 1; mask < (1<<d); ++mask ) {
            vi cur = c;
            for( int p = 0; p < d; ++p ) {
              if( (mask>>p)&1 ) {
                cur[p]--;
              }
            }
            int t = __builtin_popcount( mask );
            ll sgn = ( t%2 == 0 ? -1 : +1 );
            acc[ c[0] ][ c[1] ][ c[2] ] += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ];
          }
        }
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      vi l(d); for( auto& e : l ) cin >> e;
      vi r(d); for( auto& e : r ) cin >> e;
      ll sum = 0;
      for( int mask = 0; mask < (1<<d); ++mask ) {
        vi cur(d);
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p] = l[p]-1;
          } else {
            cur[p] = r[p];
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? +1 : -1 );
        sum += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ];
      }
      cout << sum << '\n';
    }
  }
  if( d == 4 ) {
    ll acc[ dim[0] ][ dim[1] ][ dim[2] ][ dim[3] ];
    memset( acc, 0, sizeof(acc) );
    vi c( d );
    for( c[0] = 1; c[0] < dim[0]; ++c[0] ) {
      for( c[1] = 1; c[1] < dim[1]; ++c[1] ) {
        for( c[2] = 1; c[2] < dim[2]; ++c[2] ) {
          for( c[3] = 1; c[3] < dim[3]; ++c[3] ) {
            cin >> acc[ c[0] ][ c[1] ][ c[2] ][ c[3] ];
            for( int mask = 1; mask < (1<<d); ++mask ) {
              vi cur = c;
              for( int p = 0; p < d; ++p ) {
                if( (mask>>p)&1 ) {
                  cur[p]--;
                }
              }
              int t = __builtin_popcount( mask );
              ll sgn = ( t%2 == 0 ? -1 : +1 );
              acc[ c[0] ][ c[1] ][ c[2] ][ c[3] ] += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ][ cur[3] ];
            }
          }
        }
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      vi l(d); for( auto& e : l ) cin >> e;
      vi r(d); for( auto& e : r ) cin >> e;
      ll sum = 0;
      for( int mask = 0; mask < (1<<d); ++mask ) {
        vi cur(d);
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p] = l[p]-1;
          } else {
            cur[p] = r[p];
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? +1 : -1 );
        sum += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ][ cur[3] ];
      }
      cout << sum << '\n';
    }
  }
  if( d == 5 ) {
    ll acc[ dim[0] ][ dim[1] ][ dim[2] ][ dim[3] ][ dim[4] ];
    memset( acc, 0, sizeof(acc) );
    vi c( d );
    for( c[0] = 1; c[0] < dim[0]; ++c[0] ) {
      for( c[1] = 1; c[1] < dim[1]; ++c[1] ) {
        for( c[2] = 1; c[2] < dim[2]; ++c[2] ) {
          for( c[3] = 1; c[3] < dim[3]; ++c[3] ) {
            for( c[4] = 1; c[4] < dim[4]; ++c[4] ) {
              cin >> acc[ c[0] ][ c[1] ][ c[2] ][ c[3] ][ c[4] ];
              for( int mask = 1; mask < (1<<d); ++mask ) {
                vi cur = c;
                for( int p = 0; p < d; ++p ) {
                  if( (mask>>p)&1 ) {
                    cur[p]--;
                  }
                }
                int t = __builtin_popcount( mask );
                ll sgn = ( t%2 == 0 ? -1 : +1 );
                acc[ c[0] ][ c[1] ][ c[2] ][ c[3] ][ c[4] ] += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ][ cur[3] ][ cur[4] ];
              }
            }
          }
        }
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      vi l(d); for( auto& e : l ) cin >> e;
      vi r(d); for( auto& e : r ) cin >> e;
      ll sum = 0;
      for( int mask = 0; mask < (1<<d); ++mask ) {
        vi cur(d);
        for( int p = 0; p < d; ++p ) {
          if( (mask>>p)&1 ) {
            cur[p] = l[p]-1;
          } else {
            cur[p] = r[p];
          }
        }
        int t = __builtin_popcount( mask );
        ll sgn = ( t%2 == 0 ? +1 : -1 );
        sum += sgn*acc[ cur[0] ][ cur[1] ][ cur[2] ][ cur[3] ][ cur[4] ];
      }
      cout << sum << '\n';
    }
  }

  return 0;
}

