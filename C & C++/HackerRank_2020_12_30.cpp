#include <iostream>
#include <assert.h>
#include <limits>
#include <string>
#include <vector>
#include <math.h>
#include <tuple>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;

// URL: https://www.hackerrank.com/challenges/array-left-rotation/problem

template <typename T>
vector <T> sub(vector <T> V, int a = 0, int b = -1) {
    if (b == -1) { b = V.size(); }
    assert((a >= 0) && (b <= V.size()));
    return vector <int> (V.begin() + a, V.begin() + b); }

vector <int> rotate_left(int d, vector <int> V) {
    while (d--) {
        int first = V[0];
        V = sub(V, 1, -1);
        V.push_back(first); }
    return V; }
    
// URL: https://www.hackerrank.com/challenges/merge-the-tools/problem

vector <string> merge_the_tools(string S, int k) {
    int N = S.size()/k;
    vector <string> V = {};
    for (int n = 0; n < N; n++) {
        string sub1 = S.substr(k*n, k), sub2 = "";
        set <string> ltrs = {};
        for (int j = 0; j < k; j++) {
            ltrs.insert(sub1.substr(j, 1)); }
        for (string ltr : ltrs) { sub2 += ltr; }
        V.push_back(sub2); }
    return V; }

// URL: https://www.hackerrank.com/challenges/coin-change/problem

int combs(vector <int> C, int n, int m) {
    if (n == 0) return 1;
    if (n <= 0) return 0;
    if (m <= 0) return 0;
    int q = 0, c = C[m - 1];
    q += combs(C, n - c, m);
    q += combs(C, n, m - 1);
    return q; }

// URL: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

tuple <int, int> breaking_records(vector <int> Sc) {
    int nMax = -1, Max = INT_MIN;
    int nMin = -1, Min = INT_MAX;
    for (int s : Sc) {
        if (s < Min) { nMin++; Min = s; }
        if (s > Max) { nMax++; Max = s; } }
    return make_tuple(nMin, nMax); }

// URL: https://www.hackerrank.com/challenges/day-of-the-programmer/problem

string n_day(int y, int d = 256) {
    string S = to_string(y); int m = 0;
    vector <int> M = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
    bool leap_1 = (y < 1918) && (y % 4 == 0);
    bool leap_2 = (y > 1918) && (y % 400 == 0);
    bool leap_3 = (y > 1918) && (y % 100) && (y % 4 == 0);
    M[2] += 1*(leap_1 || leap_2 || leap_3) - 13*(y == 1918);
    while (true) {
        if (d <= M[m]) { break; }
        else { d -= M[m++]; } }
    S = to_string(m + 1) + "." + S;
    if (m < 9) { S = "0" + S; }
    S = to_string(d) + "." + S;
    if (d < 10) { S = "0" + S; }
    return S; }

// URL: https://www.hackerrank.com/challenges/crush/problem

float array_manipulation(int l, vector <vector <float>> Q) {
    vector <float> V(l, 0.0); 
    for (vector <float> q : Q) {
        int a = q[0], b = q[1]; float k = q[2];
        assert((0 < a) && (a <= b) && (b <= l));
        V[a - 1] += k; if (b < l) { V[b] -= k; } }
    float Max = 0, X = 0;
    for (float v : V) {
        X += v;  Max = (Max < X)? X : Max; }
    return Max; }

// URL: https://www.hackerrank.com/challenges/sparse-arrays/problem

template <typename T>
vector <int> sparse_arrays(vector <T> V, vector <T> Q) {
    vector <int> W(Q.size(), 0);
    for (int i = 0; i < Q.size(); i++) { T q = Q[i];
        for (int j = 0; j < V.size(); j++) { T v = V[j];
            if (q == v) { W[i]++; } } }
    return W; }

// Solution printer

template <typename T>
ostream & operator << (ostream & out, const vector <T> & v) {
    out << "{";
    for (size_t i = 0; i < v.size(); i++) {
        if (i != 0) { out << ", "; }
        out << v[i]; }
    out << "}";
    return out; }

template <typename T>
ostream & operator << (ostream & out, const set <T> & v) {
    out << "{";
    for (size_t i = 0; i < v.size(); i++) {
        if (i != 0) { out << ", "; }
        out << v[i]; }
    out << "}";
    return out; }

template <typename T>
ostream & operator << (ostream & out, const tuple <T, T> & v) {
    out << "(" << get <0> (v) << ", ";
    out << get <1> (v) << ")" << endl;
    return out; }

int main() {
    vector <int> V = {1, 2, 2, 1, 2};
    vector <int> Q = {1, 2, 3};
    vector <int> W = sparse_arrays(V, Q);
    cout << "sparse_arrays(" << V << ", ";
    cout << Q << ") = " << W << endl; }