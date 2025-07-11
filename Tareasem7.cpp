#include <iostream>

using namespace std;

string nombre[3];
float nota[3];
string estado[3];
string cedula[3];
string buscaporcedula[3];
string condicionbuscada[3];


void inicializar();
void menu();
void incluir();
void reporte();
void consultar();
void modificar();
void eliminar();
void submenu();
void reportecondicion();
void reportedatos();

 
 void menu() {
	int opcion = 0;
	
	do{
		cout<<"1- Inicializar arreglos" << endl;
		cout<<"2- Incluir estudiantes" << endl;
		cout<<"3- Reporte" << endl;
		cout<<"4- Modificar estudiantes" << endl;
		cout<<"5- Eliminar estudiantes" << endl;
		cout<<"6- Submen� reportes" << endl;
		cout<<"7- Consultar datos" << endl;
		cout<<"8- Salir" << endl;
		cout<<"Ingrese un valor: ";
		cin>> opcion;
		switch (opcion){
  		
		  case 1: inicializar(); break;
		  case 2: incluir(); break;
		  case 3: reporte(); break;
		  case 4: modificar(); break;
		  case 5: eliminar(); break;
		  case 6: submenu(); break;
		  case 7: consultar(); break;
		  
		  default : cout << "La opcion es incorrecta. " << endl;
		  			break;
  			
  		}
  	} while (opcion != 7);
		
	
	
	}

 void inicializar(){
	for(int i=0; i<3; i++) 	
		{ 
			nombre[i]="";
			cedula[i]="";
			nota[i]=0;
			estado[i]="";
			
		
		}
			cout << "Arreglos inicializados.\n";
		
  		}
  	
	  
	  
 void incluir(){
 
 for (int i=0; i<3; i++ ){
		cout << "Ingrese el nombre: ";
		cin >> nombre[i];
		cout << "Ingrese la cedula: ";
		cin >> cedula[i];
		cout << "Ingrese la nota: ";
		cin >> nota[i];
		
		if (nota[i]< 60)
		estado[i]= "Reprobado";
		else if (nota[i] >=60 && nota[i] <70)
     	estado[i]= "Aplazado";
    	else
    	estado[i]= "Aprobado";
		cout << "Notas han sido ingresadas" << endl;
		
		}
 }
		
void reporte() {
		for(int i=0; i<3; i++){
	  		cout << "Nombre: " <<	nombre[i] << " Nota: " << nota[i] << " Estado: " << estado[i]  << endl;
	}
		
 
 }
	


void consultar(){  // se debe de buscar por medio de cedula y solcicitar todos los datos
	string buscaporcedula;
	cout <<"Ingrese el numero de cedula a localizar: ";
	cin >> buscaporcedula;
	
	bool encontrado= false;
	
	for(int i=0; i < 3; i++){ 
		if(cedula[i] == buscaporcedula){
			cout <<"Nombre: " <<	nombre[i] << " Nota: " << nota[i] << " Estado: " << estado[i]  << endl;
			encontrado = true;
			break;
		}
	
	
	}
	if(!encontrado){
		cout <<" Estudiante no existe";
	}

 }

void modificar(){
	string buscaporcedula;
	cout <<"Ingrese el numero de cedula a localizar: ";
	cin >> buscaporcedula;
	
	bool encontrado= false;
	
	for(int i=0; i < 3; i++){ 
		if(cedula[i] == buscaporcedula){
			cout <<"Ingrese nuevo estudiante: " << endl;
			cin>> nombre[i];
			cout <<"Ingrese nueva cedula: " << endl;
			cin>> cedula[i];
			cout <<"Ingrese nueva nota: " << endl;
			cin>> nota[i];
			
			if (nota[i]< 60)
			estado[i]= "Reprobado";
			else if (nota[i] >=60 && nota[i] <70)
     		estado[i]= "Aplazado";
    		else
    		estado[i]= "Aprobado";
			cout << "Notas han sido actualizadas" << estado [i] << endl;
		
			encontrado = true;
			break;
		}
	
		if(!encontrado){
		cout <<" Estudiante no existe";
	}
 }

}

