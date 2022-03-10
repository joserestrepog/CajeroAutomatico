#include <iostream>
#include <string>
#include <conio.h>
#define tam 1000
using namespace std;

//******************* INICIO STRUCT CUENTAS ***********************//

struct cuentas{
	string nombre;
	string clave;
	unsigned long celular,cedula;
	double saldo;
	string correo;	
};

//******************* FIN STRUCT CUENTAS ***********************//

//******************* INICIO PEDIR CLAVE ***********************//

bool validar(string clave){
	int longitud,i;
	bool t=true;
	longitud=clave.size();
	for(i=0;i<longitud;i++){
  		if(clave[i]<48 || clave[i]>57){
    		t=false;break;
 		  }
	}
	return t;
}

string recibirclave(string clave){
	int cantletras;	
	bool comprob=true,respuesta;
	char a;
	cout<<"                                    INGRESE SU CLAVE DE ACCESO: ";
	cantletras=1;
  	do{
    	a=getch();
     	cout<<"*";
     	clave+=a;
     	cantletras++;
	 	if(cantletras==5){
        	comprob=validar(clave);//SE VALIDA QUE LA CADENA SOLO CONTENGA NUMEROS
         	if (comprob==false){
           		cantletras=1;
		       system("CLS");   	
    	       cout<<endl<<"\a"<<"INGRESE NUEVAMENTE LA CLAVE."<<endl;
        	   clave=" ";
         	}	
    	}
 	}while(cantletras<=4 || comprob==false);
 	return clave;
}             

//******************* FIN PEDIR CLAVE ***********************//

//******************* INICIO CANCELACION DE CUENTAS ***********************//

void cancelacioncuentas(cuentas cuent[]){
	system("cls");
	int i=0,c=0,j=0,opc2=0;
	long ced=0;
	string clave;
	cout<<"                                    *******************************************************"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *               CANCELACION DE CUENTA                 *"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *******************************************************"<<endl<<endl;
	cout<<"                                    INGRESE EL NUMERO DE LA CUENTA: ";
	cin>>ced;
	clave=recibirclave(clave);
	system("cls");
	for(i=0;i<tam;i++){
		if(cuent[i].cedula==ced && cuent[i].clave==clave){
			j=i;
			c++;
			if(cuent[j].saldo>=0){
				system("cls");
				cout<<endl<<"\a"<<"LOS DATOS QUE USTED INGRESO SON LOS SIGUIENTES:"<<endl<<endl<<"CUENTA: "<<ced<<endl<<endl<<"OPRIMA"<<endl<<endl<<"1.SI."<<endl<<"2.NO."<<endl<<endl<<"DESEA CONTINUAR? ";
				cin>>opc2;
				switch(opc2){
					case 1:{
						system("cls");
						cout<<endl<<"\a"<<"SU SALDO A FAVOR ES: "<<cuent[j].saldo<<endl<<endl;
						cuent[j].cedula=0;
						cuent[j].clave=" ";
						cuent[j].celular=0;
						cuent[j].saldo=0;
						cuent[j].correo=" ";
						cuent[j].nombre=" ";
						cout<<endl<<"\a"<<"SU CUENTA HA SIDO ELIMINADA DE NUESTRO SISTEMA SATISFACTORIAMENTE."<<endl<<endl;
						break;
					}
					case 2:{
						return;
						break;
					}
				}
			}else{
				system("cls");
				cout<<endl<<"\a"<<"USTED TIENE UNA DEUDA DE: "<<cuent[j].saldo<<" CON LA ENTIDAD, CANCELE ESE VALOR PARA ELIMINAR SU CUENTA."<<endl<<endl;
			}	
		}
	}
	if(c==0){
		cout<<endl<<"\a"<<"DATOS INCORRECTOS, INTENTE NUEVAMENTE."<<endl<<endl;
	}
system("PAUSE");
}

//******************* FIN CANCELACION DE CUENTAS ***********************//

//******************* INICIO RETIROS ***********************//

void retiros(cuentas cuent[]){
	system("cls");
	int i=0,c=0,j=0,opc2=0;
	unsigned long ced=0,retiro=0;
	string clave;
	cout<<"                                    *******************************************************"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *                      RETIROS                        *"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *******************************************************"<<endl<<endl;
	cout<<"                                    INGRESE EL NUMERO DE LA CUENTA: ";
	cin>>ced;
	clave=recibirclave(clave);
	system("cls");
	for(i=0;i<tam;i++){
		if(cuent[i].cedula==ced && cuent[i].clave==clave){
			j=i;
			c++;
			cout<<endl<<"                                    INGRESE EL VALOR A RETIRAR: ";
			cin>>retiro;
			if(cuent[j].saldo>=retiro+2000){
				system("cls");
				cout<<endl<<"\a"<<"LOS RETIROS TIENEN UN COSTO DE $2000"<<endl<<endl<<"OPRIMA"<<endl<<endl<<"1.SI."<<endl<<"2.NO."<<endl<<endl<<"DESEA CONTINUAR? ";
				cin>>opc2;
				switch(opc2){
					case 1:{
						system("cls");
						cuent[j].saldo=cuent[j].saldo-retiro-2000;
						cout<<endl<<"\a"<<"SE RETIRARON "<<retiro<<" DE SU CUENTA, SU SALDO ACTUAL ES: "<<cuent[j].saldo<<endl<<endl;
						break;
					}
					case 2:{
						return;
						break;
					}
				}
			}else{
				system("cls");
				cout<<endl<<"\a"<<"FONDOS INSUFICIENTES."<<endl<<endl;
			}
			
		}
	}
	if(c==0){
		cout<<endl<<"\a"<<"DATOS INCORRECTOS, INTENTE NUEVAMENTE."<<endl<<endl;
	}
	system("PAUSE");
}

