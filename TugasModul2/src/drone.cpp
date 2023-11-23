#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<math.h>
#include<fstream>
#include<string>

using namespace std;

double x=0.00,y=0.00;
double titik[2][2] = {{0,0},{0,0}};


// interface
void programShow(){
    cout << "List Program: "<<endl;
    cout << "1. Lokasi"<<endl;
    cout << "2. Gerak (titik)"<<endl;
    cout << "3. Gerak (kecepatan)"<<endl;
    cout << "4. Undo"<<endl;
    cout << "5. Redo"<<endl;
    cout << "6. Save"<<endl;
    cout << "7. Load"<<endl;
    cout << "0. Exit" <<endl;
}
void home(){
    system("CLS");
    cout << "Program Simulasi Drone"<<endl;
    cout << "==========================================="<<endl;
    programShow();
}

// lokasi
void lokasi(){
    cout<<"Lokasi Drone: ("<<setprecision(2)<<fixed<<x<<",";
    cout<<setprecision(2)<<fixed<<y<<")"<<endl;
}
// Gerak1
void gerak(double h, double v){
    titik[0][0] = x;  
    titik[0][1] = y;

    x = h+x;
    y = v+y;

    titik[1][0] = x;  
    titik[1][1] = y;
}
// Gerak2
void gerak_2(int cepat, int waktu, int sudut){
    titik[0][0] = x;  
    titik[0][1] = y;
    
    double vx, vy;
    vy = cepat*sin(sudut*M_PI/180);
    vx = cepat*cos(sudut*M_PI/180);
    x += vx*waktu;
    y += vy*waktu;
    
    titik[1][0] = x;  
    titik[1][1] = y;
}
// redo
void undo(){
    if (titik[0][0] == x and titik[0][1] == y){
        cout<<"Tidak dapat undo!"<<endl;
    } else
    {
        x = titik[0][0];
        y = titik[0][1];
        cout<<"Undo berhasil"<<endl;
    }
}
// redo
void redo(){
    if (titik[1][0] == x and titik[1][1] == y){
        cout<<"Tidak dapat redo!"<<endl;
    } else
    {
        x = titik[1][0];
        y = titik[1][1];
        cout<<"Redo berhasil"<<endl;
    }
}
// save
void save(){
    ofstream MyFile("data.txt");
    MyFile<<x<<endl;
    MyFile<<y<<endl;
    MyFile.close();
    cout<<"Save Berhasil!"<<endl;
}
// load
void load(){
    string myText;
    int line = 0;
    ifstream MyReadFile("data.txt");
    while (getline (MyReadFile, myText))
    {
        if (line == 0)
        {
            x = stoi(myText);
        } else if (line == 1)
        {
            y = stoi(myText);
        }
        line++;
    }
    MyReadFile.close();
    titik[1][0]=x;
    titik[1][1]=y;
    cout<<"Load Berhasil!"<<endl;
}



int main(){
    // Deklarasi
    int program;
    int gerx,gery;
    int v, t, theta;
    char balik;
    // Program
    home();
    cout << endl << "Pilih program: "; cin >> program;
    while (program != 0)
    {
        if (program == 1)
    {
        lokasi();
    } else if (program == 2)
    {
        cout<<"Gerak (titik)"<<endl;
        cout<< "Pindah horizontal: ";cin>>gerx;
        cout<<"Pindah vertikal: ";cin>>gery;
        gerak(gerx,gery);
    } else if (program == 3)
    {
        cout<<"Gerak (kecepatan)"<<endl;
        cout <<"Kecepatan: ";cin>>v;
        cout<<"Waktu: ";cin>>t;
        cout<<"Sudut: ";cin>>theta;
        gerak_2(v,t,theta);
    } else if (program == 4)
    {
        undo();
    } else if (program == 5)
    {
        redo();
    } else if (program == 6)
    {
        save();
    } else if (program == 7)
    {
        load();
    } else {
        cout<<"Error: Nomor Input Salah"<<endl;
    }
        cout<<"Apakah ingin kembali ke home? (y/n) ";
        cin>>balik;
        if (balik == 'y' or balik =='Y')
        {
            home();
        }
        cout<<endl;
        cout << "Pilih program: "; cin >> program;

    }

    return 0;
}