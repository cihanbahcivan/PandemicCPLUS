#include "Kontrol.h"

Kontrol::Kontrol()
{
	Say();
	Olustur();
}

void Kontrol::Olustur()
{
	kisiler = new Kisi[LIMIT];
	mahalleRiskPuan = new float[MAHALLE_LIMIT];

	etkilesim1 = new int *[LIMIT];
	etkilesim2 = new int *[LIMIT];
	etkilesim3 = new int *[LIMIT];
	etkilesim4 = new int *[LIMIT];
	etkilesimMatris = new float *[LIMIT];
	iliski = new int *[LIMIT];
	maskeler = new Maske[LIMIT];
	mahalleNumara = new int[MAHALLE_LIMIT];

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesim1[i] = new int[LIMIT];
	}

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesim2[i] = new int[LIMIT];
	}

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesim3[i] = new int[LIMIT];
	}

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesim4[i] = new int[LIMIT];
	}

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesimMatris[i] = new float[LIMIT];
	}

	for (int i = 0; i < LIMIT; i++)
	{
		iliski[i] = new int[LIMIT];
	}
}

void Kontrol::ProgramMenu()
{
	EtkilesimOku();
	IliskiOku();
	KisiOku();
	MaskeKullanimi();
	EtkilesimGrafOlustur();

	int tercih = 0;
	int kaynakID = 0;
	int hedefID = 0;

	while (tercih != 7)
	{
		cout << "MENU" << endl;
		cout << "1- Iliski derecesi goster" << endl;
		cout << "2- Genel siralama hesapla" << endl;
		cout << "3- Mahalle bulasma riski hesapla" << endl;
		cout << "4- Temasli kisileri bul" << endl;
		cout << "5- Ilk vakayi tespit et" << endl;
		cout << "6- Etkilesim Graf Yazdir" << endl;
		cout << "7- Cikis yap" << endl;
		cin >> tercih;

		switch (tercih)
		{
		case 1:
			cout << "Kaynak ID girin :" << endl;
			cin >> kaynakID;
			cout << "Hedef ID girin :" << endl;
			cin >> hedefID;
			cout << endl;

			iliskiDerecesiGoster(kaynakID, hedefID);
			break;
		case 2:
			riskPuaniHesapla();
			genelSiralama();
			break;
		case 3:
			riskPuaniHesapla();
			mahalleBulasmaRiskiSiralama();
			break;
		case 4:
			temasliKisileriBul();
			break;
		case 5:
			riskPuaniHesapla();
			ilkVakaTespit();
			break;
		case 6:
			EtkilesimGrafPuan();
			break;
		default:
			break;
		}
	}
}

void Kontrol::Say()
{
	ifstream dosya;
	string satir = "";
	int counter = 0;
	int mahalleSayi = 0;
	dosya.open("kisiler.txt");
	if (dosya.is_open())
	{
		while (!dosya.eof())
		{
			getline(dosya, satir);

			satir = satir.substr(satir.find(',') + 1);

			satir = satir.substr(satir.find(',') + 1);

			satir = satir.substr(satir.find(',') + 1);

			int sayi = stoi(satir.substr(0, satir.find(',')));

			if (sayi > mahalleSayi)
			{
				mahalleSayi = sayi;
			}
			counter++;
		}

		LIMIT = counter;
		MAHALLE_LIMIT = mahalleSayi;
	}
}

void Kontrol::KisiOku()
{
	ifstream kisi;
	kisi.open("kisiler.txt");

	string satir = "", ad = "";
	int ID, mahalle, yas, cov19, kronik, sehirDisi;
	char cinsiyet;
	int counter = 0;

	if (kisi.is_open())
	{
		while (!kisi.eof())
		{

			getline(kisi, satir);

			ID = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			ad = satir.substr(0, satir.find(','));
			satir = satir.substr(satir.find(',') + 1);

			cinsiyet = satir.at(0);
			satir = satir.substr(satir.find(',') + 1);

			mahalle = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			yas = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			cov19 = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			kronik = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			sehirDisi = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);

			kisiler[counter].KisiEkle(ID, yas, mahalle, ad, cinsiyet, cov19, kronik, sehirDisi);
			counter++;
		}

		kisi.close();
	}
}

