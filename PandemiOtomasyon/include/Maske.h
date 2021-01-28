#pragma once

class Maske
{
public:
    Maske();
    void MaskeEkle(int, int, int,int, int);
    int maskeIDGetir();
    int gunGetir(int);
private:
    int gun1;
    int gun2;
    int gun3;
    int gun4;
    int ID;
};