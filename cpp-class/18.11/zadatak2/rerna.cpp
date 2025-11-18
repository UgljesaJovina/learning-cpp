#include "rerna.hpp"

#define KORAK 20

Rerna::Rerna() {
    temperatura = 0;
    trenutnoStanje = ISKLJUCENA;
} 

bool Rerna::ukljuci() {
    if (trenutnoStanje != ISKLJUCENA) return false;
    
    trenutnoStanje = UKLJUCENA;
    temperatura += KORAK;
    return true;

}

bool Rerna::iskljuci() {
    if (trenutnoStanje != UKLJUCENA) return false;

    trenutnoStanje = ISKLJUCENA;
    temperatura = 0;
    return true;
}

bool Rerna::pokvari() {
    if (trenutnoStanje == POKVARENA) return false;

    trenutnoStanje = POKVARENA;
    temperatura = 0;
    return true;
}

bool Rerna::popravi() {
    if (trenutnoStanje != POKVARENA) return false;

    trenutnoStanje = ISKLJUCENA;
    temperatura = 0;
    return true;
}

bool Rerna::pojacajtemperaturu() {
    if (!(trenutnoStanje == UKLJUCENA && temperatura + KORAK <= 220)) return false;
    temperatura += KORAK;
    return true;
}

bool Rerna::smanjiTemperaturu() {
    if (!(trenutnoStanje == UKLJUCENA && temperatura - KORAK <= 220)) return false;
    temperatura -= KORAK;
    return true;
}

int Rerna::getTemperatura() const {
    return temperatura;
}

StanjeRerne Rerna::getTrenutnoStanje() const {
    return trenutnoStanje;
}