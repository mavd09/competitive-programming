#include <bits/stdc++.h>


using namespace std;


int xs[10000];
int hs[10001];
int pos[10001];

int main() {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
  #endif

  int t, a, n, k;
  bool ok;
  long long ans;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &a, &n);
    for(int i = 0; i < n; i++)
      scanf("%d", xs+i);
    for(int i = 0; i <= n; i++)
      scanf("%d", hs+i);
    pos[0] = 0;
    for(int i = 1; i <= n; i++)
      pos[i] = pos[i-1]+xs[i-1];

    ans = 0LL; 
    for(int i = 0; i < n; i++) {
      ok = false;
            for(int j = i+1; j <= n; j++) {
        if(hs[j] > hs[i]) {
          ans += hs[i]*(pos[j]-pos[i]);
          i = j-1;
          ok = true;
          break;
        } 
      }
      if(!ok) break;
    }

    for(int i = n; i > 0; i--) {     
      ok = false;
            for(int j = i-1; j >= 0; j--) {
        if(hs[j] >= hs[i]) {
          ans += hs[i]*(pos[i]-pos[j]);
          i = j+1;
          ok = true;
          break;
        } 
      }
      if(!ok) break;
    }
    printf("%lld\n", ans*a);       
  }
    
  return 0;
}