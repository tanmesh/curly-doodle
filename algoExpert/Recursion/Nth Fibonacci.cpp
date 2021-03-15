using namespace std;

int getNthFib(int n) {
    int f0 = 0, f1 = 1;
    if(n == 1) {
        return f0;
    }
    if(n == 2) {
        return f1;
    }
  for(int i=2; i<=n; ++i) {
        int f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f0;
}