void Kontrol::EtkilesimOku()
{
	ifstream dosya;
	dosya.open("etkilesim1.txt");

	if (dosya.is_open())
	{
		for (int i = 0; i < LIMIT; i++)
		{
			for (int j = 0; j < LIMIT; j++)
			{
				if (i == j)
				{
					etkilesim1[i][j] = 0;
					dosya.get();
					dosya.get();
				}
				else
				{
					etkilesim1[i][j] = dosya.get() - '0';
					dosya.get();
				}
			}
		}
	}

	dosya.close();

	dosya.open("etkilesim2.txt");

	if (dosya.is_open())
	{

		for (int i = 0; i < LIMIT; i++)
		{
			for (int j = 0; j < LIMIT; j++)
			{
				if (i == j)
				{
					etkilesim2[i][j] = 0;
					dosya.get();
					dosya.get();
				}
				else
				{
					etkilesim2[i][j] = dosya.get() - '0';
					dosya.get();
				}
			}
		}
	}

	dosya.close();

	dosya.open("etkilesim3.txt");

	if (dosya.is_open())
	{
		for (int i = 0; i < LIMIT; i++)
		{
			for (int j = 0; j < LIMIT; j++)
			{
				if (i == j)
				{
					etkilesim3[i][j] = 0;
					dosya.get();
					dosya.get();
				}
				else
				{
					etkilesim3[i][j] = dosya.get() - '0';
					dosya.get();
				}
			}
		}
	}

	dosya.close();

	dosya.open("etkilesim4.txt");

	if (dosya.is_open())
	{
		for (int i = 0; i < LIMIT; i++)
		{
			for (int j = 0; j < LIMIT; j++)
			{
				if (i == j)
				{
					etkilesim4[i][j] = 0;
					dosya.get();
					dosya.get();
				}
				else
				{
					etkilesim4[i][j] = dosya.get() - '0';
					dosya.get();
				}
			}
		}
	}

	dosya.close();
}

void Kontrol::MaskeKullanimi()
{
	string satir = "";

	ifstream dosya;
	dosya.open("maske.txt");

	if (dosya.is_open())
	{
		for (int i = 0; i < LIMIT; i++)
		{
			getline(dosya, satir);

			int id = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);
			int gun1 = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);
			int gun2 = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);
			int gun3 = stoi(satir.substr(0, satir.find(',')));
			satir = satir.substr(satir.find(',') + 1);
			int gun4 = stoi(satir.substr(0, satir.find(',')));

			maskeler[i].MaskeEkle(id, gun1, gun2, gun3, gun4);
		}
	}
}

void Kontrol::IliskiOku()
{
	ifstream dosya;
	dosya.open("iliski.txt");

	if (dosya.is_open())
	{
		for (int i = 0; i < LIMIT; i++)
		{
			for (int j = 0; j < LIMIT; j++)
			{
				if (i == j)
				{
					iliski[i][j] == 0;
					dosya.get();
					dosya.get();
				}
				else
				{
					iliski[i][j] = dosya.get() - '0';
					dosya.get();
				}
			}
		}
	}
	dosya.close();
}

