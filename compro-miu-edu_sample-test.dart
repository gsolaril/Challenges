import "dart:io";
import "dart:math";

void main() { stdout.writeln(exercise_6([1, 2, 10, 3, 4])); }

/* 1) An array with an odd number of elements is said to be centered if
      all elements (except the middle one) are strictly greater than the
      value of the middle element. Note only arrays with an odd number
      of elements have a middle element. Write a function that accepts an
      integer array and returns 1 if it is a centered array, otherwise it
      returns 0. */

int exercise_1(List <int> X) {
    if (X.length % 2 == 0) { return 0; }
    int mid = (X.length - 1)~/2; // "~/" es "//" en Python
    for (int n = 0; n < X.length; n++) {
        if (n == mid) { continue; }
        if (X[n] <= X[mid]) { return 0; } }
    return 1; }

/* 2) Write a function that takes an array of integers as an argument
      and returns a value based on the sums of the even and odd numbers
      in the array. Let "X = the sum of the odd numbers in the array"
      and let "Y = the sum of the even numbers". The function should
      return "X – Y". */

int exercise_2(List <int> X) {
    List <int> X0 = X.where((x) => (x % 2 == 0)).toList();
    List <int> X1 = X.where((x) => (x % 2 == 1)).toList();
    int x0 = 0;            X0.forEach((int e) {x0 += e;});
    int x1 = 0;            X1.forEach((int e) {x1 += e;});
    return x1 - x0; }

/* 3) Write a function that accepts a character array, a zero-based start
      position and a length. It should return a character array containing
      "length" characters starting with the "start" character of the input
      array. The function should do error checking on the start position and
      the length and return null if the either value is not legal. */

List <String> exercise_3(List <String> X, int x0, int xF) {
    if (x0 - xF == 1) { return []; }
    if (x0 < 0 || xF <= 0 || xF <= x0) { return null; }
    if (x0 >= X.length || xF > X.length) { return null; }
    return X.sublist(x0, xF); }

/* 4) Write a function to reverse an integer using numeric operators and
      without using any arrays or other data structures. */
    
int exercise_4(int N) {
    double logN = log(N.abs())/log(10);
    int rev = 0, ds = logN.toInt() + 1;
    for (int p = 1; p <= ds; p++) {
        int c1 = (N.abs() ~/ pow(10, p - 1));
        int c2 = (N.abs() ~/ pow(10, p)*10);
        rev += pow(10, ds - p)*(c1 - c2); }
    return rev*N.sign; }

/* 5) Write a function to return an array containing all elements common to 2
      given arrays containing distinct positive integers. You should not use
      any inbuilt methods. You are allowed to use any number of arrays. */

List <int> exercise_5(List <int> A, List <int> B) {
    Set <int> A_set = A.toSet(), B_set = B.toSet();
    if (A_set.length != A.length) { return null; }
    if (B_set.length != B.length) { return null; }
    return A_set.intersection(B_set).toList(); }

/* 6) Consider an array A with n of positive integers. An integer "x" is
      called a "point of equilibrium" of "A", if there is one "x" such that
      "A[0] + A[1] + .... + A[x – 1] = A[x + 1] + A[x + 2] + .... + A[L – 1]".
      Write a function to find "x" of an array if it exists. Else, show "-1". */

int exercise_6(List <int> X) {
    int sum_L = X[0], sum_R = - X[0] - X[1];
    X.forEach((int x) {sum_R += x;});
    for (int x = 1; x < X.length - 1; x++) {
        if (sum_L == sum_R) { return x; }
        sum_L += X[x];  sum_R -= X[x + 1]; }
    return -1; }