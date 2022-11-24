#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Frase.h"

using namespace std;

Frase::Frase(){
  ingresarFrase();
}


void Frase :: ingresarFrase(){
    cout<<"ingrese la oración a analizar"<<endl;
    string oracion;
    cin>>oracion;
    this->oracion = oracion;
    }

string Frase::getOracion(){
  return this->oracion;
}

vector <string> Frase:: getVector(){
  
  return this->lista;
  
}

vector<string> Frase:: separarPalabras(vector<string> c){
	stringstream stream(this->getOracion());
  string palabra;
	while(std::getline(stream, palabra , ' '))
	c.push_back(palabra);
  return c;
  
}



int Frase::encontrarVerbo(vector<string> c){
  
  int pos;
  string archivo = "verbos.txt";
  this->contador = 0 ;
  ifstream file( archivo.c_str() ) ;

  
  if( file.is_open() ){
    
    for(int i =0; i < c.size() ; i++){
      
      string palabra= c[i];
      string candidate;
		    while( file >> candidate ) {
        
			    if(palabra == candidate ) {
            
            this->contador ++;
            
            pos=i ;
            
          }
		    }
      }
    
  }
    
  else{
    cerr << "Error! File not found!\n" ;
		exit(1);
  }
  
  if (this->contador!=1){
    cout<<"Oración invalida"<<endl;
    exit(1);
    
  }
  return pos;
}


void Frase:: verificarSujeto(Frase f){
  
  bool encontrado;
  int estado_actual;
  int estado_anterior;
  int pos_v = f.encontrarVerbo(f.getVector());
  string sustantivos = "sustantivos.txt";
  string enlaces = "enlaces.txt";
  string determinantes = "determinantes.txt";


  for(int i = pos_v-1 ; i>=0 ; i--){
    
    encontrado = false;
    ifstream file( sustantivos.c_str() ) ;
    
    if( file.is_open() ){  
      
      string palabra= f.getVector()[i];
      string candidate;
		  while( file >> candidate ) {
        
			  if(palabra == candidate ) {
          encontrado=true;
          estado_actual=1;
        }

      } 
  
    }
    
    ifstream file2(enlaces.c_str() ) ;
    if( file2.is_open() ){
      
      string palabra= f.getVector()[i];
      string candidate;
		  while( file2 >> candidate ) {
        
			  if(palabra == candidate ) {
          
          encontrado=true;
          estado_actual=2; 
          
        }
        
      }
      
    }
    
  ifstream file3(determinantes.c_str() ) ;
    if( file3.is_open() ){  
      
      string palabra= f.getVector()[i];
      string candidate;
		  while( file3 >> candidate ) {
        
			  if(palabra == candidate ) {
          
          encontrado=true;
          estado_actual=3; 
          
        }
        
      } 
      
    }
    
    if(estado_actual!=estado_anterior){
      
      estado_anterior=estado_actual;
      
    }
      
    else{
      
      cout<<"Oración invalida"<<endl;
      
      exit(1);
      
    }
    
  }
  
}





void Frase:: verificarPredicado(Frase f){
  
  bool encontrado;
  int estado_actual;
  int estado_anterior;
  int pos_v = f.encontrarVerbo(f.getVector());
  string sustantivos = "sustantivos.txt";
  string enlaces = "enlaces.txt";
  string determinantes = "determinantes.txt";

  for(int i = pos_v+1 ; i<f.getVector().size() ; i++){
    
    encontrado = false;
    ifstream file( sustantivos.c_str() ) ;
    if( file.is_open() ){
      
      string palabra= f.getVector()[i];
      string candidate;
		  while( file >> candidate ) {
        
        if(palabra == candidate ) {
          encontrado=true;
          estado_actual=1;
        }

      } 
  
    }
    
  ifstream file2(enlaces.c_str() ) ;
  
  if( file2.is_open() ){  
      string palabra= f.getVector()[i];
      string candidate;
		  while( file2 >> candidate ) {
        
			  if(palabra == candidate ) {
           encontrado=true;
           estado_actual=2; 
          
        }
        
      }
    
    }
  ifstream file3(determinantes.c_str() ) ;
  if( file3.is_open() ){  
    
      string palabra= f.getVector()[i];
      string candidate;
		  while( file3 >> candidate ) {
        
			  if(palabra == candidate ) {
          
          encontrado=true;
          estado_actual=3; 
          
        }
        
      }  
    
    }
    
    if(estado_actual!=estado_anterior){
      
      estado_anterior=estado_actual;
      
    }
      
    else{
      
      cout<<"Salí por acá Oración invalida"<<endl;
      exit(1);
      
    }
    
  }
  
}


int main(){
  Frase *oracion= new Frase();
  oracion->separarPalabras(oracion->getVector());
  oracion->encontrarVerbo(oracion->getVector());
  oracion->verificarSujeto(*oracion);
  oracion->verificarPredicado(*oracion);
}
