#pragma once

#include <iostream>
#include <iomanip>
#include "Kisi.h"
#include "Maske.h"

using namespace std;

class Kontrol
{
public:
    int LIMIT = 0;
    int MAHALLE_LIMIT = 0;

    Kisi *kisiler;
    float *mahalleRiskPuan;

    int **etkilesim1;
    int **etkilesim2;
    int **etkilesim3;
    int **etkilesim4;
    float **etkilesimMatris;
    int **iliski;
    Maske *maskeler;
    int *mahalleNumara;

    Kontrol();

    void Olustur();
    void Say();
    void KisiOku();
    void EtkilesimOku();
    void ProgramMenu();
    void MaskeKullanimi();
    void IliskiOku();
    float kronikKatsayi();

    void EtkilesimGrafPuan();
    void ilkVakaTespit();
    void iliskiDerecesiGoster(int, int);
    void etkilesimHesapla(int, int);
    float kisiEtkilesimHesapla(int, int);
    float etkilesimPuaniHesapla(int, int, int);
    void riskPuaniHesapla();
    void temasliKisileriBul();
    void mahalleRiskPuanHesapla();
    void mahalleBulasmaRiskiSiralama();
    void EtkilesimGrafOlustur();
    bool YolBul(int[], bool[], int, int, int);
    bool YolRecursive(int, int, bool[], int[], int);
    void genelSiralama();

    ~Kontrol();

private:
};
