#ifndef IMEKLASE_HPP_INCLUDED
#define IMEKLASE_HPP_INCLUDED

class ImeKlase {
    int id;
    double stanje;

public:
    ImeKlase(); // base constructor
    ImeKlase(int, double); // constructor with parameters
    ImeKlase(const ImeKlase&); // copy constructor

    int getId();
    double getStanje();
    int asd() {
        return 300;
    }
};

#endif // IMEKLASE HPP INCLUDED