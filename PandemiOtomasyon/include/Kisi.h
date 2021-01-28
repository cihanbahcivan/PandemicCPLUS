#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Kisi
{
public:
	Kisi();
	void KisiEkle(int, int, int, string, char, bool, bool, bool);
	void setRiskPuan(float);
	float getRiskPuan();
	int getID();
	int getYas();
	bool getKronik();
	int getMahalleID();
	float YasKatsayi();

	float getYasKatsayi();
	float getKronikKatsayi();
	
	string getAd();
	bool getCovid();
	bool getIlDisi();
	void EkranaYazdir();
private:
	int kisiID;
	int kisiYas;
	int mahalleID;
	string kisiAd;
	char kisiCinsiyet;
	bool covid19;
	bool kronikHasta;
	bool ilDisindaBulundu;

	float yasKatsayi;
	float kronikKatsayi;

	float riskPuan;
};

