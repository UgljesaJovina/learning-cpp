#include "imeKlase.hpp"

// constructor bez parametara se koristi za postavljanje default vrednosti
ImeKlase::ImeKlase() { 
    id = 0;
    stanje = 0;

    // this->id = 0;
    // this->stanje = 0;
}

ImeKlase::ImeKlase(int id, double stanje) {
    this->id = id;
    this->stanje = stanje;
}

ImeKlase::ImeKlase(const ImeKlase &original) {
    // originalni objekat proslednje po referenci
    id = original.id;
    stanje = original.stanje;
}

int ImeKlase::getId() {
    return id;
}

double ImeKlase::getStanje() {
    return stanje;
}