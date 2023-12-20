#include "1.1.h"
#include <cmath>

double Sequence::Value(){
    int step = getStep();
    if(step < n){
        return values[step];
    }else{
        return values[n-1];
    }
};

Sequence::Sequence(int n, double* values) : step(0), n(n), values(values) {}
Sequence::Sequence() : step(0), n(1), values(0) {}

FibonacciSequence::FibonacciSequence() : Sequence(2, new double[2]{0, 1}) {}

Sequence::~Sequence(){
    delete[] values;
}

double* Sequence::getValues(){
    return values;
}

void Sequence::incrStep(){
    step++;
}

int Sequence::getStep(){
    return step;
}

void FibonacciSequence::Next(){
    double* values = getValues();
    double temp = values[0];

    values[0] = values[1];
    values[1] = values[1] + temp;

    incrStep();
}

// 1, 1, 2, 6, 24, 120, 720, ... modulo x: if x = 10, that's
// 1, 1, 2, 6, 4, 0, 0, ...
FactorialModXSequence::FactorialModXSequence(int x) : Sequence(1, new double[1]{1}), x(x){}

void FactorialModXSequence::Next() {
    double* values = getValues();
    incrStep();
    int currentStep = getStep();
    values[0] *= currentStep;
    values[0] = fmod(values[0], static_cast<double>(x));
}

double FactorialModXSequence::Value(){
    return Sequence::Value();
}