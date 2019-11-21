#include <iostream>
#include <stdlib.h>
#include <time.h>


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


void secuencia_jugadas(int var_comienza){
    string jugadas_par;
    string jugadas_impar;
    string jugador_actual;
    char simbolo_actual;
    bool cuadrante_logico;
    char cuadrante_num;
    bool ganar=false;
    int i=0, j=0,turno=0;

    //definir matriz
    char matriz[3][9];
    for(i=0;i<3;i++){
        for(j=0;j<=9;j++){
            matriz[i][j]=']';
            if((i==0 || i==1 || i==2) && (j==0 || j==3 || j==6) ){
                matriz[i][j]='[';
            }
        }
    }
    matriz[0][1]='1';
    matriz[0][4]='2';
    matriz[0][7]='3';
    matriz[1][1]='4';
    matriz[1][4]='5';
    matriz[1][7]='6';
    matriz[2][1]='7';
    matriz[2][4]='8';
    matriz[2][7]='9';

  if(var_comienza==0){
    jugadas_par="player2";
    jugadas_impar="player1";
  }
  if(var_comienza==1){
    jugadas_par="player1";
    jugadas_impar="player2";
  }
  turno=1;
  while( turno<=9 && ganar==false){
    cout<<"turno numero: "<<turno<<endl;

    if(turno % 2 !=0){
        cout<<jugadas_impar<<" es su turno"<<endl;
        simbolo_actual='x';
        jugador_actual=string(jugadas_impar);
    }
    if(turno % 2 ==0){
        cout<<jugadas_par<<" es su turno"<<endl;
        simbolo_actual='o';
        jugador_actual=string(jugadas_par);
    }
    //cout<<jugador_actual<<endl;
    turno=turno+1;

   //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

    //ingresasr el cuadrante donde se insertara
    cuadrante_logico=false;
    while(cuadrante_logico==false){
        cout<<"SELECCIONE UN CUADRANTE"<<endl;
        cin >>cuadrante_num;

        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                if(matriz[i][j]==cuadrante_num){
                    matriz[i][j]= simbolo_actual;
                    cout<<"se agrego simbolo"<<endl;
                    cuadrante_logico=true;
                }
            }
            cout<<endl;
        }
    }
    //revisar si alguien ha ganado
    //caso 1
    if(matriz[0][1]==simbolo_actual && matriz[0][4]==simbolo_actual && matriz[0][7]==simbolo_actual){
        ganar=true;
    }
    //caso 2
    if(matriz[1][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[1][7]==simbolo_actual){
        ganar=true;
    }
    //caso 3
    if(matriz[2][1]==simbolo_actual && matriz[2][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
    //caso 4
    if(matriz[0][1]==simbolo_actual && matriz[1][1]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
    //caso 5
    if(matriz[0][4]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][4]==simbolo_actual){
        ganar=true;
    }
     //caso 6
    if(matriz[0][7]==simbolo_actual && matriz[1][7]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 7
    if(matriz[0][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 8
    if(matriz[0][7]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
    system("cls");
  }
  if(ganar==true){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#      hay un ganador       #"<<endl;
        cout<<"#############################"<<endl;
        //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
  }
  cout <<"FELICIDADES "<<jugador_actual<<endl;
  if(ganar==false){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#          EMPATE           #"<<endl;
  }
}




//modo juego P1 VS P2
void contra_jugador(){
    char aux[2] ;
	int num=0;
	int var_quien_comienza=0;

	system("cls");
	mostrar_logo();
	logo_P1vsP2();

	cout<< "Elija un player cada jugador"<<endl;
	cout<< "ingrese cualquier tecla para continuar..."<<endl;
	cin>> aux;

    //azar
	srand(time(NULL));
	num = rand()%2;

	if(num==0){
        cout<<"comienza el Player1"<<endl;
        var_quien_comienza=0;
	}
	if(num==1){
        cout<<"comienza el Player2"<<endl;
        var_quien_comienza=1;
	}
	cout<<"presione una tecla para continuar";
	cin >>aux;
	system("cls");
	secuencia_jugadas(var_quien_comienza);
}







int main()
{
    contra_jugador();
   return 0;
}
