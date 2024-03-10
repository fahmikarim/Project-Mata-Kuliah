#include <iostream>
#include <iomanip>
#include <fstream>
//#include <stdlib.h>
//#include <string>
//#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
    {
        int id;
        string nama;
        int stok;
        int harga;
    }dt;
    dt data[1000]; dt temp[1000];dt temp1[1000], temp2[1000], temp3[1000];
    string file_temp = "temp.txt";


string replaceSpasi(string str);
string replaceUnderscore(string str);

int jumlah;
void input(dt data[]);
void output(dt data[]);

void searching(dt data[]);
void sequential(dt data[]);
void binary(dt data[]);

void sorting(dt data[]);
void bubble(dt data[]);
void selection(dt data[]);
void insertion(dt data[]);
void shell(dt data[]);

void transaksi();
void merginsambung();
void update();
void split(dt data[]);
void merging();
int shell_sort(dt array[], int jumlah3);


string replaceSpasi(string str)
{
	for (int i = 0; str[i]; i++)
	{ 
		if (str[i] == ' ')
		{
			str[i] = '_';
		}
	}
	return str;
}

string replaceUnderscore(string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '_')
		{
			str[i] = ' ';
		}
	}
	return str;
}		

int main ()
{
    int pilih; char ulang='T'; char valid='Y';
    do
    {
        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(15,' ') << "PROGRAM PENDATAAN BAHAN BAKAR" << string(14,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "|  MENU" << string(52,' ') << "|\n";
        cout << "|    1. Input Data" << string(41,' ') << "|\n";
        cout << "|    2. Output Data" << string(40,' ') << "|\n";
        cout << "|    3. Searching Data" << string(37,' ') << "|\n";
        cout << "|    4. Sorting Data" << string(39,' ') << "|\n";
        cout << "|    5. Transaksi" << string(42,' ') << "|\n";
        cout << "|    6. Keluar" << string(45,' ') << "|\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";

        do{
        cout << "\n Pilihan Anda : "; cin >> pilih; cin.ignore();
        switch (pilih)
        {
            case 1  : valid='Y'; system ("cls"); input(data); break;
            case 2  : valid='Y'; system ("cls"); output(data); break;
            case 3  : valid='Y'; system ("cls"); searching(data); break;
            case 4  : valid='Y'; system ("cls"); sorting(data); break;
            case 5  : valid='Y'; system ("cls"); transaksi(); break;
            case 6  : valid='Y'; return 0;

            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }} while (valid=='T');

    cout << "\n  Apakah Anda ingin kembali ke menu Awal? (Y/T) "; cin >> ulang; cin.ignore();
    }while(toupper(ulang)=='Y');
}

void input(dt data[])
{
    string file; char ulang='X';
    int jumlah=0;

        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(18,' ') << "INPUT DATA BAHAN BAKAR" << string(18,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file\t: "; cin >> file;
        do {
        cout << "  Jumlah data\t: "; cin >> jumlah; cin.ignore();
        if (jumlah>0)
        {
        ulang='X';
        for (int i=0; i<jumlah; i++)
        {
            cout << "\tID BBM\t: "; cin >> data[i].id; cin.ignore();
            cout << "\tNama\t: "; getline(cin, data[i].nama);
            transform(data[i].nama.begin(), data[i].nama.end(), data[i].nama.begin(), ::toupper);
            cout << "\tStok\t: "; cin >> data[i].stok; cin.ignore();
            cout << "\tHarga\t: "; cin >> data[i].harga; cin.ignore(); cout << endl;
        }

        for (int i=0; i<jumlah; i++)
        data[i].nama=replaceSpasi(data[i].nama);

        ofstream ofs(file, ios::app);
        if (ofs.is_open())
        {
            for (int i=0; i<jumlah; i++)
            {
                ofs << data[i].id << " " << data[i].nama << " " << data[i].stok << " " << data[i].harga << " " << endl;
            }
            ofs.close();
            cout << "  Data berhasil tersimpan!\n";
        }
        } else {cout << "  Maaf, jumlah data yang Anda inputkan harus lebih banyak dari 0.\n\n"; ulang='Y';}
        } while (ulang=='Y');
}

void output(dt data[])
{
        int jumlah=0;
        string file;

        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(19,' ') << "PENDATAAN BAHAN BAKAR" << string(18,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();

        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

        cout << "  +---------+----------------------+---------+-------------+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;

        for (int i=0; i<jumlah; i++)
        {
            cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
            cout << "  +---------+----------------------+---------+-------------+" << endl;
        }
        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA
}

void searching(dt data[])
{
    int pilih; char ulang='T'; char valid='Y'; string file;

    do
    {
        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(14,' ') << "SEARCHING PENDATAAN BAHAN BAKAR" << string(13,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "|  METODE" << string(50,' ') << "|\n";
        cout << "|    1. Sequential Search" << string(34,' ') << "|\n";
        cout << "|    2. Binary Search" << string(38,' ') << "|\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";

        do{
        cout << "\n Pilihan Anda : "; cin >> pilih; cin.ignore();
        switch (pilih)
        {
            case 1  : valid='Y'; system ("cls"); sequential(data); break;
            case 2  : valid='Y'; system ("cls"); binary(data); break;

            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }} while (valid=='T');

    cout << "\n  Apakah Anda ingin kembali ke menu Searching? (Y/T) "; cin >> ulang; cin.ignore();
    }while(toupper(ulang)=='Y');
}

void sequential(dt data[]) //SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQ SEQUENTIAL
{
        string file; char valid='Y', ulang='X'; int pilih; int jumlah=0; char simpan;
        bool found = false; int mul[1000], n=0;

        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(21,' ') << "SEQUENTIAL SEARCH" << string(20,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Searching data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Nama" << endl;
        cout << "    3. Harga" << endl;
        cout << "    4. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : { valid='Y';
            int id;
            cout << "\n  Cari ID : "; cin >> id; cin.ignore();
            for (i = 0; i < jumlah; i++)
            {
                if (id == data[i].id)
                {
                    found = true; break;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }}
           break;
//---------NAMA--------------------------------------------------------------------------------------------------------------------------------------------
           case 2 : { valid='Y';
            string nama; int s;
            cout << "\n  Cari nama : "; getline(cin, nama);
            transform(nama.begin(), nama.end(), nama.begin(), ::toupper);
            for (i = 0; i < jumlah; i++)
            {
                if (replaceSpasi(nama) == replaceSpasi(data[i].nama))
                {
                    found = true;
                    s=i;
                    break;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[s].id << " | " << setw(20) << replaceUnderscore(data[s].nama) << " | " << setw(7) << data[s].stok << " | Rp " << setw(8) << data[s].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }}
            break;
//----------HARGA------------------------------------------------------------------------------------------------------------
           case 3 : { valid='Y';
            do {
            int harga;
            cout << "\n  Cari harga : ";
            cout << "\n    1. Lebih besar";
            cout << "\n    2. Lebih kecil";
            cout << "\n    3. Sama dengan";
            cout << "\n  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //LEBIH BESAR
            if (pilih == 1)
            {
                cout << "\n  Cari bahan bakar dengan harga di atas : "; cin >> harga; cin.ignore();

            for (int i = 0; i < jumlah; i++)
            {
                if (data[i].harga > harga)
                {
                    found = true;
                    mul[n]=i;
                    n++;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;

                for (int j=0; j<n; j++)
                {
                    cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                }
                cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
                if (toupper(simpan)=='Y')
                {
                cout << "  Nama file baru : "; cin >> file; cin.ignore();
                ofstream ofs(file, ios::app);
                if (ofs.is_open())
                {
                for (int j=0; j<n; j++)
                    {
                    ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                    }
                    ofs.close();
                cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                }
                }

            } else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }
            } else if (pilih == 2) //LEBIH KECIL
            {
                cout << "\n  Cari bahan bakar dengan harga di bawah : "; cin >> harga; cin.ignore();

                for (int i = 0; i < jumlah; i++)
                {
                    if (data[i].harga < harga)
                    {
                        found = true;
                        mul[n]=i;
                        n++;
                    }
                }
                if (found==true)
                {
                    cout << "  Data ditemukan !!" << endl;
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                    cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                    cout << "  +---------+----------------------+---------+-------------+" << endl;

                    for (int j=0; j<n; j++)
                    {
                        cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                        cout << "  +---------+----------------------+---------+-------------+" << endl;
                    }
                    cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
                    if (toupper(simpan)=='Y')
                    {
                    cout << "  Nama file baru : "; cin >> file; cin.ignore();
                    ofstream ofs(file, ios::app);
                    if (ofs.is_open())
                    {
                    for (int j=0; j<n; j++)
                        {
                        ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                        }
                        ofs.close();
                    cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                    }
                    }
                } else
                {
                    cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
                }
            } else if (pilih == 3) //SAMA DENGAN
            {
                cout << "\n  Cari bahan bakar dengan harga : "; cin >> harga; cin.ignore();

            for (int i = 0; i < jumlah; i++)
            {
                if (data[i].harga == harga)
                {
                    found = true;
                    mul[n]=i;
                    n++;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;

                for (int j=0; j<n; j++)
                {
                    cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                }
                cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN

                if (toupper(simpan)=='Y')
                {
                cout << "  Nama file baru : "; cin >> file; cin.ignore();
                ofstream ofs(file, ios::app);
                if (ofs.is_open())
                {
                for (int j=0; j<n; j++)
                    {
                    ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                    }
                    ofs.close();
                cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                }
                }
            } else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }
            } else {ulang='Y'; cout << "  Maaf, input yang Anda masukkan invalid. Silakan coba lagi.";}
            } while (ulang=='Y');
           }
           break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 4 : { valid='Y';
            do {
            int stok;
            cout << "\n  Cari stok : ";
            cout << "\n    1. Lebih besar";
            cout << "\n    2. Lebih kecil";
            cout << "\n    3. Sama dengan";
            cout << "\n  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //LEBIH BESAR
            if (pilih == 1)
            {
                cout << "\n  Cari bahan bakar dengan stok di atas : "; cin >> stok; cin.ignore();

            for (int i = 0; i < jumlah; i++)
            {
                if (data[i].stok > stok)
                {
                    found = true;
                    mul[n]=i;
                    n++;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;

                for (int j=0; j<n; j++)
                {
                    cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                }
                cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
                if (toupper(simpan)=='Y')
                {
                cout << "  Nama file baru : "; cin >> file; cin.ignore();
                ofstream ofs(file, ios::app);
                if (ofs.is_open())
                {
                for (int j=0; j<n; j++)
                    {
                    ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                    }
                    ofs.close();
                cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                }
                }

            } else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }
            } else if (pilih == 2) //LEBIH KECIL
            {
                cout << "\n  Cari bahan bakar dengan stok di bawah : "; cin >> stok; cin.ignore();

                for (int i = 0; i < jumlah; i++)
                {
                    if (data[i].stok < stok)
                    {
                        found = true;
                        mul[n]=i;
                        n++;
                    }
                }
                if (found==true)
                {
                    cout << "  Data ditemukan !!" << endl;
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                    cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                    cout << "  +---------+----------------------+---------+-------------+" << endl;

                    for (int j=0; j<n; j++)
                    {
                        cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                        cout << "  +---------+----------------------+---------+-------------+" << endl;
                    }
                    cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
                    if (toupper(simpan)=='Y')
                    {
                    cout << "  Nama file baru : "; cin >> file; cin.ignore();
                    ofstream ofs(file, ios::app);
                    if (ofs.is_open())
                    {
                    for (int j=0; j<n; j++)
                        {
                        ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                        }
                        ofs.close();
                    cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                    }
                    }
                } else
                {
                    cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
                }
            } else if (pilih == 3) //SAMA DENGAN
            {
                cout << "\n  Cari bahan bakar dengan stok : "; cin >> stok; cin.ignore();

            for (int i = 0; i < jumlah; i++)
            {
                if (data[i].stok == stok)
                {
                    found = true;
                    mul[n]=i;
                    n++;
                }
            }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;

                for (int j=0; j<n; j++)
                {
                    cout << left << "  | " << setw(7) << data[mul[j]].id << " | " << setw(20) << replaceUnderscore(data[mul[j]].nama) << " | " << setw(7) << data[mul[j]].stok << " | Rp " << setw(8) << data[mul[j]].harga << " |\n";
                    cout << "  +---------+----------------------+---------+-------------+" << endl;
                }
                cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
                if (toupper(simpan)=='Y')
                {
                cout << "  Nama file baru : "; cin >> file; cin.ignore();
                ofstream ofs(file, ios::app);
                if (ofs.is_open())
                {
                for (int j=0; j<n; j++)
                    {
                    ofs << left << data[mul[j]].id << " " << replaceSpasi(data[mul[j]].nama) << " " << data[mul[j]].stok << " " << data[mul[j]].harga << " \n";
                    }
                    ofs.close();
                cout << "\n  !! Data berhasil disimpan dalam file " << file << " !!\n";
                }
                }
            } else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }
            } else {ulang='Y'; cout << "  Maaf, input yang Anda masukkan invalid. Silakan coba lagi.";}
            } while (ulang=='Y'); }
            break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------FILE TIDAK ADA--------------------------------------------------------------------------------------------
        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA
}

void binary(dt data[]) //BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BIN BINARY
{
        string file; char valid='Y'; int pilih; int jumlah=0; 
        bool found = false; 

        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(23,' ') << "BINARY SEARCH" << string(22,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Searching data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Nama" << endl;
        cout << "    3. Harga" << endl;
        cout << "    4. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : { valid='Y';
            int id;
                for (int i=0; i<jumlah-1; i++)
                {
                    int min=i;
                    for (int j=i+1; j<jumlah; j++)
                    {
                        if (data[j].id < data[min].id)
                        {
                            min=j;
                        }
                    }
                    dt temp = data[i];
                    data[i] = data[min];
                    data[min] = temp;
                }

                cout << "\n  Cari ID : "; cin >> id; cin.ignore();
                int low = 0, high = jumlah-1, mid;
                while (low <= high)
                {
                    mid = (low + high) / 2;
                    if (data[mid].id == id)
                    {
                        found = true;
                        break;
                    }
                    else if (data[mid].id < id)
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[mid].id << " | " << setw(20) << replaceUnderscore(data[mid].nama) << " | " << setw(7) << data[mid].stok << " | Rp " << setw(8) << data[mid].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }}
           break;
//---------NAMA--------------------------------------------------------------------------------------------------------------------------------------------
           case 2 : { valid='Y';
            string nama;
                for (int i=0; i<jumlah-1; i++)
                {
                    int min=i;
                    for (int j=i+1; j<jumlah; j++)
                    {
                        if (replaceSpasi(data[j].nama) < replaceSpasi(data[min].nama))
                        {
                            min=j;
                        }
                    }
                    dt temp = data[i];
                    data[i] = data[min];
                    data[min] = temp;
                }

                cout << "\n  Cari nama : "; getline(cin, nama);
                transform(nama.begin(), nama.end(), nama.begin(), ::toupper);

                int low = 0, high = jumlah-1, mid;
                while (low <= high)
                {
                    mid = (low + high) / 2;
                    if (replaceSpasi(data[mid].nama) == replaceSpasi(nama))
                    {
                        found = true;
                        break;
                    }
                    else if (data[mid].nama < nama)
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[mid].id << " | " << setw(20) << replaceUnderscore(data[mid].nama) << " | " << setw(7) << data[mid].stok << " | Rp " << setw(8) << data[mid].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }}
            break;
//----------HARGA------------------------------------------------------------------------------------------------------------
           case 3 : { valid='Y';
            int harga;
                for (int i=0; i<jumlah-1; i++)
                {
                    int min=i;
                    for (int j=i+1; j<jumlah; j++)
                    {
                        if (data[j].harga < data[min].harga)
                        {
                            min=j;
                        }
                    }
                    dt temp = data[i];
                    data[i] = data[min];
                    data[min] = temp;
                }

                cout << "\n  Cari harga : "; cin >> harga; cin.ignore();
                int low = 0, high = jumlah-1, mid;
                while (low <= high)
                {
                    mid = (low + high) / 2;
                    if (data[mid].harga == harga)
                    {
                        found = true;
                        break;
                    }
                    else if (data[mid].harga < harga)
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[mid].id << " | " << setw(20) << replaceUnderscore(data[mid].nama) << " | " << setw(7) << data[mid].stok << " | Rp " << setw(8) << data[mid].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }}
            break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 4 : { valid='Y';
            int stok;
                for (int i=0; i<jumlah-1; i++)
                {
                    int min=i;
                    for (int j=i+1; j<jumlah; j++)
                    {
                        if (data[j].stok < data[min].stok)
                        {
                            min=j;
                        }
                    }
                    dt temp = data[i];
                    data[i] = data[min];
                    data[min] = temp;
                }

                cout << "\n  Cari stok : "; cin >> stok; cin.ignore();
                int low = 0, high = jumlah-1, mid;
                while (low <= high)
                {
                    mid = (low + high) / 2;
                    if (data[mid].stok == stok)
                    {
                        found = true;
                        break;
                    }
                    else if (data[mid].stok < stok)
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
            if (found==true)
            {
                cout << "  Data ditemukan !!" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
                cout << "  +---------+----------------------+---------+-------------+" << endl;
                cout << left << "  | " << setw(7) << data[mid].id << " | " << setw(20) << replaceUnderscore(data[mid].nama) << " | " << setw(7) << data[mid].stok << " | Rp " << setw(8) << data[mid].harga << " |\n";
                cout << "  +---------+----------------------+---------+-------------+" << endl;
            }
            else
            {
                cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
            }} break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------FILE TIDAK ADA--------------------------------------------------------------------------------------------
        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA
}

void sorting(dt data[])
{
    int pilih; char ulang='T'; char valid='Y'; string file;
    do
    {
        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(14,' ') << "SORTING PENDATAAN BAHAN BAKAR" << string(15,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "|  METODE" << string(50,' ') << "|\n";
        cout << "|    1. Bubble" << string(45,' ') << "|\n";
        cout << "|    2. Selection" << string(42,' ') << "|\n";
        cout << "|    3. Insertion Sort" << string(37 ,' ') << "|\n";
        cout << "|    4. Shell Sort" << string(41,' ') << "|\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";

        do{
        cout << "\n Pilihan Anda : "; cin >> pilih; cin.ignore();
        switch (pilih)
        {
            case 1  : valid='Y'; system ("cls"); bubble(data); break;
            case 2  : valid='Y'; system ("cls"); selection(data); break;
            case 3  : valid='Y'; system ("cls"); insertion(data); break;
            case 4  : valid='Y'; system ("cls"); shell(data); break;

            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }} while (valid=='T');

    cout << "\n  Apakah Anda ingin kembali ke menu Sorting? (Y/T) "; cin >> ulang; cin.ignore();
    }while(toupper(ulang)=='Y');
}

void bubble(dt data[]) //BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE BUBBLE
{
        string file; char valid='Y', ulang='X'; int pilih; char simpan; int jumlah=0;

        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(22,' ') << "SORTING BUBBLE" << string(22,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Sorting data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Harga" << endl;
        cout << "    3. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].id < data[j+1].id)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].id > data[j+1].id)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------HARGA------------------------------------------------------------------------------------------------------------
            case 2 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].harga < data[j+1].harga)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].harga > data[j+1].harga)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 3 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].stok < data[j+1].stok)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (int i=0; i<jumlah-1; i++)
                {
                    for (int j=0; j<jumlah-1-i; j++)
                    {
                        if (data[j].stok > data[j+1].stok)
                        {
                            dt temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                    }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------TAMPILAN DATA URUT--------------------------------------------------------------------------------------------
        cout << "\n  Data setelah diurutkan : \n";
        cout << "\n  Nama file = " << file << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;

        for (int i=0; i<jumlah; i++)
        {
            cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
            cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

        cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
        if (toupper(simpan)=='Y')
        {
        cout << "  Nama file baru : "; cin >> file; cin.ignore();
        ofstream ofs(file, ios::app);
        if (ofs.is_open())
        {
            for (int i = 0; i<jumlah; i++)
            {
            ofs << left << data[i].id << " " << replaceSpasi(data[i].nama) << " " << data[i].stok << " " << data[i].harga << " \n";
            }
            ofs.close();
        cout << "  !! Data berhasil disimpan dalam file " << file << " !!\n";
        }
        }

        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA
}

void selection(dt data[]) //SELECTION SELECTION SELECTION SELECTION SELECTION SELECTION SELECTION SELECTION SELECTION SELECTION
{
        int pilih; char valid='Y', ulang='X'; string file; int jumlah=0;
        int current, j; dt temp; char simpan = 'Y';

        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(21,' ') << "SORTING SELECTION" << string(20,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Sorting data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Harga" << endl;
        cout << "    3. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].id < data[j].id)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].id > data[j].id)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------HARGA------------------------------------------------------------------------------------------------------------
            case 2 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].harga < data[j].harga)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].harga > data[j].harga)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }

            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 3 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].stok < data[j].stok)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                for (current=0; current<jumlah; current++)
                {
                    for (j=current+1; j<jumlah; j++)
                    {
                    if(data[current].stok > data[j].stok)
                      {
                        temp = data[current];
                        data[current] = data[j];
                        data[j] = temp;
                      }
                    }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------TAMPILAN DATA URUT--------------------------------------------------------------------------------------------
        cout << "\n  Data setelah diurutkan : \n";
        cout << "\n  Nama file = " << file << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;

        for (int i=0; i<jumlah; i++)
        {
            cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
            cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

        cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
        if (toupper(simpan)=='Y')
        {
        cout << "  Nama file baru : "; cin >> file; cin.ignore();
        ofstream ofs(file, ios::app);
        if (ofs.is_open())
        {
            for (int i = 0; i<jumlah; i++)
            {
            ofs << left << data[i].id << " " << replaceSpasi(data[i].nama) << " " << data[i].stok << " " << data[i].harga << " \n";
            }
            ofs.close();
        cout << "  !! Data berhasil disimpan dalam file " << file << " !!\n";
        }
        }

        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA

}

void insertion(dt data[]) //INSERTION INSERTION INSERTION INSERTION INSERTION INSERTION INSERTION INSERTION INSERTION
{
        string file; char valid='Y', ulang='X'; int pilih; char simpan; int jumlah=0;
        int j;


        system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(20,' ') << "SORTING INSERTION" << string(21,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;
//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Sorting data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Harga" << endl;
        cout << "    3. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.id > data[j].id) && (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                 for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.id < data[j].id) && (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------HARGA------------------------------------------------------------------------------------------------------------
            case 2 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.harga > data[j].harga) && (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                 for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.harga < data[j].harga) && (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 3 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
                for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.stok > data[j].stok) && (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
                 for(i=1; i<jumlah; i++)
                {
                     dt temp = data[i];
                     j = i-1;
                     while((temp.stok < data[j].stok) & (j >= 0))
                     {
                     data[j+1]=data[j];
                     j = j-1;
                     data[j+1]=temp;
                     }
                }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------TAMPILAN DATA URUT--------------------------------------------------------------------------------------------
        cout << "\n  Data setelah diurutkan : \n";
        cout << "\n  Nama file = " << file << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;

        for (int i=0; i<jumlah; i++)
        {
            cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
            cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

        cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
        if (toupper(simpan)=='Y')
        {
        cout << "  Nama file baru : "; cin >> file; cin.ignore();
        ofstream ofs(file, ios::app);
        if (ofs.is_open())
        {
            for (int i = 0; i<jumlah; i++)
            {
            ofs << left << data[i].id << " " << replaceSpasi(data[i].nama) << " " << data[i].stok << " " << data[i].harga << " \n";
            }
            ofs.close();
        cout << "  !! Data berhasil disimpan dalam file " << file << " !!\n";
        }
        }

        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA

}

void shell(dt data[]) //SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL SHELL
{

        int pilih; char valid='Y', ulang='X'; string file; int jumlah=0;
        dt temp; char simpan = 'Y';

        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(23,' ') << "SORTING SHELL" << string(22,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n\n";
        cout << "  Nama file : "; cin >> file; cin.ignore();
//------AMBIL FILE---------------------------------------------------------------------------------------------------
        ifstream ifs(file);
        if (ifs.is_open())
        {
            int i=jumlah;
            while (!ifs.eof())
            {
                ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
                i++;
            }
            ifs.close();
            jumlah += i - 1;

//------ID------------------------------------------------------------------------------------------------------------
        do
        {
        cout << "\n  Sorting data berdasarkan :" << endl;
        cout << "    1. ID " << endl;
        cout << "    2. Harga" << endl;
        cout << "    3. Stok" << endl;
        cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();

        switch(pilih)
        {
           case 1 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].id < temp.id)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].id > temp.id)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------HARGA------------------------------------------------------------------------------------------------------------
            case 2 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].harga < temp.harga)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].harga > temp.harga)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
