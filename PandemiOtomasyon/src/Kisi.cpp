#include "Kisi.h"

Kisi::Kisi()
{
}

int Kisi::getID()
{
	return kisiID;
}

int Kisi::getYas()
{
	return kisiYas;
}

int Kisi::getMahalleID()
{
	return mahalleID;
}

bool Kisi::getCovid()
{
	return covid19;
}

bool Kisi::getKronik()
{
	return kronikHasta;
}

bool Kisi::getIlDisi()
{
	return ilDisindaBulundu;
}

float Kisi::YasKatsayi()
{
	if (kisiYas <= 5)
	{
		return 0.2;
	}
	else if (kisiYas <= 20)
	{
		return 0.5;
	}
	else if (kisiYas <= 55)
	{
		return 1.0;
	}
	else if (kisiYas <= 75)
	{
		return 1.7;
	}
	else
	{
		return 2.0;
	}
}

string Kisi::getAd()
{
	return kisiAd;
}

float Kisi::getYasKatsayi()
{
	return yasKatsayi;
}

float Kisi::getKronikKatsayi()
{
	return kronikKatsayi;
}


void Kisi::KisiEkle(int id, int yas, int mahID, string ad, char cinsiyet, bool covid, bool kronik, bool ilDisi)
{
	kisiID = id;
	kisiYas = yas;
	mahalleID = mahID;
	kisiAd = ad;
	kisiCinsiyet = cinsiyet;
	covid19 = covid;
	kronikHasta = kronik;
	ilDisindaBulundu = ilDisi;

	riskPuan = 0;

	yasKatsayi = YasKatsayi();
	kronikKatsayi = (kronikHasta != true) ? 1.0f : 1.7f;
}

float Kisi::getRiskPuan()
{
	return riskPuan;
}

void Kisi::setRiskPuan(float puan)
{
	riskPuan = puan;
}

void Kisi::EkranaYazdir()
{
	cout << kisiID << " " << kisiAd << " " << riskPuan << endl;
}