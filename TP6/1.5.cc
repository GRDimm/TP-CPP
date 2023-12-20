#include <iostream>

#include "1.5.h"

using namespace std;

int Uint2048::numAdditions = 0;

Uint2048::Uint2048() {
    for (int i = 0; i < 32; i++) {
        u_[i] = 0;
    }
}

Uint2048::Uint2048(int x) {
    for (int i = 0; i < 32; i++) {
        u_[i] = 0;
    }
    u_[0] = static_cast<uint64>(x);
}

Uint2048 Uint2048::operator+(const Uint2048& other) const {
  Uint2048 result;
  uint64 carry = 0;
  for (int i = 0; i < 32; ++i) {
    result.u_[i] = u_[i] + other.u_[i] + carry;
    // Detect overflows, which indicate that there should be a carry.
    // It's not that simple!
    if ((carry == 0 && result.u_[i] < u_[i]) ||
        (carry == 1 && result.u_[i] <= other.u_[i])) {
      carry = 1;
    } else {
      carry = 0;
    }
  }
  // The last carry is lost.
  numAdditions++;
  return result;
}

Uint2048 Uint2048::ComputeTwosComplement() const {
    Uint2048 twosComplement;
    for (int i = 0; i < 32; ++i) {
        twosComplement.u_[i] = ~u_[i]; //Inverser les bits
    }
    Uint2048 one(1);
    return twosComplement + one; //Complément à 2
}

Uint2048 Uint2048::operator-(const Uint2048& other) const {
    return *this + other.ComputeTwosComplement();
}

bool Uint2048::operator<(const Uint2048& other) const {
    for (int i = 31; i >= 0; i--) {
        if (u_[i] < other.u_[i]) {
            return true;
        } else if (u_[i] > other.u_[i]) {
            return false;
        }
    }
    return false;
}

void Uint2048::Print() const {
  // The difficulty is to print the number in base 10.
  // First, precompute *all* the powers of 10 that are smaller or equal to x.
  // Since 2^2048 ~= 10^616.5, we need up to 617 powers: 10^0...10^616.
  int p = 0;
  Uint2048 cur(1);  // 10^p
  Uint2048 p10[617];  // p10[i] will be equal to 10^i.
  p10[0] = cur;
  while (p < 616 && !(*this < cur)) {
    // Simple way of computing p10 * 10 with few additions.
    Uint2048 tmp2 = cur + cur;
    Uint2048 tmp4 = tmp2 + tmp2;
    Uint2048 tmp8 = tmp4 + tmp4;
    cur = tmp8 + tmp2; //5*tmp2
    p++;
    p10[p] = cur;
  }

  // Now, compute the digits in base 10, one by ones.
  Uint2048 s(0);
  if (p > 0) --p;
  while (p >= 0) {
    int d;  // Declared outside the "for" loop to keep its value after it's done
    for (d = 0; d < 10; ++d) {
      Uint2048 t = s + p10[p];
      if (*this < t) break;
      s = t;
    }
    cout << d;
    p--;
  }
}

// Ne peut pas être const car retourner un static => fonction static => non const
int Uint2048::NumAdditions(){
    return numAdditions;
}