void Kontrol::ilkVakaTespit()
{
	Kisi *ilkVakalar = new Kisi[LIMIT];

	int vakaIndeks = 0;

	for (int i = 0; i < LIMIT; i++)
	{
		if (kisiler[i].getIlDisi() == true)
		{
			ilkVakalar[vakaIndeks] = kisiler[i];
			vakaIndeks++;
		}
	}

	for (int i = 0; i < vakaIndeks - 1; i++)
	{
		for (int j = 0; j < vakaIndeks - i - 1; j++)
		{
			if (ilkVakalar[j].getRiskPuan() > ilkVakalar[j + 1].getRiskPuan())
			{
				Kisi kisi = ilkVakalar[j];
				ilkVakalar[j] = ilkVakalar[j + 1];
				ilkVakalar[j + 1] = kisi;
			}
		}
	}

	cout << "kisiID isim riskPuani" << endl;

	for (int i = vakaIndeks; i > 0; i--)
	{
		ilkVakalar[i - 1].EkranaYazdir();
	}

	delete[] ilkVakalar;
}

void Kontrol::iliskiDerecesiGoster(int kaynak, int hedef)
{
	int kaynakIndeks = kaynak - 101;
	int hedefIndeks = hedef - 101;

	int iliskiKaynakIndeks = iliski[kaynakIndeks][hedefIndeks];

	if (iliskiKaynakIndeks == 3)
	{
		cout << "Ayni evde yaşayan kisiler" << endl;
	}
	else if (iliskiKaynakIndeks == 2)
	{
		cout << "Is arkadasi" << endl;
	}
	else if (iliskiKaynakIndeks == 1)
	{
		cout << "Arkadas" << endl;
	}
	else
	{
		cout << "Arkadas degil" << endl;
	}

	etkilesimHesapla(kaynakIndeks, hedefIndeks);
}

void Kontrol::etkilesimHesapla(int kaynakId, int hedefId)
{
	bool *gezilen = new bool[LIMIT];

	for (int i = 0; i < LIMIT; i++)
	{
		gezilen[i] = false;
	}

	int *etkilesimKisiler = new int[LIMIT];

	for (int i = 0; i < LIMIT; i++)
	{
		etkilesimKisiler[i] = 0;
	}

	gezilen[kaynakId] = true;

	if (YolRecursive(kaynakId, hedefId, gezilen, etkilesimKisiler, 0))
	{
		for (int i = 0; i < LIMIT; i++)
		{
			if (etkilesimKisiler[i] == 0)
				break;

			if (etkilesimKisiler[i] == (hedefId + 101))
			{
				cout << etkilesimKisiler[i] << endl;
				break;
			}
			else
			{
				cout << etkilesimKisiler[i] << " -> ";
			}
		}
	}
	cout << endl;

	delete[] gezilen;
	delete[] etkilesimKisiler;
}

void Kontrol::riskPuaniHesapla()
{
	float risk = 0.f;
	for (int i = 0; i < LIMIT; i++)
	{
		for (int j = 0; j < LIMIT; j++)
		{
			if (i != j)
			{
				risk += kisiler[i].getYasKatsayi() * kisiler[i].getKronikKatsayi() * kisiEtkilesimHesapla(kisiler[i].getID(), kisiler[j].getID());
			}
		}
		kisiler[i].setRiskPuan(risk);
		risk = 0.f;
	}
}

void Kontrol::temasliKisileriBul()
{
	cout << "Temasli Kisiler" << endl;

	for (int i = 0; i < LIMIT; i++)
	{
		if (kisiler[i].getCovid() == true)
		{
			cout << "Hasta kisi : " << kisiler[i].getAd() << endl;
			cout << "Hastaya temasli kisiler : " << endl;
			for (int j = 0; j < LIMIT; j++)
			{
				if (etkilesimMatris[i][j] != 0)
				{
					cout << kisiler[j].getAd() << endl;
				}
			}
			cout << "-----" << endl;
		}
	}
}