//******************* FIN RETIROS ***********************//

//******************* INICIO CONSULTAS DE SALDO ***********************//

void consultasaldo(cuentas cuent[]){
	system("cls");
	int i=0,c=0,opc2,j=0;
	long ced=0;
	string clave;
	cout<<"                                    *******************************************************"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *                CONSULTAS DE SALDO                   *"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *******************************************************"<<endl<<endl;
	cout<<"                                    INGRESE EL NUMERO DE LA CUENTA: ";
	cin>>ced;
	clave=recibirclave(clave);
	system("cls");
	for(i=0;i<tam;i++){
		if(cuent[i].cedula==ced && cuent[i].clave==clave){
			j=i;
			c++;
			cout<<endl<<"\a"<<"LA CONSULTA DE SALDO TIENE UN COSTO DE $1500"<<endl<<endl<<"OPRIMA"<<endl<<endl<<"1.SI."<<endl<<"2.NO."<<endl<<endl<<"DESEA CONTINUAR? ";
			cin>>opc2;
			switch(opc2){
				case 1:{
					if(cuent[j].saldo>=1500){
						system("cls");
						cuent[j].saldo=cuent[j].saldo-1500;
						cout<<endl<<"\a"<<"SU SALDO ES: "<<cuent[j].saldo<<endl<<endl;
					}else{
						system("cls");
						cout<<endl<<"\a"<<"FONDOS INSUFICIENTES."<<endl<<endl;
					}
					
					break;
				}
				case 2:{
					return;
					break;
				}
			}
		}
	}
	if(c==0){
		cout<<endl<<"\a"<<"DATOS INCORRECTOS, INTENTE NUEVAMENTE."<<endl<<endl;
	}
	system("PAUSE");
}

//******************* FIN CONSULTAS DE SALDO ***********************//

//******************* INICIO CONSIGNACIONES ***********************//

void consignaciones(cuentas cuent[]){
	system("cls");
	int i=0,c=0,opc2=0,j=0;
	long ced=0;
	unsigned long saldo;
	string nomb;
	cout<<"                                    *******************************************************"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *                    CONSIGNACIONES                   *"<<endl;
	cout<<"                                    *                                                     *"<<endl;
	cout<<"                                    *******************************************************"<<endl<<endl;
	cout<<"                                    INGRESE EL NUMERO DE LA CUENTA A LA QUE VA A CONSIGNAR: ";
	cin>>ced;
	fflush(stdin);
	cout<<"                                    INGRESE EL NOMBRE DE QUIEN REALIZA LA TRANSACCION: ";
	getline(cin,nomb);
	for(i=0;i<tam;i++){
		if(cuent[i].cedula==ced){
			cout<<"                                    INGRESE EL VALOR A CONSIGNAR: ";
			cin>>saldo;
			j=i;
			c++;
		}
	}
	if(c==0){
		system("cls");
		cout<<endl<<"\a"<<"ESE NUMERO DE CUENTA NO SE ENCUENTRA REGISTRADO EN NUESTRO SISTEMA."<<endl<<endl;
		system("PAUSE");
		return;
	}
	system("cls");
	cout<<endl<<"\a"<<"LOS DATOS QUE USTED INGRESO SON LOS SIGUIENTES:"<<endl<<endl<<"CUENTA: "<<ced<<endl<<"NOMBRE DE QUIEN CONSIGNA: "<<nomb<<endl<<"VALOR A CONSIGNAR: "<<saldo<<endl<<endl<<"RECUERDE QUE A CADA CONSIGNACION SE LE HACE EL DESCUENTO DEL 4 POR MIL."<<endl<<endl<<"OPRIMA"<<endl<<endl<<"1.SI."<<endl<<"2.NO."<<endl<<endl<<"DESEA CONTINUAR? ";
	cin>>opc2;
	switch(opc2){
		case 1:{
			system("cls");
			saldo=saldo-(saldo*0.004);
			cuent[j].saldo=cuent[j].saldo+saldo;
			cout<<endl<<"\a"<<"CONSIGNACION REALIZADA."<<endl<<endl;
			system("PAUSE");
			break;
		}	
		case 2:{
			system("cls");
			return;
			break;
		}
	}
}

//******************* FIN CONSIGNACIONES ***********************//

