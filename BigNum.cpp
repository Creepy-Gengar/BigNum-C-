typedef vector <int> BigInt;
typedef long long int ll;
string na, nb;
BigInt A, B;
void Printl(BigInt N) {
    for (int j = N.size() - 1; j >= 0; j--)
        cout << N[j];
    cout << endl;
}
void RemZero(BigInt& N) {
    while (N.size() > 1 && !N.back()) N.pop_back();
}
int Larger_Smaller(BigInt A, BigInt B) {
    if (A.size() > B.size()) return 1;
    if (A.size() < B.size()) return -1;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] > B[i]) return 1;
        if (A[i] < B[i]) return -1;
    }
    return 0;
}
BigInt Str2BInt(string N) {
    BigInt C;
    for (int k = N.size() - 1; k >= 0; k--)
        C.push_back(N[k] - '0');
    RemZero(C);
    return C;
}
BigInt operator+ (BigInt A, BigInt B) {
    int ans = 0;
    BigInt C;
    while (A.size() < B.size()) A.push_back(0);
    while (A.size() > B.size()) B.push_back(0);
    int l = A.size();
    for (int i = 0; i < l; i++) {
        ans += A[i] + B[i];
        C.push_back(ans % 10);
        ans /= 10;
    }
    if (ans) C.push_back(ans);
    RemZero(C);
    return C;
}
BigInt operator- (BigInt A, BigInt B) {
    int ans = 0;
    BigInt C;
    while (A.size() < B.size()) A.push_back(0);
    while (A.size() > B.size()) B.push_back(0);
    int l = A.size();
    for (int i = 0; i < l; i++) {
        int r = A[i] - B[i] - ans;
        if (r < 0)
            r += 10, ans = 1;
        else ans = 0;
        C.push_back(r);
    }
    RemZero(C);
    return C;
}
BigInt operator* (BigInt A, ll b) {
    ll ans = 0;
    BigInt C;
    for (int i = 0; i < A.size(); i++) {
        ans += A[i] * b;
        C.push_back(ans % 10);
        ans /= 10;
    }
    if (ans) {
        while (ans)
            C.push_back(ans % 10), ans /= 10;
    }
    RemZero(C);
    return C;
}
BigInt operator* (BigInt A, BigInt B) {
    BigInt c, m, a;
    for (int i = 0; i < B.size(); i++) {
        a = A * B[i];
        a.insert(a.begin(), m.begin(), m.end());
        m.push_back(0);
        c = c + a;
    }
    RemZero(c);
    return c;
}