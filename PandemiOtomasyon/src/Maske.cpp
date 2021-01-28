#include "Maske.h"

Maske::Maske()
{
    ID = 0;
    gun1 = 0;
    gun2 = 0;
    gun3 = 0;
    gun4 = 0;
}

void Maske::MaskeEkle(int maskeID, int maskeGun1, int maskeGun2, int maskeGun3, int maskeGun4)
{
    ID = maskeID;
    gun1 = maskeGun1;
    gun2 = maskeGun2;
    gun3 = maskeGun3;
    gun4 = maskeGun4;
}

int Maske::maskeIDGetir()
{
    return ID;
}

int Maske::gunGetir(int gun)
{
    if(gun == 1)
    {
        if(gun1 == 0)
            return 3;
        else
            return 1;
    }
    else if(gun == 2)
    {
        if(gun2 == 0)
            return 3;
        else
            return 1;
    }
    else if(gun == 3)
    {
        if(gun3 == 0)
            return 3;
        else
            return 1;
    }
    else
    {
        if(gun4 == 0)
            return 3;
        else
            return 1;
    }
}