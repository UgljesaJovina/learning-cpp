#ifndef RERNA_HPP_INCLUDED
#define RERNA_HPP_INCLUDED

enum StanjeRerne {
    ISKLJUCENA,
    UKLJUCENA,
    POKVARENA
};

class Rerna
{
    StanjeRerne trenutnoStanje;
    int temperatura;
public:
    Rerna();

    bool ukljuci();
    bool iskljuci();
    bool popravi();
    bool pokvari();

    bool pojacajtemperaturu();
    bool smanjiTemperaturu();

    int getTemperatura() const;
    StanjeRerne getTrenutnoStanje() const;
};


#endif