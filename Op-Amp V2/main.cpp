//
// Created by harry on 20/11/2024.
//

#include "op_amp.h"

using namespace std;

op_amp Amp;
int main() {
    Amp.set_type("inverting");
    Amp.set_Rf(100000);
    Amp.set_Rin(1000);
    Amp.get_gain();
}
