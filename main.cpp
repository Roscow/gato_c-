#include <iostream>

using namespace std;

void mostrar_logo(){
    cout<<"####################################"<<endl;
	cout<<"##             GATO#              ##"<<endl;
	cout<<"##________________________________##"<<endl;

}

void logo_P1vsP2(){
    cout<< "####################################"<<endl;
	cout<< "##        JUEGO P1 VS P2          ##"<<endl;
	cout<< "##________________________________##"<<endl;
}

void logo_P1vsPc(){
    cout<< "####################################"<<endl;
	cout<< "##        JUEGO P1 VS PC          ##"<<endl;
	cout<< "##________________________________##"<<endl;
}



void menu_principal(){
    mostrar_logo();
    int tipo_juego=0;
	cout<< "####################################"<<endl;
	cout<<  "##         Menu princial          ##"<<endl;
	cout<<  "##________________________________##"<<endl;
	cout<<  "##  Seleccione un modo            ##"<<endl;
	cout<<  "##    1- Player1 vs Player2       ##"<<endl;
	cout<<  "##    2- Player1 vs PC            ##"<<endl;
	cout<<  "##________________________________##"<<endl;
	cout<<  "ingrese...."	<<endl;
	cin>> tipo_juego;
}




int main()
{
    menu_principal();
   return 0;
}
