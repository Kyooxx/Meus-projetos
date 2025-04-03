#include <stdio.h>
#include <stdlib.h>
#include "relogio.h"

struct Relogio {
    int horas;
    int minutos;
    int segundos;
};

Relogio *criar_relogio(int h, int m, int s) {
    Relogio *r = (Relogio *)malloc(sizeof(Relogio));
    if (r) {
        r->horas = h;
        r->minutos = m;
        r->segundos = s;
    }
    return r;
}

void destruir_relogio(Relogio *r) {
    free(r);
}

void incrementar_segundo(Relogio *r) {
    r->segundos++;
    if (r->segundos >= 60) {
        r->segundos = 0;
        r->minutos++;
    }
    if (r->minutos >= 60) {
        r->minutos = 0;
        r->horas++;
    }
    if (r->horas >= 24) {
        r->horas = 0;
    }
}

void exibir_horario(const Relogio *r) {
    printf("Horário: %02d:%02d:%02d\n", r->horas, r->minutos, r->segundos);
}

