#include <iostream>
using namespace std;

void penjumlahan(){
    int a,b;
    cout << "Bilangan pertama : ";
    cin >> a;
    cout << "Bilangan kedua : ";
    cin >> b;
    cout << a << " + " << b << " = " << a+b;
}

void pengurangan(){
    int a,b;
    cout << "Bilangan pertama : ";
    cin >> a;
    cout << "Bilangan kedua : ";
    cin >> b;
    cout << a << " - " << b << " = " << a-b;
}

void perkalian(){
    int a,b;
    cout << "Bilangan pertama : ";
    cin >> a;
    cout << "Bilangan kedua : ";
    cin >> b;
    cout << a << "*" << b << " = " << a*b;
}

void pembagian(){
    int a,b;
    cout << "Bilangan pertama : ";
    cin >> a;
    cout << "Bilangan kedua : ";
    cin >> b;
    cout << a << "/" << b << " = " << a/b;
}

float pangkat(float m, int n){
    if (n==0) return 1;
    else return m*pangkat(m,n-1);
}

void perpangkatan() {
    int a,b;
    cout << "Bilangan basis : ";
    cin >> a;
    cout << "Bilangan pangkat (bilangan bulat) : ";
    cin >> b;
    
    if (a==0){
        if (b==0) cout << "0^0 Tidak terdefinisi";
        else cout << 0;
    }
    else if (b>0) cout << a << "^" << b << " = " << pangkat(a,b);
    else cout << a << "^" << b << " = " << 1/pangkat(a,-b);
}

float fungsi(float a, float b, float c, float d, float x){
    double hasil = a*pangkat(x,3) + b*pangkat(x,2) + c*x + d;
    return hasil;
}

void integral(){
    float awal, akhir;
    cout << "Masukkan batas awal : ";
    cin >> awal;
    cout << "Masukkan batas akhir : ";
    cin >> akhir;

    cout << "Asumsikan fungsi berderajat 3 (f(x) = ax^3 + bx^2 + cx + d)" << endl;
    float a,b,c,d,delta;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;
    cout << "Masukkan nilai d: ";
    cin >> d;
    cout << "Masukkan nilai delta x (lebar kisi): ";
    cin >> delta;

    double total = 0;

    double batasawal, batasakhir; 
    batasawal = awal;
    batasakhir = batasawal + delta;
    while (batasakhir <= akhir ){
        double bagian = (0.5)*delta*(fungsi(a,b,c,d,batasawal) + fungsi(a,b,c,d,batasakhir));
        total += bagian;

        batasawal = batasakhir;
        batasakhir += delta;
    }

    if (batasawal < akhir){
        double bagian = (0.5)*(akhir-batasawal)*(fungsi(a,b,c,d,batasawal) + fungsi(a,b,c,d,akhir));
        total += bagian;
    }

    cout << total;
}



int main(){
    bool jawab = true;
    while(jawab){
        int pilihan;
        cout << "------------------------------------------------------"<< endl;
        cout << "|       Selamat Datang di Kalkulator Sederhana       |" << endl;
        cout << "------------------------------------------------------"<< endl;
        cout << "Berikut ini adalah pilihan menu yang dapat dilakukan" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "4. Pembagian" << endl;
        cout << "5. Perpangkatan" << endl;
        cout << "6. Integral" << endl;
        cout << "Masukkan nomor menu yang Anda pilih" << endl;
        cin >> pilihan;
        

        switch (pilihan) {
            case 1: 
                penjumlahan();
                break;
            case 2: 
                pengurangan();
                break;
            case 3: 
                perkalian();
                break;
            case 4:
                pembagian();
                break;
            case 5:
                perpangkatan();
                break;
            case 6:
                integral();
                break;
            
            default: 
                cout << "Masukan Anda salah" << endl;
                break;
        }
        
        cout << "\n \n";

        char j;
        cout << "Apakah Anda ingin melakukan operasi lagi? (y/n)" << endl;
        cin >> j;
        if (j == 'n') jawab = false;
        else if (j == 'y') jawab = true;
        else {
            cout << "Error, masukan Anda salah" << endl;
            jawab = false;
        }
    }
    cout << "Terima kasih telah menggunakan kalkulator sederhana ini.";
}