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

int nTest, n, cntLowJump, cntHighJump, lastWall, curWall;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    for( int tc = 1; ( cin >> n >> lastWall ); tc++ ) {
        cntLowJump = cntHighJump = 0;
        for( int i = 1; i < n; i++ ) {
            cin >> curWall;
            cntLowJump += ( lastWall > curWall );
            cntHighJump += ( lastWall < curWall );
            lastWall = curWall;
        }
        cout << "Case " << tc << ": " << cntHighJump << " " << cntLowJump << "\n";
    }

    return 0;
}
