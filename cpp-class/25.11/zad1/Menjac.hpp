#pragma once

enum TipMenjaca {
    MANUAL, AUTOMATIC
};

class Menjac {
    int brojBrzina;
    TipMenjaca tipMenjaca;
public:
    Menjac() {
        brojBrzina = 5;
        tipMenjaca = AUTOMATIC;
    }

    Menjac(int brojBrzina, TipMenjaca tipMenjaca) {
        this->brojBrzina = brojBrzina;
        this->tipMenjaca = tipMenjaca;
    }

    Menjac(const Menjac& original) {
        brojBrzina = original.brojBrzina;
        tipMenjaca = original.tipMenjaca;
    }

    bool setBrojBrzina(int broj) {
        if (broj == 5 || broj == 6) {
            brojBrzina = broj;
            return true;
        }

        return false;
    }

    void setTip(TipMenjaca tip) { tipMenjaca = tip; }

    int getBrojBrzina() const { return brojBrzina; }

    TipMenjaca getTipMenjaca() const { return tipMenjaca; }
};