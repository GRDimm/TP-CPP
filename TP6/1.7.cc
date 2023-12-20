#include <iostream>

#include "1.7.h"

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

Uint2048::Uint2048(const Uint2048& other) {
    for (int i = 0; i < 32; i++) {
        u_[i] = other.u_[i];
    }
}

bool Uint2048::operator==(const Uint2048& other) const {
    for (int i = 0; i < 32; ++i) {
        if(u_[i] != other.u_[i]){
            return false;
        }
    }
    return true;
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

Uint2048& Uint2048::operator=(const Uint2048& other) {
    if (this != &other) {
        for (int i = 0; i < 32; ++i) {
            this->u_[i] = other.u_[i];
        }
    }
    return *this;
}

Uint2048 Uint2048::operator>>(int n) const {
        Uint2048 result;
        int shiftElements = n / 64;
        int shiftBits = n % 64;

        for (int i = 0; i < 32 - shiftElements; i++) {
            result.u_[i] |= (u_[i + shiftElements] >> shiftBits);
            if (i < 32 - shiftElements - 1 && shiftBits > 0) {
                result.u_[i] |= (u_[i + shiftElements + 1] << (64 - shiftBits));
            }
        }

        return result;
    }

Uint2048 Uint2048::operator<<(int n) const {
    Uint2048 result;
    int shiftElements = n / 64;
    int shiftBits = n % 64;

    for (int i = 0; i < 32 - shiftElements; i++) {
        result.u_[i + shiftElements] |= (u_[i] << shiftBits);
        if (i < 32 - shiftElements - 1 && shiftBits > 0) {
            result.u_[i + shiftElements + 1] |= (u_[i] >> (64 - shiftBits));
        }
    }

    return result;
}



// O(2048^2)
// While tourne 2048 fois max et 7 opérations en O(2048) max dedans : 3*"=", "==", "+", "<<" et ">>".
Uint2048 Uint2048::operator*(const Uint2048& other) const {
    Uint2048 r = 0;
    Uint2048 zero = 0;


    Uint2048 tempX(*this);
    Uint2048 tempY(other);

    while (!(tempX == zero)) {

        if (tempX.u_[0] & 1) { // Bit de poids faible == 1 implique impair
            r = r + tempY;
        }

        tempX = tempX >> 1; // Div par 2
        tempY = tempY << 1; // Mult par 2
    }

    return r;
}


//Le premier while tourne au plus 2048 fois et le 2e aussi donc OK
Uint2048 Uint2048::operator/(const Uint2048& other) const {
    Uint2048 quotient = 0;
    Uint2048 dividend(*this); // Dividende initial
    Uint2048 divisor = other;  // Diviseur

    while (!(dividend < divisor)) {
        Uint2048 temp = divisor; // Utilise une copie du diviseur

        // Recherche du plus grand facteur de multiplication
        int shift = 0;
        while (!(dividend < (temp << 1)) && (!((temp << 1) < temp))) {
            temp = temp << 1;
            shift++;
        }
        
        // Soustrait le facteur du dividende et met à jour le quotient
        dividend = dividend - temp;
        quotient = quotient + (Uint2048(1) << shift);
    }

    return quotient;
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