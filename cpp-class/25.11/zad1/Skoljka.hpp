#pragma once

enum BojaSkoljke {
    ZELENA, CRVENA, PLAVA
};

class Skoljka
{
    BojaSkoljke bojaSkoljke;
public:
    Skoljka() { bojaSkoljke = PLAVA; }
    
    Skoljka(BojaSkoljke bojaSkoljke) { this->bojaSkoljke = bojaSkoljke; }

    Skoljka(const Skoljka& original) { bojaSkoljke = original.bojaSkoljke; }

    void setBoja(BojaSkoljke boja) { bojaSkoljke = boja; }

    BojaSkoljke getBoja() const { return bojaSkoljke; }
};