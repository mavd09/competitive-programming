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

int nTest, n, td, mile, juice;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    for( int tc = 1; nTest--; tc++ ) {
        cin >> n;
        mile = juice = 0;
        for( int i = 0; i < n; i++ ) {
            cin >> td;
            mile  += ceil((td+1)/30.0) * 10;
            juice += ceil((td+1)/60.0) * 15;
        }
        cout << "Case " << tc << ": ";
        if( mile < juice ) cout << "Mile " << mile << "\n";
        else if( juice < mile ) cout << "Juice " << juice << "\n";
        else cout << "Mile Juice " << mile << "\n";
    }

    return 0;
}
