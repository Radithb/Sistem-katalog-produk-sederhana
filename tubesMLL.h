#ifndef tubesMLL_H
#define tubesMLL_H
#include <iostream>
#include <string>

using namespace std;

typedef struct elemenKategori* adrKategori;
typedef struct elemenProduk* adrProduk;

struct Kategori {
    string namaKategori;
};

struct Produk {
    int id;
    string namaProduk;
    float harga;
    int stok;
};

struct elemenProduk {
    Produk info;
    adrProduk next;
    adrProduk prev;
};

struct elemenKategori {
    Kategori info;
    adrKategori next;
    adrKategori prev;
    adrProduk firstProduk;
};

struct ListKategori {
    adrKategori first;
    adrKategori last;
};

void createList_103012400173(ListKategori &L);
adrKategori createKategori_103012400173(string namaKategori);
adrProduk createProduk_103012400173(int id, string nama, float harga, int stok);

void insertLastKategori_103012400173(ListKategori &L, adrKategori P);
void insertProdukToKategori_103012400173(ListKategori &L, string namaKategori, adrProduk P);

void displayKategori_103012400173(ListKategori L);
void displayProduk_103012400173(ListKategori L);

adrKategori searchKategori_103012400173(ListKategori L, string namaKategori);
adrProduk searchProdukByID_103012400173(ListKategori L, int id);

bool updateProduk_103012400173(ListKategori &L, int id, string namaBaru, float hargaBaru, int stokBaru);
void deleteProduk_103012400173(ListKategori &L, int id);

int totalStok_103012400173(ListKategori L);
adrProduk produkStokMinimum_103012400173(ListKategori L);
void sortProdukByHarga(ListKategori &L);
adrProduk produkStokMinimum(ListKategori L);

#endif