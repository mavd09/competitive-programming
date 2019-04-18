#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, ll> pii;
 
typedef __int128 T;

T abs(T a) {
 return a < 0 ? -a : a;
}
 
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  pt operator / (T d) { return {x/d, y/d}; } /// only for floating point
  bool operator == (const pt b) const { return x == b.x && y == b.y; }
  bool operator != (const pt b) const { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};
 
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }
 
struct line {
  pt v; T c; int type; pt o;
  line() {}
  line(pt v, T c) : v(v), c(c) {}
  line(T a, T b, T c) : v({b,-a}), c(c) {}
  line(pt p, pt q, int type) : v(q-p), c(cross(v,p)), type(type), o(p) {}
  T side(pt p) { return cross(v,p)-c; }
 
  ll get_y(ll x) {
    if(v.x == 0) return -1; /// no existe
    return (c + v.y*x) / v.x;
  }
  ll get_x(ll y) {
    if(v.y == 0) return -1; /// no existe
    return (-c + v.x*y) / v.y;
  }
  bool operator < (const line &o) const {
    return v < o.v || c < o.c;
  }
  bool operator == (const line &o) const {
    return (cross(v, o.v) == 0 && c == o.c);
  }
};
 
bool inter_ll(line l1, line l2, pt &out) {
  T d = cross(l1.v, l2.v);
  if (d == 0) return false;
  pt num = (l2.v*l1.c - l1.v*l2.c);
  if(num.x % d != 0 || num.y % d != 0) return false;
  out = num / d;
  return true;
}
 
ll n, m;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #else
    #define endl '\n'
  #endif
 
  cin >> m >> n; /// n es x, m es y
  int q; cin >> q;
  vector<line> lines;
 
  function<void(line)> add = [&] (line l) {
    if(find(lines.begin(), lines.end(), l) == lines.end()) lines.push_back(l);
  };
 
  for(int i = 0; i < q; i++) {
    int t, x, y; cin >> t >> y >> x;
    line cur;
    if(t == 1 || t == 3) {
      add( line{ {x, y}, {x, y-1}, 0} );
      add( line{ {x, y}, {x-1, y}, 1 } );
    }
    if(t == 2 || t == 3) {
      add( line{ {x, y}, {x+1, y+1}, 2 } );
      add( line{ {x, y}, {x+1, y-1}, 3 } );
    }
  }
 
//  cout << "hay " << lines.size() << " lineas" << endl;
 
  ll taken = 0;
  map<pt, set<int>> cnt;
  for(int i = 0; i < lines.size(); i++) {
//    cout << lines[i].v << " " << lines[i].c << endl;
//    vector<pt> pts;
//    pts.push_back({lines[i].get_x(1), 1});
////    cout << pts.back() << endl;
//    pts.push_back({lines[i].get_x(m), m});
////    cout << pts.back() << endl;
//    pts.push_back({1, lines[i].get_y(1)});
////    cout << pts.back() << endl;
//    pts.push_back({n, lines[i].get_y(n)});
////    cout << pts.back() << endl;
//    bool f = 0;
//    for(int j = 0; j < pts.size() && !f; j++) {
//      for(int k = j+1; k < pts.size() && !f; k++) {
//        if(pts[j] == pts[k]) continue;
//        if(pts[j].x >= 1 && pts[j].x <= n && pts[j].y >= 1 && pts[j].y <= m &&
//          pts[k].x >= 1 && pts[k].x <= n && pts[k].y >= 1 && pts[k].y <= m) {
//          cout << "linea corta en " << pts[j] << " " << pts[k] << endl;
//          cout << "deberia sumar " << max(abs(pts[j].x - pts[k].x), abs(pts[j].y - pts[k].y))+1 << endl;
//          taken += max(abs(pts[j].x - pts[k].x), abs(pts[j].y - pts[k].y))+1;
//          f = 1;
//        }
//      }
//    }
 
//    cout << lines[i].o << " " << lines[i].type << endl;
 
    ll prev = taken;
    if(lines[i].type == 0) taken += m;
    if(lines[i].type == 1) taken += n;
    if(lines[i].type == 2) {
      taken += min(n - lines[i].o.x, m - lines[i].o.y) + min(lines[i].o.x-1, lines[i].o.y-1) + 1;
    }
    if(lines[i].type == 3) {
      taken += min(m - lines[i].o.y, lines[i].o.x-1) + min(n - lines[i].o.x, lines[i].o.y-1) + 1;
    }
 
//    cout << taken - prev << endl;
 
    for(int j = 0; j < i; j++) {
      pt out;
      if(inter_ll(lines[i], lines[j], out)) {
        if(out.x >= 1 && out.x <= n && out.y >= 1 && out.y <= m) {
//          cout << "interseccion de lineas " << i << " y " << j << endl;
//          cout << "da = " << out << endl;
          cnt[out].insert(i);
          cnt[out].insert(j);
        }
      }
    }
  }
//  cout << "ocupadas " << taken << endl;
//  cout << "intersecciones hay " << cnt.size() << endl;
  ll resta = 0;
  for(auto &x : cnt) {
    taken -= x.second.size()-1;
//    cout << "for pt = " << x.first.x << " " << x.first.y << endl;
    resta += x.second.size()-1;
//    for(auto &e : x.second) {
//      cout << e << endl;
//    }
  }
//  cout << "resta = " << resta << endl;
  cout << n*m - taken << endl;
 
  return 0;
}