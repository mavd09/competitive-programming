#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest;
string word[ ] = { "one", "two" };
string w;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    while( nTest-- ) {
        cin >> w;
        int sz = int( w.size( ) );
        if( sz == 5 ) cout << "3\n";
        else {
            for( int i = 0; i < 2; i++ ) {
                int mistakes = 0;
                for( int j = 0; j < sz; j++ ) mistakes += word[ i ][ j ] != w[ j ];
                if( mistakes <= 1 ) cout << i+1 << "\n";
            }
        }
    }

    return 0;
}