void eliminar() { 
	string buscaporcedula;
	cout <<"Ingrese el numero de cedula a localizar: ";
	cin >> buscaporcedula;

	bool encontrado= false;
	
	for(int i=0; i < 3; i++){ 
		if(cedula[i] == buscaporcedula){
			nombre[i]="";
			cedula[i]="";
			nota[i]=0;
			// validar el tema de poder quitar la nota 
			
			if (nota[i]< 60)
			estado[i]= "Reprobado";
			else if (nota[i] >=60 && nota[i] <70)
     		estado[i]= "Aplazado";
    		else
    		estado[i]= "Aprobado";
			cout << "Notas han sido actualizadas" << estado [i] << endl;
			
			encontrado = true;
			break;
		}
	
		if(!encontrado){
		cout <<" Estudiante no existe";
	}
 }
	
	
}

void submenu(){ 
	
	int opcion = 0;  // variable local
  	
  	do{
  		cout << endl;
  		cout << "1-Reporte por condici�n: "  << endl;
  		cout << "2-Reporte de todos los datos: "  << endl;
  		cout << "3-Regresar"  << endl;
  		cout << "Ingrese un valor: ";
  		cin >> opcion;
  		switch (opcion){
  		
		  case 1:reportecondicion(); break;
		  case 2:reportedatos(); break;
		  case 3:menu(); break;
		 
		  default : cout << "La opcion es incorrecta " << endl;
		  			break;
  			
  		}
  	} while (opcion != 3);
  

}

void reportecondicion(){
	int opcion;
	cout << endl;
	cout <<"Seleccione la condici�n a validar: ";
	cout <<"1-Aprobado." << endl;
	cout <<"2-Aplazado." << endl;	
	cout <<"3-Reprobado." << endl;
	cout <<"Opcion: ";
	cin >> opcion;
	
	string condicionbuscada;
	
	switch(opcion) {
        case 1: condicionbuscada = "Aprobado"; break;
        case 2: condicionbuscada = "Aplazado"; break;
        case 3: condicionbuscada = "Reprobado"; break;
        default:
            cout << "Opci�n inv�lida." << endl;
            return;
    }
	bool encontrado = false;
	for(int i = 0; i < 3; i++) {
		if (estado[i] == condicionbuscada) {
			cout << nombre[i]
                 << " | C�dula: " << cedula[i]
                 << " | Nota: " << nota[i]
                 << "\n";
            encontrado = true;
        }
}

	if(!encontrado)
		cout << "No se encontr� ning�n estudiante." << endl;
}

void reportedatos(){
	
	 cout << "REPORTE COMPLETO DE ESTUDIANTES" << endl;
	 for (int i = 0; i < 3; i++) {
        cout << nombre[i]
             << " | C�dula: " << cedula[i]
             << " | Nota: " << nota[i]
             << " | Estado: " << estado[i] << endl;
    }
    
    float suma=0;
    for(int i=0; i<3; i++){ 
    	suma+= nota[i];
    	}
    float promedio= suma/3;
    	
    cout << "El promedio general es: " << promedio << endl;
    
	float promMax = nota[0], promMin = nota[0];
	
	for (int i = 1; i < 3; i++) {
        if (nota[i] > promMax) promMax = nota[i];
        if (nota[i] < promMin) promMin = nota[i];
	
	if(nota[i]> promedio){
		cout <<"Estudiante con nota mayor al promedio" << promMax
			 << " | Nombre: " << nombre[i]
			 << " | C�dula: " << cedula[i]
             << " | Nota: " << nota[i]
             << " | Estado: " << estado[i] << endl;
	
	}
	else{
		cout <<"Estudiante con nota menor al promedio" 
			 << " | Nombre: " << nombre[i]
			 << " | C�dula: " << cedula[i]
             << " | Nota: " << nota[i]
             << " | Estado: " << estado[i] << endl;
	
	}
	

}

int main(){
	
	
	menu();
	
	return 0;
	
}
