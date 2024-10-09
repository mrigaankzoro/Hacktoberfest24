#include <iostream>

/* Notes
- any algorithm for multiplying two numbers of n-digits, it takes 2n computation
steps
- any algorithm for adding two numbers of n-digits, it takes n computation steps
- Elementary school algorithm have complexity of - O(n^2)

x = a*10^n/2 + b
if a num = ab, n = number of digits
*/

#define ll long long

ll pow(ll a, ll b) {
  ll res = 1;
  for (int i = 0; i < b; i++)
    res *= a;
  return res;
}

// recursive function
ll karatsuba(ll x, ll y) {
  if (x < 10 || y < 10)
    return x * y;
  ll temp = x;
  int n, n_x = 0, n_y = 0;

  while (temp) {
    n_x++;
    temp /= 10;
  }

  temp = y;
  while (temp) {
    n_y++;
    temp /= 10;
  }

  n = std::max(n_x, n_y);
  ll half = n / 2;

  ll a = x / pow(10, half);
  ll b = x % pow(10, half);
  ll c = y / pow(10, half);
  ll d = y % pow(10, half);

  ll ac = karatsuba(a, b);
  ll bd = karatsuba(b, d);
  ll ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

  return ac * pow(10, 2 * half) + (ad_plus_bc * pow(10, half)) + bd;
}

// testing the code
int main(void) {
  ll a, b;
  std::cout << "Enter num1: ";
  std::cin >> a;
  std::cout << "Enter num2: ";
  std::cin >> b;

  std::cout << "Normal Multiplication: " << a * b << std::endl;
  std::cout << "Karatsuba's Multiplication: " << karatsuba(a, b) << std::endl;

  return 0;
}
