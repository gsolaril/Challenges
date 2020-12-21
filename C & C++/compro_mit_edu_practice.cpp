#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <set>
#include <map>
using namespace std;

/* An array with an odd number of elements is said to be centered if all numbers (except the middle one)
are strictly greater than the value of the middle element. Note that only arrays with an odd number of
elements have a middle element. Write a function that accepts an integer array and returns "1" if it is
a centered array, otherwise it returns "0". */

bool Exercise_1(vector <int> V) {
    if (V.size() % 2 == 0) { return false; }
    if (V.size() == 1) { return true; }
    int mid = (int) V.size()/2;
    for (int i = 0; i < V.size(); i++) {
        if (i == mid) { continue; }
        if (V[i] <= V[mid]) { return false; } }
    return true; }

/* Write a function that takes an array of integers as an argument and gives the difference between the
sums of odd and even numbers. */

int Exercise_2(vector <int> V) {
    int evn = 0, odd = 0;
    for (int i = 0; i < V.size(); i++) {
        if (V[i] % 2) { odd += V[i]; } else { evn += V[i]; } }
    return odd - evn; }

/* Write a function that accepts a character array, a zero-based start position and a length. It should
give a character array containing containing length characters starting with the start character of the
input array. The function should do error checking on the start position and the length and return null
if the either value is not legal. */  

vector <int> Exercise_3(vector <int> V, int S, int L) {
    if (L == 0) { return {}; }
    if (L < 0 || S < 0) { return {NULL}; }
    if (S + L > V.size()) { return {NULL}; }
    auto first = V.cbegin() + S;
    auto last = V.cbegin() + S + L;
    return vector <int> (first, last); }

/* Write a function to reverse an integer using numeric operators and without using any arrays or other
data structures. */

int Exercise_4(int N) {
    if (N < 10) { return N; }
    int rev = 0, exp = 1 + (int) log10(N);
    while (exp--) { rev += (N % 10)*pow(10, exp);  N /= 10; }
    return rev; }

/* Write a function to return an array containing all elements common to two given arrays containing
distinct positive integers. You should not use any inbuilt methods. You are allowed to use any number
of arrays. The signature of the function is: "int[] f(int[] first, int[] second)" */

vector <int> Exercise_5(vector <int> A, vector <int> B) {
    vector <int> R = {}; bool flag = false;
    for (int a : A) {
        for (int r : R) {
            if (a == r) { flag = true; continue; } }
        if (flag) { continue; }
        for (int b : B) {
            if (a == b) { R.push_back(b); break; } } }
    return R; }

/* An integer "x" is called a "point of equilibrium" of array "A", if there is one "x" such that:
"A[0] + A[1] + .... + A[x – 1] = A[x + 1] + A[x + 2] + .... + A[L – 1]". Write a function to find
"x" of an array if it exists. Else, show "-1". */

int Exercise_6(vector <int> V) {
    int SL = 0, SR = - V[0];
    for (int v : V) { SR += v; }
    for (int x = 1; x < V.size(); x++) {
        SL += V[x - 1]; SR -= V[x];
        if (SL == SR) { return x; } }
    return -1; }

// Insert solution here:

int main() {
    vector <int> V = {1, 2, 1, 1, 4};
    int R = Exercise_6(V);
    cout << R << ", ";
    return 0; }