void Kontrol::mahalleRiskPuanHesapla()
{
	for (int i = 0; i < MAHALLE_LIMIT; i++)
	{
		mahalleRiskPuan[i] = 0;
		mahalleNumara[i] = i+1;
	}

	for (int i = 0; i < LIMIT; i++)
	{
		mahalleRiskPuan[kisiler[i].getMahalleID() - 1] += kisiler[i].getRiskPuan();
	}

	for (int i = 0; i < (MAHALLE_LIMIT - 1); i++)
	{
		for (int j = 0; j < (MAHALLE_LIMIT - 1) - i; j++)
		{
			if (mahalleRiskPuan[j] > mahalleRiskPuan[j + 1])
			{
				float mahalleRisk = mahalleRiskPuan[j];
				mahalleRiskPuan[j] = mahalleRiskPuan[j + 1];
				mahalleRiskPuan[j + 1] = mahalleRisk;

				int id = mahalleNumara[j];
				mahalleNumara[j] = mahalleNumara[j + 1];
				mahalleNumara[j + 1] = id;
			}
		}
	}
}

bool Kontrol::YolRecursive(int kaynak, int hedef, bool dizi[], int idDizi[], int indeks)
{
	if (etkilesimMatris[kaynak][hedef] > 0)
	{
		idDizi[indeks] = kaynak + 101;
		indeks++;
		idDizi[indeks] = hedef + 101;
		return true;
	}
	else
	{
		for (int i = 0; i < LIMIT; i++)
		{
			if (etkilesimMatris[kaynak][i] > 0 && dizi[i] != true)
			{
				dizi[i] = true;
				idDizi[indeks] = kaynak + 101;
				indeks++;
				if (YolRecursive(i, hedef, dizi, idDizi, indeks))
					return true;
				idDizi[indeks] = 0;
				indeks--;
			}
		}
	}
	return false;
}

void Kontrol::mahalleBulasmaRiskiSiralama()
{
	mahalleRiskPuanHesapla();

	cout << "mahalleID riskPuani" << endl;

	for (int i = MAHALLE_LIMIT; i > 0; i--)
	{
		cout << mahalleNumara[i - 1] << " " << mahalleRiskPuan[i - 1] << endl;
	}
}

float Kontrol::kisiEtkilesimHesapla(int id1, int id2)
{
	float toplam = 0.f;
	for (int i = 1; i < MAHALLE_LIMIT; i++)
	{
		toplam += etkilesimPuaniHesapla(id1, id2, i);
	}
	return toplam;
}

float Kontrol::etkilesimPuaniHesapla(int id1, int id2, int gun)
{
	float etkiKatsayi = 0.f;
	float iliskiKatsayi = 0.f;
	float maskeKatsayi = 0.f;

	id1 -= 101;
	id2 -= 101;

	switch (gun)
	{
	case 1:

		if (etkilesim1[id1][id2] == 1)
		{
			etkiKatsayi = 1.0;
		}
		else
		{
			etkiKatsayi = 0.0;
		}

		if (iliski[id1][id2] == 0)
		{
			iliskiKatsayi = 1.0;
		}
		else if (iliski[id1][id2] == 1)
		{
			iliskiKatsayi = 1.2;
		}
		else if (iliski[id1][id2] == 2)
		{
			iliskiKatsayi = 1.5;
		}
		else
		{
			iliskiKatsayi = 1.9;
		}

		break;

	case 2:
		if (etkilesim2[id1][id2] == 1)
		{
			etkiKatsayi = 1.0;
		}
		else
		{
			etkiKatsayi = 0.0;
		}

		if (iliski[id1][id2] == 0)
		{
			iliskiKatsayi = 1.0;
		}
		else if (iliski[id1][id2] == 1)
		{
			iliskiKatsayi = 1.2;
		}
		else if (iliski[id1][id2] == 2)
		{
			iliskiKatsayi = 1.5;
		}
		else
		{
			iliskiKatsayi = 1.9;
		}
		break;

	case 3:
		if (etkilesim3[id1][id2] == 1)
		{
			etkiKatsayi = 1.0;
		}
		else
		{
			etkiKatsayi = 0.0;
		}

		if (iliski[id1][id2] == 0)
		{
			iliskiKatsayi = 1.0;
		}
		else if (iliski[id1][id2] == 1)
		{
			iliskiKatsayi = 1.2;
		}
		else if (iliski[id1][id2] == 2)
		{
			iliskiKatsayi = 1.5;
		}
		else
		{
			iliskiKatsayi = 1.9;
		}
		break;

	case 4:
		if (etkilesim4[id1][id2] == 1)
		{
			etkiKatsayi = 1.0;
		}
		else
		{
			etkiKatsayi = 0.0;
		}

		if (iliski[id1][id2] == 0)
		{
			iliskiKatsayi = 1.0;
		}
		else if (iliski[id1][id2] == 1)
		{
			iliskiKatsayi = 1.2;
		}
		else if (iliski[id1][id2] == 2)
		{
			iliskiKatsayi = 1.5;
		}
		else
		{
			iliskiKatsayi = 1.9;
		}
		break;

	default:
		break;
	}
	maskeKatsayi = maskeler[id1].gunGetir(gun);

	float katsayiCarpim = etkiKatsayi * iliskiKatsayi * maskeKatsayi;

	return katsayiCarpim;
}

