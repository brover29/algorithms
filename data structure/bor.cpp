int t[nlog], lv[nlog], rv[nlog], cnt[nlog]

t[v] = 0 // swap chetnoe raz
t[v] = 1 // swap nechetnoe kol-vo raz

int timer = 1;

void add(int x) {
  int v = 1;
  cnt[v] ++;
  for(int bit = 29; bit >= 0; -- bit) {
    if((x >> bit) & 1) {
      if(!lv[v]) lv[v] = ++timer;
      v = lv[v];
    } else {
      if(!rv[v]) rv[v] = ++timer;
      v = rv[v];
    }
    cnt[v]++;
  }
}

int get(int x) {
  int v = 1, res = 0, sum = 0;
  for(int bit = 29; bit >= 0; -- bit) {
    if(((totalupdate >> bit) & 1) != t[v]) {
      swap(lv[v], rv[v]);
      t[v] ^= 1;
    }
    if(sum + (1 << bit) > x) {
      // не можем пойти в 1
      if(!rv[v]) break;
      v = rv[v];
    } else {
      // можем пойти и в 1 и в 0
      res += cnt[rv[v]];
      if(!lv[v]) break;
      v = lv[v], sum += (1 << bit);
    }
  }
  return res;
}

for(int i = 1; i <= n; ++ i) {
  cin >> a[i];
  add(a[i]);
}

int totalupdate = 0;

if(tp == 1) {
  int x; cin >> x;
  totalupdate ^= x;
} else cout << get(r) - get(l - 1);
