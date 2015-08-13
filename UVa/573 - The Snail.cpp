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

double h, u, d, f;

int main( ) {

	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> h >> u >> d >> f ) && ( h+u+d+f > 0 ) ) {
        double ff = u*f/100.0, p = 0.0;
        for( int day = 1; ; day++, u -= ff ) {
            if( u >= 0.0 ) {
                p += u;
                if( p > h ) {
                    cout << "success on day " << day << "\n";
                    break;
                }
            }
            p -= d;
            if( p < 0.0 ) {
                cout << "failure on day " << day << "\n";
                break;
            }
        }
    }

    return 0;
}
