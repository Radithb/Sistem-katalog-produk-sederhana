#include "tubesMLL.h"

/* ================= PRIMITIVES ================= */

void createList_103012400173(ListKategori &L) {
    L.first = NULL;
    L.last = NULL;
}

adrKategori createKategori_103012400173(string namaKategori) {
    adrKategori P = new elemenKategori;
    P->info.namaKategori = namaKategori;
    P->next = NULL;
    P->prev = NULL;
    P->firstProduk = NULL;
    return P;
}

adrProduk createProduk_103012400173(int id, string nama, float harga, int stok) {
    adrProduk P = new elemenProduk;
    P->info.id = id;
    P->info.namaProduk = nama;
    P->info.harga = harga;
    P->info.stok = stok;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

/* ================= INSERT KATEGORI ================= */

void insertLastKategori_103012400173(ListKategori &L, adrKategori P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

/* ================= INSERT PRODUK KE KATEGORI ================= */

void insertProdukToKategori_103012400173(ListKategori &L, string namaKategori, adrProduk P) {
    adrKategori K = searchKategori_103012400173(L, namaKategori);
    if (K != NULL) {
        if (K->firstProduk == NULL) {
            K->firstProduk = P;
        } else {
            adrProduk Q = K->firstProduk;
            while (Q->next != NULL) {
                Q = Q->next;
            }
            Q->next = P;
            P->prev = Q;
        }
    }
}

/* ================= DISPLAY ================= */

void displayKategori_103012400173(ListKategori L) {
    adrKategori P = L.first;
    while (P != NULL) {
        cout << "Kategori: " << P->info.namaKategori << endl;
        P = P->next;
    }
}

void displayProduk_103012400173(ListKategori L) {
    adrKategori K = L.first;
    while (K != NULL) {
        cout << "\nKategori: " << K->info.namaKategori << endl;
        cout << "==================================" << endl;

        adrProduk P = K->firstProduk;
        float totalKategori = 0;

        while (P != NULL) {
            float totalHarga = P->info.harga * P->info.stok;

            cout << "ID      : " << P->info.id << endl;
            cout << "Nama    : " << P->info.namaProduk << endl;
            cout << "Harga   : " << P->info.harga << endl;
            cout << "Stok    : " << P->info.stok << endl;
            cout << "Total   : " << totalHarga << endl;
            cout << "------------------------------" << endl;

            totalKategori += totalHarga;
            P = P->next;
        }

        cout << "Total nilai kategori: " << totalKategori << endl;
        K = K->next;
    }
}


/* ================= SEARCH ================= */

adrKategori searchKategori_103012400173(ListKategori L, string namaKategori) {
    adrKategori P = L.first;
    while (P != NULL) {
        if (P->info.namaKategori == namaKategori) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrProduk searchProdukByID_103012400173(ListKategori L, int id) {
    adrKategori K = L.first;
    while (K != NULL) {
        adrProduk P = K->firstProduk;
        while (P != NULL) {
            if (P->info.id == id) {
                return P;
            }
            P = P->next;
        }
        K = K->next;
    }
    return NULL;
}

/* ================= UPDATE ================= */

bool updateProduk_103012400173(ListKategori &L, int id, string namaBaru, float hargaBaru, int stokBaru) {
    adrProduk P = searchProdukByID_103012400173(L, id);
    if (P != NULL) {
        P->info.namaProduk = namaBaru;
        P->info.harga = hargaBaru;
        P->info.stok = stokBaru;
        return true;
    }
    return false;
}

/* ================= DELETE PRODUK ================= */

void deleteProduk_103012400173(ListKategori &L, int id) {
    adrKategori K = L.first;
    while (K != NULL) {
        adrProduk P = K->firstProduk;
        while (P != NULL) {
            if (P->info.id == id) {
                if (P->prev != NULL) {
                    P->prev->next = P->next;
                } else {
                    K->firstProduk = P->next;
                }
                if (P->next != NULL) {
                    P->next->prev = P->prev;
                }
                delete P;
                return;
            }
            P = P->next;
        }
        K = K->next;
    }
}

/* ================= UTIL ================= */

int totalStok_103012400173(ListKategori L) {
    int total = 0;
    adrKategori K = L.first;
    while (K != NULL) {
        adrProduk P = K->firstProduk;
        while (P != NULL) {
            total += P->info.stok;
            P = P->next;
        }
        K = K->next;
    }
    return total;
}

adrProduk produkStokMinimum_103012400173(ListKategori L) {
    adrProduk minP = NULL;
    adrKategori K = L.first;
    while (K != NULL) {
        adrProduk P = K->firstProduk;
        while (P != NULL) {
            if (minP == NULL || P->info.stok < minP->info.stok) {
                minP = P;
            }
            P = P->next;
        }
        K = K->next;
    }
    return minP;
}

void sortProdukByHarga(ListKategori &L) {
    adrKategori K = L.first;

    while (K != NULL) {
        adrProduk P = K->firstProduk;

        if (P != NULL && P->next != NULL) {
            bool swapped;

            do {
                swapped = false;
                adrProduk Q = K->firstProduk;

                while (Q->next != NULL) {
                    if (Q->info.harga > Q->next->info.harga) {
                        // tukar info
                        Produk temp = Q->info;
                        Q->info = Q->next->info;
                        Q->next->info = temp;
                        swapped = true;
                    }
                    Q = Q->next;
                }
            } while (swapped);
        }

        K = K->next;
    }

    cout << "Produk berhasil diurutkan berdasarkan harga (ascending)." << endl;
}