//----------STOK---------------------------------------------------------------------------------------------------
            case 3 : valid='Y';
            do
            {
            cout << "\n  Urutkan dari : \n";
            cout << "    1. Terbesar\n";
            cout << "    2. Terkecil\n";
            cout << "  Pilihan Anda : "; cin >> pilih; cin.ignore();
            //terbesar
            if (pilih==1)
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].stok < temp.stok)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }
            ulang='X';
            } else if (pilih==2) //terkecil
            {
            int gap = jumlah / 2;
            while (gap > 0)
            {
                for (int i = gap; i < jumlah; i++)
                {
                    dt temp = data[i];
                    int j = i;
                    while (j >= gap && data[j - gap].stok > temp.stok)
                    {
                        data[j] = data[j - gap];
                        j -= gap;
                    }
                    data[j] = temp;
                }
                gap /= 2;
            }
            ulang='X';
            } else {cout << "  Maaf, input Anda invalid. Silakan coba lagi.\n"; ulang='Y';}
            } while (ulang=='Y'); break;
            default : valid='T'; cout << " Maaf, input Anda invalid. Silakan coba lagi." << endl; break;
        }
        } while (valid=='T');
//------TAMPILAN DATA URUT--------------------------------------------------------------------------------------------
        cout << "\n  Data setelah diurutkan : \n";
        cout << "\n  Nama file = " << file << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +---------+----------------------+---------+-------------+" << endl;

        for (int i=0; i<jumlah; i++)
        {
            cout << left << "  | " << setw(7) << data[i].id << " | " << setw(20) << replaceUnderscore(data[i].nama) << " | " << setw(7) << data[i].stok << " | Rp " << setw(8) << data[i].harga << " |\n";
            cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

        cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN
        if (toupper(simpan)=='Y')
        {
        cout << "  Nama file baru : "; cin >> file; cin.ignore();
        ofstream ofs(file, ios::app);
        if (ofs.is_open())
        {
            for (int i = 0; i<jumlah; i++)
            {
            ofs << left << data[i].id << " " << replaceSpasi(data[i].nama) << " " << data[i].stok << " " << data[i].harga << " \n";
            }
            ofs.close();
        cout << "  !! Data berhasil disimpan dalam file " << file << " !!\n";
        }
        }

        }else {cout << "  Maaf, file tidak tersedia.\n";} //JIKA FILE TIDAK TERBUKA

}

