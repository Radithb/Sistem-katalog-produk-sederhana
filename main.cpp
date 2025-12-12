#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    ListKategori L;
    createList_103012400173(L);

    int pilihan;
    do {
        cout << "\n===== SISTEM KATALOG PRODUK =====" << endl;
        cout << "1. Tambah Kategori" << endl;
        cout << "2. Tambah Produk ke Kategori" << endl;
        cout << "3. Tampilkan Semua Kategori" << endl;
        cout << "4. Tampilkan Semua Produk" << endl;
        cout << "5. Cari Produk (ID)" << endl;
        cout << "6. Update Produk" << endl;
        cout << "7. Hapus Produk" << endl;
        cout << "8. Total Stok Semua Produk" << endl;
        cout << "9. Produk dengan Stok Paling Sedikit" << endl;
        cout << "10. Urutkan Berdasarkan Harga" << endl;

        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string namaKategori;
            cout << "Nama kategori: ";
            cin.ignore();
            getline(cin, namaKategori);
            adrKategori K = createKategori_103012400173(namaKategori);
            insertLastKategori_103012400173(L, K);

        } else if (pilihan == 2) {
            string namaKategori, namaProduk;
            int id, stok;
            float harga;

            cout << "Nama kategori tujuan: ";
            cin.ignore();
            getline(cin, namaKategori);

            cout << "ID produk: ";
            cin >> id;
            cin.ignore();
            cout << "Nama produk: ";
            getline(cin, namaProduk);
            cout << "Harga: ";
            cin >> harga;
            cout << "Stok: ";
            cin >> stok;

            adrProduk P = createProduk_103012400173(id, namaProduk, harga, stok);
            insertProdukToKategori_103012400173(L, namaKategori, P);

        } else if (pilihan == 3) {
            displayKategori_103012400173(L);

        } else if (pilihan == 4) {
            displayProduk_103012400173(L);

        } else if (pilihan == 5) {
            int id;
            cout << "Masukkan ID produk: ";
            cin >> id;
            adrProduk P = searchProdukByID_103012400173(L, id);
            if (P != NULL) {
                cout << "\nProduk ditemukan:" << endl;
                cout << "Nama  : " << P->info.namaProduk << endl;
                cout << "Harga : " << P->info.harga << endl;
                cout << "Stok  : " << P->info.stok << endl;
            } else {
                cout << "Produk tidak ditemukan!" << endl;
            }

        } else if (pilihan == 6) {
            int id, stok;
            float harga;
            string nama;

            cout << "Masukkan ID produk: ";
            cin >> id;
            cin.ignore();
            cout << "Nama baru: ";
            getline(cin, nama);
            cout << "Harga baru: ";
            cin >> harga;
            cout << "Stok baru: ";
            cin >> stok;

            if (updateProduk_103012400173(L, id, nama, harga, stok)) {
                cout << "Produk berhasil diupdate!" << endl;
            } else {
                cout << "Produk tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) {
            int id;
            cout << "Masukkan ID produk yang dihapus: ";
            cin >> id;
            deleteProduk_103012400173(L, id);
            cout << "Produk berhasil dihapus (jika ditemukan)." << endl;

        } else if (pilihan == 8) {
            cout << "Total stok semua produk: "
                 << totalStok_103012400173(L) << endl;

        } else if (pilihan == 9) {
            adrProduk P = produkStokMinimum_103012400173(L);
            if (P != NULL) {
                cout << "Produk dengan stok paling sedikit:" << endl;
                cout << "Nama : " << P->info.namaProduk << endl;
                cout << "Stok : " << P->info.stok << endl;
            } else {
                cout << "Data masih kosong." << endl;
            }
        } else if (pilihan == 10) {
            sortProdukByHarga(L);
        }


    } while (pilihan != 0);

    cout << "Program selesai." << endl;
    return 0;
}