void Kontrol::EtkilesimGrafOlustur()
{
	for (int i = 0; i < LIMIT; i++)
	{
		for (int j = 0; j < LIMIT; j++)
		{
			if (i != j)
			{
				etkilesimMatris[i][j] = kisiEtkilesimHesapla(kisiler[i].getID(), kisiler[j].getID());
			}
			else
			{
				etkilesimMatris[i][j] = 0;
			}
		}
	}
}

void Kontrol::EtkilesimGrafPuan()
{
	for (int i = 0; i < LIMIT; i++)
	{
		for (int j = 0; j < LIMIT; j++)
		{
			cout << "(" << i + 101 << "," << j + 101 << ") = "  << setw(5) << left << etkilesimMatris[i][j] << "    ";
		}
		cout << endl
			 << endl;
	}
	cout << endl;
}

void Kontrol::genelSiralama()
{
	Kisi *siralamaKisiler = new Kisi[LIMIT];

	for (int i = 0; i < LIMIT; i++)
	{
		siralamaKisiler[i] = kisiler[i];
	}

	int i, j;

	for (i = 0; i < (LIMIT - 1); i++)
	{
		for (j = 0; j < (LIMIT - 1) - i; j++)
		{
			if (siralamaKisiler[j].getRiskPuan() > siralamaKisiler[j + 1].getRiskPuan())
			{
				Kisi kisi = siralamaKisiler[j];
				siralamaKisiler[j] = siralamaKisiler[j + 1];
				siralamaKisiler[j + 1] = kisi;
			}
		}
	}

	cout << "kisiID isim riskPuani" << endl;

	for (int i = LIMIT; i > 0; i--)
	{
		siralamaKisiler[i - 1].EkranaYazdir();
	}

	delete[] siralamaKisiler;
}

Kontrol::~Kontrol()
{
	delete[] kisiler;
	delete[] mahalleRiskPuan;
	delete[] maskeler;

	for (int i = 0; i < LIMIT; i++)
		delete[] etkilesim1[i];
	delete[] etkilesim1;

	for (int i = 0; i < LIMIT; i++)
		delete[] etkilesim2[i];
	delete[] etkilesim2;

	for (int i = 0; i < LIMIT; i++)
		delete[] etkilesim3[i];
	delete[] etkilesim3;

	for (int i = 0; i < LIMIT; i++)
		delete[] etkilesim4[i];
	delete[] etkilesim4;

	for (int i = 0; i < LIMIT; i++)
		delete[] etkilesimMatris[i];
	delete[] etkilesimMatris;

	for (int i = 0; i < LIMIT; i++)
		delete[] iliski[i];
	delete[] iliski;
	
	delete[] mahalleNumara;
}