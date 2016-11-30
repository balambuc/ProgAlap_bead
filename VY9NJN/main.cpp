#include <iostream>

using namespace std;

#define MERET 100

void beolvas(int &N, int &M, int Min[MERET], int P[MERET][MERET]);
void megold(int N, int M, int &T,int Min[MERET], int P[MERET][MERET], int Nyert[MERET], int db[MERET]);
int Max(int j, int N, int P[MERET][MERET]);
int Db(int i, int N, int M, int Min[MERET], int P[MERET][MERET], int db[MERET]);
void kiir(int T, int Gyozt[MERET]);

int main()
{
    //Be
    int N, M, Min[MERET]= {}, P[MERET][MERET]= {};

    //Ki
    int T, Nyert[MERET]= {};

    beolvas(N, M, Min, P);

    //Db fv memorizacioja
    int db[MERET];
    for(int i=0; i<N; i++)
        db[i]=-1;

    megold(N, M, T, Min, P, Nyert, db);
    kiir(T, Nyert);

    return 0;
}

void beolvas(int &N, int &M, int Min[MERET], int P[MERET][MERET])
{
    bool hiba=false;
    int s=0, si=0;

    do {
        cerr << "Tanulok (N) es versenyek (M) szama szokozzel elvalasztva (N=[1..100], M=[1..100]):";
        cin >> N;
        cin >> M;
        hiba= cin.fail() || (cin.peek()!= '\n') || (N<1 || N>100) || (M<1 || M>100);
        if(hiba) {
            cerr << "HIBA!" << endl;
            cin.clear();
            cin.ignore(100,'\n');
        }

    } while(hiba);


    do {
        hiba=false;
        cerr << "A " << M << " verseny minimum ponthatarai (Mi) szokozzel elvalasztva (Mi=[0..50]):";
        for(int i=0; i<M; i++) {
            cin >> Min[i];
            hiba=hiba || (Min[i]<0 || Min[i]>50) || cin.fail() || ((cin.peek()!= '\n') && cin.peek()!=' ');
        }

        if(hiba) {
            cerr << "HIBA!" << endl;
            cin.clear();
            cin.ignore(100,'\n');
        }
    } while (hiba);

    cerr << "Kerem soronkent adja be a " << M << " verseny parametereit szokozzel elvalasztva a kovetkezo modon:" << endl;
    cerr << "\t indulok szama [1.." << N << "]" << endl;
    cerr << "\t versenyzo sorszama [1.." << N << "]" << " versenyzo eredmenye [1..100]" << endl;

    for(int i=0; i<M; i++) {
        do {
            hiba=false;
            cerr << "A(z) " << i+1 << ". verseny parameterei:";
            cin >> s;
            for(int j=0; j<s; j++) {
                cin >> si;
                hiba = hiba || si<1 || si>N || cin.fail() || ((cin.peek()!= '\n') && cin.peek()!=' ');
                cin >> P[si-1][i];
                hiba = hiba || P[si-1][i]<0 || P[si-1][i]>100 || cin.fail() || ((cin.peek()!= '\n') && cin.peek()!=' ');

            }
            if(hiba) {
                cerr << "HIBA!" << endl;
                cin.clear();
                cin.ignore(100,'\n');
            }
        } while(hiba);
    }
}

void megold(int N, int M, int &T,int Min[MERET], int P[MERET][MERET], int Nyert[MERET], int db[MERET])
{
    //megszamolas
    T=0;
    for(int i=0; i<N; i++)
        if(Db(i,N,M,Min,P,db)>=1)
            T++;

    //Nyert vektor inic
    for(int i=0; i<N; i++)
        Nyert[i]=i+1;

    //buborekrendezes
    //Egyszerre rendezi a nyert es a db halmazokat, igy a nyert halmazban a tanulok indexei is "helyukre kerulnek"
    for(int i=N-1; i>0; i--)
        for(int j=0; j<i; j++)
            if(db[j]<db[j+1]) {
                int S=db[j];
                db[j]=db[j+1];
                db[j+1]=S;
                S=Nyert[j];
                Nyert[j]=Nyert[j+1];
                Nyert[j+1]=S;
            }
}

int Max(int j, int N, int P[MERET][MERET])
{
    int s=P[0][j];
    for(int i=1; i<N; i++)
        if(P[i][j]>s)
            s=P[i][j];
    return s;
}

int Db(int i, int N, int M, int Min[MERET], int P[MERET][MERET], int db[MERET])
{
    if(db[i]!=-1)
        return db[i];
    int s=0;
    for(int j=0; j<M; j++)
        if(P[i][j]==Max(j, N, P) && P[i][j]>=Min[j])
            s++;
    db[i]=s;
    return s;
}

void kiir(int T, int Nyert[MERET])
{
    cerr << "Az egyeni gyozelmeket elertek szama, es sorszamaik gyozelmek szama szerint csokkeno, azon belul sorszam szerint novekvo sorrendben:" << endl;
    cout << T;
    if(T>0)
        cout << " " << Nyert[0];
    for(int i=1; i<T; i++)
        cout << " " << Nyert[i];
}
