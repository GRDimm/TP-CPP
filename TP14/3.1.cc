#include "3.1.h"

int Hat::num_hats_global_ = 0;

Hat* HatFactory::NewHat() {
    hats_.emplace_back(new Hat());
    return hats_.back().get();
}

HatFactory::~HatFactory(){
    
}