void transaksi()
{
    char valid='Y'; char ulang='X';	int pilih;

	do
    {
    system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(23,' ') << "MENU TRANSAKSI" << string(21,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "|  METODE" << string(50,' ') << "|\n";
        cout << "|    1. Merging Sambung" << string(36,' ') << "|\n";
        cout << "|    2. Merging Urut" << string(39,' ') << "|\n";
        cout << "|    3. Splitting" << string(42 ,' ') << "|\n";
        cout << "|    4. Updating" << string(43,' ') << "|\n";
        cout << "|" << string(58,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
	do
    {
	cout << "\n  Pilihan Anda : ";
	cin >> pilih;
		if (pilih == 1){valid='Y';
			merginsambung();
		}
			else if (pilih == 2){valid='Y';
                merging();
			}
				else if (pilih == 3){valid='Y';
                    split(data);
				}
					else if (pilih == 4){valid='Y';
						update();
					}
						else
						{cout << "  Maaf, input Anda invalid. Silakan coba lagi." << endl; valid='X';}
    } while (valid=='X');
    cout << "\n  Apakah Anda ingin kembali ke menu Transaksi? (Y/T) "; cin >> ulang; cin.ignore();
    }while(toupper(ulang)=='Y');
}

void merginsambung(){
    string file;
    system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(22,' ') << "MERGING SAMBUNG" << string(21,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
//--FILE 1---------------------------------------------------------------------------
	cout << "\n  Nama file 1 : "; cin >> file; cin.ignore();

	ifstream ifs(file);
    int jumlah1 = 0;

    if (ifs.is_open()) {
    int i = jumlah1;

    while (!ifs.eof()) {
        ifs >> temp1[i].id >> temp1[i].nama >> temp1[i].stok >> temp1[i].harga;
        i++;
        }
        jumlah1 += i - 1;
        ifs.close();

        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;

        for (int i=0; i<jumlah1; i++)
        {
        cout << left << "  | " << setw(7) << temp1[i].id << " | " << setw(20) << replaceUnderscore(temp1[i].nama) << " | " << setw(7) << temp1[i].stok << " | Rp " << setw(8) << temp1[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

//--FILE 2------------------------------------------------------------------------------------------------
	cout << "\n  Nama file 2 : "; cin >> file; cin.ignore();

	ifstream ifs2(file);
    int jumlah2 = 0;

    if (ifs2.is_open()) {
    int i = jumlah2;

    while (!ifs2.eof()) {
        ifs2 >> temp2[i].id >> temp2[i].nama >> temp2[i].stok >> temp2[i].harga;
        i++;
        }
        jumlah2 += i - 1;
        ifs2.close();

        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        for (int i=0; i<jumlah2; i++)
        {
        cout << left << "  | " << setw(7) << temp2[i].id << " | " << setw(20) << replaceUnderscore(temp2[i].nama) << " | " << setw(7) << temp2[i].stok << " | Rp " << setw(8) << temp2[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

	//Penggabungan 2 variabel menjadi variabel temp3
	for (i = 0; i < jumlah1; i++){
		temp3[i].id = temp1[i].id;
		temp3[i].nama = temp1[i].nama;
		temp3[i].stok = temp1[i].stok;
		temp3[i].harga = temp1[i].harga;
	}
	int jumlah3;
	jumlah3 = jumlah1 + jumlah2;
	int a = 0, b = i;
	//cout << i << " " << jumlah1 << " " << jumlah2 << " " << jumlah3;

	while (b < jumlah3 && a < jumlah2){
			temp3[b].id = temp2[a].id;
			temp3[b].nama = temp2[a].nama;
			temp3[b].stok = temp2[a].stok;
			temp3[b].harga = temp2[a].harga;
			a++;
			b++;
	}

	cout << "\n  Data setelah disambung : " << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;

        for (int i=0; i<jumlah3; i++)
        {
        cout << left << "  | " << setw(7) << temp3[i].id << " | " << setw(20) << replaceUnderscore(temp3[i].nama) << " | " << setw(7) << temp3[i].stok << " | Rp " << setw(8) << temp3[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

	char simpan = 'Y';
    cout << "\n  Apakah Anda ingin menyimpan ke file baru? (Y/T) "; cin >> simpan; cin.ignore(); //SIMPAN

		if (simpan == 'y' || simpan == 'Y'){
			for (int i = 0; i < jumlah3; i++){
				string str = temp3[i].nama;
				temp3[i].nama = replaceSpasi(str).c_str();
			}
			cout << "  Nama file baru : ";
			cin >> file;
			ofstream ofs(file, ios::app);
				if (!ofs.is_open()) {
					cout << "Tidak bisa membuka file";
					exit(1);
				}
				for (int i = 0; i < jumlah3; i++) {
				ofs << left << setw(10) << temp3[i].id
					<< setw(35) << replaceSpasi(temp3[i].nama)
					<< right << setprecision(7)
					<< setw(5) << temp3[i].stok
					<< setw(10) << temp3[i].harga
					<< endl;
				}
				ofs.close();

        cout << "  !! Data berhasil disimpan dalam file " << file << " !!\n";
		}

		} else cout << "  Maaf, file tidak tersedia.";
        } else cout << "  Maaf, file tidak tersedia.\n";
}

void update(){

    string file; int jumlah = 0;
    system("cls");
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(24,' ') << "UPDATE DATA" << string(23,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";
        cout << "\n  Nama file : "; cin.ignore() >> file;

        ifstream ifs(file);
        if (ifs.is_open()) {
        int i = jumlah;

          while (!ifs.eof()) {
            ifs >> temp[i].id >> temp[i].nama >>
                temp[i].stok >> temp[i].harga;
            i++;
          }
          jumlah += i - 1;
          ifs.close();

        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        for (int i=0; i<jumlah; i++)
        {
        cout << left << "  | " << setw(7) << temp[i].id << " | " << setw(20) << replaceUnderscore(temp[i].nama) << " | " << setw(7) << temp[i].stok << " | Rp " << setw(8) << temp[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

	cout << "  ID data yang ingin Anda update : "; int cari; cin >> cari; cin.ignore();
	bool found = false;
      int lop = 0;  // index yang dituju
      for (int i = 0; i < jumlah; i++) {
        if (temp[i].id == cari) {
          found = true;
          // cout << "ini i nya = " << i << endl; //melihat index tadinya
          lop = i;
          break;
        }
      }
      // cout << "lop = " << lop << endl; //make sure index tadinya

    if(found) {
			cout << "\n  UPDATE DATA" << endl;
			cout << "     ID BBM\t\t: ";
			cin >> temp[lop].id; cin.ignore();
			cout << "     Nama BBM \t\t: ";
			getline(cin,temp[lop].nama);
            transform(temp[lop].nama.begin(), temp[lop].nama.end(), temp[lop].nama.begin(), ::toupper);
			cout << "     Stok \t\t: ";
			cin >> temp[lop].stok; cin.ignore();
			cout << "     Harga \t\t: ";
			cin >> temp[lop].harga; cin.ignore();

			cout << "  Apakah Anda ingin menyimpan perubahan? (Y/N) ";
			char update = 'Y';
			cin >>	update;
			if (update == 'y' || update == 'Y'){
				// Buka file_temp dan masuk ke file_temp
				ofstream ofs(file_temp, ios::app);
				if (!ofs.is_open()) {
				cout << "Tidak bisa membuka file";
				exit(1);
			}
				for (int i = 0; i < jumlah; i++) {
				ofs << left << setw(10) << temp[i].id
					<< setw(35) << replaceSpasi(temp[i].nama)
					<< right << setprecision(7)
					<< setw(5) << temp[i].stok
					<< setw(10) << temp[i].harga
					<< endl;
			}
				remove(file.c_str());
				ofs.close();
				rename(file_temp.c_str(), file.c_str());
				cout << "  !! Selamat, data berhasil terupdate !!" << endl;
			}
	} else cout << "  Sayang sekali, data yang Anda cari tidak ditemukan." << endl;
    } else cout << "  Maaf, file tidak tersedia.\n";
}

void split(dt data[])
{
    system("cls");
    string file, file1, file2;
    int i = 0; int jumlah=0;

    cout << "+" << string(58,'=') << "+\n";
    cout << "|" << string(23,' ') << "MENU SPLITTING" << string(21,' ') << "|\n";
    cout << "+" << string(58,'=') << "+\n";

    cout << "\n";
    cout << "  Nama file : "; cin >> file; cin.ignore();

    ifstream ifs(file);
    if (ifs.is_open()) {
        while (!ifs.eof())
        {
            ifs >> data[i].id >> data[i].nama >> data[i].stok >> data[i].harga;
            i++;
        }
    ifs.close();
    jumlah = i - 1;

    cout << "\n  Nama file 1 : "; cin >> file1; cin.ignore();
    cout << "  Nama file 2 : "; cin >> file2; cin.ignore();

    ofstream ofs1(file1, ios::app);
    if (ofs1.is_open())
    {
    ofstream ofs2(file2, ios::app);
    if (ofs2.is_open())
        {
        for (int j=0; j<jumlah; j++)
        {
            if (j < jumlah/2)
            {
                ofs1 << data[j].id << " " << replaceSpasi(data[j].nama) << " " << data[j].stok << " " << data[j].harga << " ";
            }
            else if (j >= jumlah/2)
            {
                ofs2 << data[j].id << " " << replaceSpasi(data[j].nama) << " " << data[j].stok << " " << data[j].harga << " ";
            }
        }
        cout << "  !! Selamat, file berhasil dipecah menjadi " << file1 << " dan " << file2 << " !!\n";
    } ofs2.close();
    }
        ofs1.close();

    }
    else
    {
        cout << "  Maaf, file tidak tersedia." << endl;
    }
}

void merging()
{
    system("cls");
    string file;
        cout << "+" << string(58,'=') << "+\n";
        cout << "|" << string(24,' ') << "MERGING URUT" << string(22,' ') << "|\n";
        cout << "+" << string(58,'=') << "+\n";

	cout << "\n  Nama file 1 : ";
	cin >> file;

	ifstream ifs(file);
    int jumlah1 = 0;

    if (ifs.is_open()) {
    int i = jumlah1;

    while (!ifs.eof()) {
        ifs >> temp1[i].id >> temp1[i].nama >>
				temp1[i].stok >> temp1[i].harga;
            i++;
          }
          jumlah1 += i - 1;
          ifs.close();



        cout << "  Data file " << file << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;

        for (int i=0; i<jumlah1; i++)
        {
        cout << left << "  | " << setw(7) << temp1[i].id << " | " << setw(20) << replaceUnderscore(temp1[i].nama) << " | " << setw(7) << temp1[i].stok << " | Rp " << setw(8) << temp1[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

        cout << "\n  Nama file 2 : "; cin >> file; cin.ignore();

        ifstream ifs2(file);
        int jumlah2 = 0;

        if (ifs2.is_open()) {
        int i = jumlah2;

        while (!ifs2.eof()) {
        ifs2 >> temp2[i].id >> temp2[i].nama >> temp2[i].stok >> temp2[i].harga; i++;
        }
          jumlah2 += i - 1;
          ifs2.close();

	cout << "  Data file " << file << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;

        for (int i=0; i<jumlah2; i++)
        {
        cout << left << "  | " << setw(7) << temp2[i].id << " | " << setw(20) << replaceUnderscore(temp2[i].nama) << " | " << setw(7) << temp2[i].stok << " | Rp " << setw(8) << temp2[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

	//Penggabungan 2 variabel menjadi variabel temp3
	for (i = 0; i < jumlah1; i++){
		temp3[i].id = temp1[i].id;
		temp3[i].nama = temp1[i].nama;
		temp3[i].stok = temp1[i].stok;
		temp3[i].harga = temp1[i].harga;
	}
	int jumlah3;
	jumlah3 = jumlah1 + jumlah2;
	int a = 0, b = i;
	//masuk ke temp3
	cout << endl;
	while (b < jumlah3 && a < jumlah2){
			temp3[b].id = temp2[a].id;
			temp3[b].nama = temp2[a].nama;
			temp3[b].stok = temp2[a].stok;
			temp3[b].harga = temp2[a].harga;
			a++;
			b++;

	}
	//Urutkan file temp3 berdasar id
	shell_sort(temp3, jumlah3);

	cout << "  Data setelah disambung urut berdasarkan ID : " << endl;
        cout << "  +=========+======================+=========+=============+" << endl;
        cout << "  | ID BBM  | Nama BBM             | Stok    | Harga       |" << endl;
        cout << "  +=========+======================+=========+=============+" << endl;

        for (int i=0; i<jumlah3; i++)
        {
        cout << left << "  | " << setw(7) << temp3[i].id << " | " << setw(20) << replaceUnderscore(temp3[i].nama) << " | " << setw(7) << temp3[i].stok << " | Rp " << setw(8) << temp3[i].harga << " |\n";
        cout << "  +---------+----------------------+---------+-------------+" << endl;
        }

	char simpan = 'Y';
	cout << "  Apakah Anda ingin menyimpan data? (Y/N) "; cin >> simpan; cin.ignore();
		if (simpan == 'y' || simpan == 'Y'){
			for (int i = 0; i < jumlah3; i++){
				string str = temp3[i].nama;
				temp3[i].nama = replaceSpasi(str).c_str();
			}
			cout << "\n  Nama file baru : ";
			cin >> file;
			ofstream ofs(file, ios::app);
				if (!ofs.is_open()) {
					cout << "  Maaf, file tidak tersedia.";
					exit(1);
				}
				for (int i = 0; i < jumlah3; i++) {
				ofs << left << setw(10) << temp3[i].id
					<< setw(35) << replaceSpasi(temp3[i].nama)
					<< right << setprecision(7)
					<< setw(5) << temp3[i].stok
					<< setw(10) << temp3[i].harga
					<< endl;
				}
				ofs.close();

				cout << "  !! Data berhasil disimpan dalam file " << file << "!!\n";

		}
        } else cout << "  Maaf, file tidak tersedia.\n";
    } else cout << "  Maaf, file tidak tersedia.\n";

}

int shell_sort(dt data[], int jumlah3){
	int i = 0, j = 0, k = 0;
	dt mid;

	for(k = jumlah3/2; k > 0; k /= 2){
		for(j = k; j < jumlah3; j++){
			for(i = j-k; i >= 0; i -= k){
			if(data[i + k].id >= data[i].id)
				break;
			else {
				mid = data[i];
				data[i] = data[i + k];
				data[i + k] = mid;
			}
		}
	}
}

	return 0;
}




