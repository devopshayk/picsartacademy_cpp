#include "ZABS.hpp"
#include <iostream>

int main() {
    Lion simba("Simba");

    Animal* a = &simba;
    IVoice* v = &simba;
    IWalk* w = &simba;
    IFeedable* f = &simba;

    a->PrintInfo();
    v->Voice();
    w->Walk();
    f->Feed();
    a->PrintInfo();

    return 0;
}
