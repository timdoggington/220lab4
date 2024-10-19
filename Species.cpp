//
// Created by Alex Chambers on 10/16/24.
//
#include "Species.hpp"

#include <iostream>
#include <string>
using namespace std;

Species::Species(string s, string st, string inf) {
    name = s;
    status = st;
    info = inf;
}

Species::Species() {
    name = "";
    status = "";
    info = "";
}