//******************* INICIO CREACION DE CUENTAS ***********************//

void creacioncuentas(cuentas cuent[]){
	system("cls");
	int i=0,opc2=0;
	unsigned long cel,cedu;
	string corr,nomb,clave;
	cout<<"                                   *******************************************************"<<endl;
	cout<<"                                   *                                                     *"<<endl;
	cout<<"                                   *                 CREACION DE CUENTAS                 *"<<endl;
	cout<<"                                   *                                                     *"<<endl;
	cout<<"                                   *******************************************************"<<endl<<endl;
	cout<<"                                    INGRESE SU NUMERO DE CEDULA: ";
	cin>>cedu;
	for(i=0;i<tam;i++){
		if(cuent[i].cedula==cedu){
			system("cls");
			cout<<endl<<"\a"<<"LA CUENTA YA EXISTE EN NUESTRO SISTEMA."<<endl<<endl;
			system("PAUSE");
			system("cls");
			return;
		}
	}
	fflush(stdin);
	cout<<"                                    INGRESE SU NOMBRE COMPLETO: ";
	getline(cin,nomb);
	fflush(stdin);
	cout<<"                                    INGRESE SU CORREO ELECTRONICO: ";
	getline(cin,corr);
	cout<<"                                    INGRESE SU NUMERO CELULAR: ";			
	cin>>cel;
	clave=recibirclave(clave);//PEDIR CLAVE
	system("cls");
	cout<<endl<<"\a"<<"LOS DATOS QUE USTED INGRESO SON LOS SIGUIENTES:"<<endl<<endl<<"CEDULA: "<<cedu<<endl<<"NOMBRE: "<<nomb<<endl<<"CORREO: "<<corr<<endl<<"CELULAR: "<<cel<<endl<<endl<<"OPRIMA"<<endl<<endl<<"1.SI."<<endl<<"2.NO."<<endl<<endl<<"DESEA CONTINUAR? ";
	cin>>opc2;
	switch(opc2){
		case 1:{
			for(int i=0;i<tam;i++){
				if(cuent[i].cedula==0){
					cuent[i].cedula=cedu;
					cuent[i].celular=cel;
					cuent[i].nombre=nomb;
					cuent[i].correo=corr;
					cuent[i].clave=clave;
					system("cls");
					break;
				}
			}
			system("cls");
			cout<<endl<<"\a"<<"SU NUMERO DE CUENTA ES: "<<cedu<<endl<<endl;
			system("PAUSE");
			return;
		}	
		case 2:{
			system("cls");
			return;
			break;
		}
	}
	system("cls");
}

//******************* FIN CREACION DE CUENTAS ***********************//

//******************* INICIO LIMPIAR CUENTAS ***********************//

void limpiarcuentas(cuentas cuent[]){
	for(int i=0;i<tam;i++){
		cuent[i].cedula=0;
		cuent[i].clave=" ";
		cuent[i].celular=0;
		cuent[i].saldo=0;
		cuent[i].correo=" ";
		cuent[i].nombre=" ";
	}
}

//******************* FIN LIMPIAR CUENTAS ***********************//

int main(){
	int opc;
	system("color 3F");
	cuentas cuent[tam];
	limpiarcuentas(cuent);
	do{
		system("cls");
		cout<<"                                   ********************************************************"<<endl;
		cout<<"                                   *                                                      *"<<endl;
		cout<<"                                   *                     BIENVENIDOS                      *"<<endl;
		cout<<"                                   *                                                      *"<<endl;
		cout<<"                                   ********************************************************"<<endl;
		cout<<"                                   *                                                      *"<<endl;
		cout<<"                                   *              1. CREACION DE CUENTA.                  *"<<endl;
		cout<<"                                   *              2. CONSIGNACIONES.                      *"<<endl;	
		cout<<"                                   *              3. CONSULTAS DE SALDO.                  *"<<endl;
		cout<<"                                   *              4. RETIROS.                             *"<<endl;
		cout<<"                                   *              5. CANCELACION DE UNA CUENTA.           *"<<endl;
		cout<<"                                   *                                                      *"<<endl;
		cout<<"                                   ********************************************************"<<endl<<endl;
		cout<<"                                       INGRESE EL NUMERO DEL PROCESO QUE VA A REALIZAR: ";
		cin>>opc;
		switch(opc){
			case 1:{
				creacioncuentas(cuent);
				break;
			}
			case 2:{
				consignaciones(cuent);
				break;
			}
			case 3:{
				consultasaldo(cuent);
				break;
			}
			case 4:{
				retiros(cuent);
				break;
			}
			case 5:{
				cancelacioncuentas(cuent);
				break;
			}
			default:{
				system("cls");
				cout<<endl<<"\a"<<"ESA OPCION NO ESTA EN NUESTRO MENU, INTENTE NUEVAMENTE."<<endl<<endl;
				system("PAUSE");
				system("cls");
				break;
			}
		}
	}while(opc<0 || opc>=0);	
system("PAUSE");
exit(0);
}
