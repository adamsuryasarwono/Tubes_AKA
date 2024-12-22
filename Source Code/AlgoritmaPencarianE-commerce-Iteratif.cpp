#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int cariProdukIteratif(const string produk[], int n, string cariProduk) {
    for (int i = 0; i < n; i++) {
        if (produk[i] == cariProduk) return i;
    }
    return -1;
}

int cariIDIteratif(const int idProduk[], int n, int cariID) {
    for (int i = 0; i < n; i++) {
        if (idProduk[i] == cariID) return i;
    }
    return -1;
}

int main() {
    const int n = 10;
    string produk[n] = {"Laptop", "Smartphone", "Tablet", "Keyboard", "Mouse", "Headphone", "Monitor", "Printer", "Speaker", "Charger"};
    int idProduk[n] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    string cariProduk;
    int cariID;
    int hasil;

    cout << "Program Pencarian Barang di Toko Online (Iteratif)" << endl;
    cout << "Daftar produk di toko: {" << endl;
    for (int i = 0; i < n; i++) {
        cout << idProduk[i] << ": " << produk[i] << endl;
    }
    cout << "}" << endl;

    cout << "\nPilih cara cari:" << endl;
    cout << "1. Cari berdasarkan nama produk" << endl;
    cout << "2. Cari berdasarkan ID produk" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    int pilihan;
    cin >> pilihan;

    auto start = chrono::high_resolution_clock::now();  

    if (pilihan == 1) {
        cout << "Masukkan nama produk yang ingin dicari: ";
        cin.ignore();
        getline(cin, cariProduk);
        hasil = cariProdukIteratif(produk, n, cariProduk);
    } else if (pilihan == 2) {
        cout << "Masukkan ID produk yang ingin dicari: ";
        cin >> cariID;
        hasil = cariIDIteratif(idProduk, n, cariID);
    } else {
        cout << "Pilihan nggak valid." << endl;
        return 1;
    }

    auto end = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed = end - start;   

    if (hasil != -1) {
        if (pilihan == 1) {
            cout << "\nProduk " << cariProduk << " ketemu di indeks ke-" << hasil << endl;
        } else {
            cout << "\nID produk " << cariID << " ketemu di indeks ke-" << hasil << endl;
        }
    } else {
        cout << "Produk atau ID nggak ketemu." << endl;
    }
    cout << "Waktu eksekusi: " << elapsed.count() << " detik" << endl;
    return 0;
}