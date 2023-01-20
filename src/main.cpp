#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* INISIALISAI VARIABEL */
char Op[] = {'*','+','/','-'};  char NumString[4]; double Num[4]; double ArrNum[24][4]; string txt; ifstream file; string str; string txtOut; ofstream fileOutput;

double OpFunc (char op, double a, double b) { 
/* Fungsi empat operator aritmatika aritmatika */
  if (op == '+') return (double)a+b;
  else if (op == '-') return (double)a-b;
  else if (op == '/') { if (b != 0) return (double)a/b;}
  else if (op == '*') return (double)a*b;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // Mempercepat IO
  int no = 0; int n = 0; int Hasil = 24; double EPS = 0.0000000001; bool IsExist; int pilihanMode; char pilihanSave;
  str = "";

  /* ASCII ART sebagai kode start program */
  cout << "\033[1;31m"
  << R"(
        222222222222222        444444444  
      2:::::::::::::::22     4::::::::4  
      2::::::222222:::::2   4:::::::::4  
      2222222     2:::::2  4::::44::::4  
                  2:::::2 4::::4 4::::4  
                  2:::::24::::4  4::::4  
              2222::::24::::4   4::::4  
          22222::::::224::::444444::::444
        22::::::::222  4::::::::::::::::4
      2:::::22222     4444444444:::::444
      2:::::2                    4::::4  
      2:::::2                    4::::4  
      2:::::2       222222       4::::4  
      2::::::2222222:::::2     44::::::44
      2::::::::::::::::::2     4::::::::4
      22222222222222222222     4444444444
  )";
  cout << "\033[0m";
  cout << "\033[1;32m"
              << "G    A   M    E    S    O    L    V    E    R\n"
              << "\033[0m"
              << endl;

  /* Kode untuk memilih jenis masukan */
  cout << "================================================" << endl;
  cout<<"Masukkan pilihan masukan:"<<endl;
  cout<<"1. Masukan via CLI"<<endl;
  cout<<"2. Masukan via file (*.txt)"<<endl;
  cout<<"3. Masukan random dari sistem"<<endl;
  cin >> pilihanMode;
  cout << "================================================" << endl;
  switch(pilihanMode){
    case 1:
      cout<<"Silahkan masukkan nilai yang akan diproses: "<<endl;
      for (int i = 0 ; i < 4 ; ++i){
        cin >> NumString[i];
        switch(NumString[i]){
          case 'A':
            Num[i] = 1;
            break;
          case 'J':
            Num[i] = 11;
            break;
          case 'Q':
            Num[i] = 12;
            break;
          case 'K':
            Num[i] = 13;
            break;
          default:
            Num[i] = double(NumString[i]) - 48;
            break;
        }
      }
      cout << "================================================" << endl;
      break;
    case 2:
      cout<<"Silahkan masukkan nama file yang akan diproses: "<<endl;
      cin >> txt;
      file.open("../test/input/" + txt + ".txt");
      for(int i = 0 ; i < 4 ; i++){
        file >> NumString[i];
        switch(NumString[i]){
          case 'A':
            Num[i] = 1;
            break;
          case 'J':
            Num[i] = 11;
            break;
          case 'Q':
            Num[i] = 12;
            break;
          case 'K':
            Num[i] = 13;
            break;
          default:
            Num[i] = double(NumString[i]) - 48;
            break;
        }
      }
      file.close();
      cout << "================================================" << endl;
      break;
    case 3:
      srand(time(0));
      for(int i = 0; i < 4 ; i++){
        int x = rand() % 13 + 1;
        Num[i] = x;
        switch(x){
          case 1:
            NumString[i] = 'A';
            break;
          case 11:
            NumString[i] = 'J';
            break;
          case 12:
            NumString[i] = 'Q';
            break;
          case 13:
            NumString[i] = 'K';
            break;
          default:
            string conv = to_string(Num[i]);
            NumString[i] = conv[0];
            break;
        }
      }
      cout << "Bilangan hasil random dari sistem: " << endl;
      cout << NumString[0] << " " << NumString[1] << " " << NumString[2] << " " << NumString[3] << endl;
  }

  /* Kode untuk mengecek solusi yang ada */
  cout << "Solusi :" <<endl;
  str += "Solusi :\n";
  clock_t Mulai = clock(); //Waktu Dimulai
  for (int a = 0 ; a < 4 ; a++){
    for(int b = 0 ; b <4 ; b++) {
      if (b != a){
        for (int c = 0 ; c < 4 ; c++) {
          if ((c != a) && (c != b)) {
            for (int d = 0 ; d < 4 ; d++) {
              if ((d !=a ) && (d != b) && ( d!= c)){
                ArrNum[n][0] = Num[a]; ArrNum[n][1] = Num[b];
                ArrNum[n][2] = Num[c]; ArrNum[n][3] = Num[d]; IsExist = false;
                for (int f = 0 ; f < n ; f++) {
                  for (int g = 0 ; g < 4 ; g++) {
                    if (g < 3) {
                      if (ArrNum[f][g] != ArrNum[n][g]) break;
                    } else {
                      if (ArrNum[f][g] == ArrNum[n][g]) IsExist = true;
                    }
                  }
                  if (IsExist == true) break;
                }

                if (IsExist == false ) {
                  n++;
                  for (int i = 0 ; i < 4 ; i++) { // Operator pertama
                    for (int j = 0 ; j < 4 ; j++) { // Operator kedua
                      for (int k = 0; k < 4 ; k++) { // Operator ketiga
                      /* Fungsi untuk mengatasi semua kemungkinan bracket (5 kemungkinan) */
                        if (fabs(OpFunc(Op[k], (OpFunc(Op[j], (OpFunc(Op[i],Num[a], Num[b])), Num[c])), Num[d]) -Hasil) <= EPS) { // ((n0 op0 n1) op1 n2) op2 d3
                          no++; cout<< "\033[1;36m"; cout << no << " "<< "((" << Num[a] << Op[i] <<  Num[b] << ")" << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "(("; str += to_string(int(Num[a])); str += Op[i]; str += to_string(int(Num[b])); str += ")"; str += Op[j]; str += to_string(int(Num[c])); str += ")"; str += Op[k]; str += to_string(int(Num[d])); str += "\n";
                        }
                        if (fabs(OpFunc(Op[k], (OpFunc( Op[i], Num[a], (OpFunc(Op[j],Num[b], Num[c])) ) ) , Num[d])- Hasil) <= EPS) { // (n0 op0 (n1 op1 n2)) op2 d3
                          no++; cout << "\033[1;33m"; cout << no << " "<< "(" << Num[a] << Op[i] << "("  << Num[b]  << Op[j]  << Num[c] << "))" << Op[k] << Num[d] << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "("; str += to_string(int(Num[a])); str += Op[i]; str += "("; str += to_string(int(Num[b])); str += Op[j]; str += to_string(int(Num[c])); str += "))"; str += Op[k]; str += to_string(int(Num[d])); str += "\n";
                        }
                        if (fabs(OpFunc(Op[j],OpFunc(Op[i], Num[a], Num[b]), OpFunc(Op[k], Num[c], Num[d])) - Hasil ) <= EPS) { // (n0 op0 n1) op1 (n2 op2 n3)
                          no++; cout << "\033[1;32m"; cout << no << " "<< "(" << Num[a] << Op[i] << Num[b] << ")" << Op[j] << "(" << Num[c] << Op[k] << Num[d] << ")" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "("; str += to_string(int(Num[a])); str += Op[i]; str += to_string(int(Num[b])); str += ")"; str += Op[j]; str += "("; str += to_string(int(Num[c])); str += Op[k]; str += to_string(int(Num[d])); str += ")"; str += "\n";
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[k],OpFunc(Op[j],Num[b],Num[c]), Num[d])) - Hasil) <= EPS) { // n0 op0 ((n1 op1 n2) op2 n3)
                          no++; cout << "\033[1;34m"; cout << no <<" " << Num[a] << Op[i] << "(("  << Num[b]  << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << ")" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += to_string(int(Num[a])); str += Op[i]; str += "(("; str += to_string(int(Num[b])); str += Op[j]; str += to_string(int(Num[c])); str += ")"; str += Op[k]; str += to_string(int(Num[d])); str += ")"; str += "\n";
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[j],Num[b],OpFunc(Op[k], Num[c],Num[d]))) - Hasil) <= EPS) { // n0 op0 (n1 op1 (n2 op2 n3))
                          no++; cout << "\033[1;35m"; cout << no << " " << Num[a] << Op[i] << "("  << Num[b] << Op[j] << "(" <<  Num[c] << Op[k] << Num[d] << "))" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += to_string(int(Num[a])); str += Op[i]; str += "("; str += to_string(int(Num[b])); str += Op[j]; str += "("; str += to_string(int(Num[c])); str += Op[k]; str += to_string(int(Num[d])); str += "))"; str += "\n";
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* Kode untuk menghitung waktu eksekusi */
  cout << "\033[0m";
  cout << "Waktu Eksekusi\t: " << (double)(clock() - Mulai)/CLOCKS_PER_SEC << "s\n";
  str += "Waktu Eksekusi\t: ";
  str += to_string(double(clock()-Mulai)/CLOCKS_PER_SEC);
  str += "s";
  str += "\n";

  /* Kode untuk menampilkan kartu masukan */
  str += "Kartu Masukan\t: ";
  for(int i = 0 ; i < 4 ; i++){
    str += NumString[i];
    str += " ";
  }
  str += "\n";

  /* Kode untuk mengecek jumlah solusi */
  if (no == 0){
    cout << "Tidak Ada Solusi" << endl;
    str += "Tidak Ada Solusi\n";
  }else{
    cout << "Jumlah solusi\t: " << no << endl;
    str += "Jumlah solusi\t: "; str += to_string(no);
  }

  /* Kode untuk menyimpan hasil */
  cout << "================================================" << endl;
  cout << "Apakah hasil ingin disimpan? (y/n): " << endl;
  cin >> pilihanSave;
  cout << "================================================" << endl;
  switch(pilihanSave){
    case 'y':
      cout << "Masukkan nama file untuk keluaran:" << endl;
      cin >> txtOut;
      cout << "================================================" << endl;
      fileOutput.open("../test/output/" + txtOut +".txt",std::ios::out);
      if(fileOutput.is_open()){
        fileOutput << str << endl;
        cout << "File output berhasil disimpan" << endl;
        cout << "================================================" << endl;
      }
      else{
        cout << "Gagal untuk melakukan proses penyimpanan" << endl;
        cout << "================================================" << endl;
      }
      break;
    case 'n':
      cout << "File tidak disimpan" << endl;
      cout << "================================================" << endl;
      break;
  }

  /* Kode untuk menutup program */
  cout << "\033[1;32m";
  cout << " T    H    A    N    K    Y    O    U    !    !"<<endl;
  cout << "  For using our app to solve your 24-Game :))  "<<endl;
  cout << "\033[0m";
  return 0;
}
