#include <iostream>
using namespace std;

// deklarasi single linked list
struct Film{
  // komponen / member
  string judul;
  int durasi, harga;
  Film *next;
};

Film *kepala, *ekor, *saat_ini, *node_baru, *hapus, *sebelum;

// buat single linked list
void createSingleLinkedList(string judul, int d, int hg){
  kepala = new Film();
  kepala->judul = judul;
  kepala->durasi = d;
  kepala->harga = hg;
  kepala->next = NULL;
  ekor = kepala;
}

// print single linked list
int countSingleLinkedList(){
  saat_ini = kepala;
  int jumlah = 0;
  while (saat_ini != NULL){
    jumlah++;
    saat_ini = saat_ini->next;
  }
  return jumlah;
}

// tambahAwal Single linked list
void addFirst(string judul, int d, int hg){
  node_baru = new Film();
  node_baru->judul = judul;
  node_baru->durasi = d;
  node_baru->harga = hg;
  node_baru->next = kepala;
  kepala = node_baru;
}

// tambahAkhir Single linked list
void addLast(string judul, int d, int hg){
  node_baru = new Film();
  node_baru->judul = judul;
  node_baru->durasi = d;
  node_baru->harga = hg;
  node_baru->next = NULL;
  ekor->next = node_baru;
  ekor = node_baru;
}
// tambah tengah single linked list
void addMiddle(string judul, int d, int hg, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    node_baru = new Film();
    node_baru->judul = judul;
    node_baru->durasi = d;
    node_baru->harga = hg;

    // transfer
    saat_ini = kepala;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      saat_ini = saat_ini->next;
      nomor++;
    }
    node_baru->next = saat_ini->next;
    saat_ini->next = node_baru;
  }
}
// menghilangkan awalan
void removeFirst(){
  hapus = kepala;
  kepala = kepala->next;
  delete hapus;
}

// menghilangkan akhiran
void removeLast(){
  hapus = ekor;
  saat_ini = kepala;
  while (saat_ini->next != ekor){
    saat_ini = saat_ini->next;
  }
  ekor = saat_ini;
  ekor->next = NULL;
  delete hapus;
}
// menghilangkan bagian tengah
void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    saat_ini = kepala;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        sebelum = saat_ini;
      }
      if( nomor == posisi ){
        hapus = saat_ini;
      }
      saat_ini = saat_ini->next;
      nomor++;
    }
    sebelum->next = saat_ini;
    delete hapus;
  }
}


// ubahAwal Single linked list
void changeFirst(string judul, int d, int hg){
  kepala->judul = judul;
  kepala->durasi = d;
  kepala->harga = hg;
}

// ubahAkhir Single linked list
void changeLast(string judul, int d, int hg){
  ekor->judul = judul;
  ekor->durasi = d;
  ekor->harga = hg;
}

// ubah node di posisi tengah single linked list
void changeMiddle(string judul, int d, int hg, int posisi) {
  if (posisi < 1 || posisi > countSingleLinkedList()) {
    cout << "Posisi diluar jangkauan" << endl;
  } else if (posisi == 1) {
    cout << "Posisi bukan posisi tengah" << endl;
  } else {
    saat_ini = kepala;
    int nomor = 1;
    while (nomor < posisi) {
      saat_ini = saat_ini->next;
      nomor++;
    }
    saat_ini->judul = judul;
    saat_ini->durasi = d;
    saat_ini->harga = hg;
  }
}


// print single linked list
void printSingleLinkedList(){
  cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  saat_ini = kepala;
  while (saat_ini != NULL){
    cout << "Judul Film : " << saat_ini->judul << endl;
    cout << "Durasi Film : " << saat_ini->durasi << endl;
    cout << "Harga Tiket : " << saat_ini->harga << endl;
    saat_ini = saat_ini->next;
  }
}

int main(){
  createSingleLinkedList("Laut Memanggilmu", 18, 15000);
//   printSingleLinkedList();
  cout << "\n\n" << endl;
  addFirst("Dia adalah Kakakku", 90, 40000);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  addLast("Avenger", 17, 30000);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  removeFirst();
  printSingleLinkedList();
  cout << "\n\n" << endl;
  addLast("infinite war", 180, 40000);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  removeLast();
  printSingleLinkedList();
  cout << "\n\n" << endl;
  changeFirst("Berhenti di Kamu", 120, 60000);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  addMiddle("Bumi Manusia", 90, 20000, 2);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  addMiddle("Negeri 5 Menara", 80, 30000, 2);
  printSingleLinkedList();
  cout << "\n\n" << endl;
  return 0;
}