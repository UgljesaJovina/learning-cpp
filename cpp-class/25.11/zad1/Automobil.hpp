#pragma once
#include "Skoljka.hpp"
#include "Menjac.hpp"

enum StanjeAutomobila {
    UGASEN, POKVAREN, U_VOZNJI
};

class Automobil {
    Menjac m;
    Skoljka s;

    StanjeAutomobila stanje;
    int trenutnaBrzina;
public:
    Automobil() : m(), s() { stanje = UGASEN; }
    Automobil(int bB, TipMenjaca tip, BojaSkoljke boja, StanjeAutomobila stanje, int trenutna)
        : m(bB, tip), s(boja) {
            this->stanje = stanje;
            trenutnaBrzina = trenutna;
        }
    Automobil(const Automobil& o) : m(o.m), s(o.s) { 
        stanje = o.stanje;
        trenutnaBrzina = o.trenutnaBrzina;
    }

    bool upali() {
        if (stanje != UGASEN) return false;

        stanje = U_VOZNJI;
        return true;
    }

    bool ugasi() {
        if (stanje != U_VOZNJI) return false;

        stanje = UGASEN;
        trenutnaBrzina = 0;
        return true;
    }

    bool pokvari() {
        if (stanje == POKVAREN) return false;

        stanje = POKVAREN;
        trenutnaBrzina = 0;
        return true;
    }

    bool popravi() {
        if (stanje != POKVAREN) return false;

        stanje = UGASEN;
        trenutnaBrzina = 0;
        return true;
    }

    bool povecajBrzinu() {
        if (stanje != U_VOZNJI) return false;

        if (trenutnaBrzina + 1 > m.getBrojBrzina()) return false;

        trenutnaBrzina++;

        return true;
    }

    bool smanjiBrzinu() {
        if (stanje != U_VOZNJI) return false;

        if (trenutnaBrzina - 1 < 0) return false;

        trenutnaBrzina--;

        return true;
    }

    bool setBrojBrzina(int broj) { return m.setBrojBrzina(broj); }
    void setBoja(BojaSkoljke boja) { s.setBoja(boja); }
    void setTipMenjaca(TipMenjaca tip) { m.setTip(tip); }

    int getBrojBrzina() const { return m.getBrojBrzina(); }
    TipMenjaca getTipMenjaca() const { return m.getTipMenjaca(); }
    BojaSkoljke getBoja() const { return s.getBoja(); }

    friend void napisiAuto(const Automobil& a);
};