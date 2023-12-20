#include "1.2.h"
#include <cmath>
#include <iostream>

using namespace std;

double Sequence::Value(){
    int step = getStep();
    if(step < n){
        return values[step];
    }else{
        return values[n-1];
    }
};

Sequence::Sequence(int n, double* values) : step(0), values(values), n(n) {}
Sequence::Sequence() : step(0), values(0), n(1) {}

FibonacciSequence::FibonacciSequence() : Sequence(2, new double[2]{0, 1}) {
    incrStep();
}

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

FibonacciSequence::FibonacciSequence(const FibonacciSequence& f) 
    : Sequence(f.n, new double[f.n]) { // Créez un nouveau tableau et copiez les valeurs
    // Copie en profondeur des valeurs de la séquence
    for (int i = 0; i < f.n; ++i) {
        this->getValues()[i] = f.getValues()[i];
    }
    // Copiez tout autre état nécessaire de f
    this->setStep(f.getStep());
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

void Sequence::setStep(int x){
    step = x;
}


ShiftSequence::ShiftSequence(Sequence* seq, int shift) : seq(seq), shift(shift) {
    for(int i=0; i < shift; i++){
        seq->Next();
    }
}

ShiftSequence::~ShiftSequence() {
    delete seq;
}

double ShiftSequence::Value() {
    if (seq) {
        return seq->Value();
    }
    return 0;
}

void ShiftSequence::Next() {
    if (seq) {
        seq->Next();
        incrStep();
    }
}