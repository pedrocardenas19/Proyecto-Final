#ifndef frase_h
#define node_h
#include <string>
#include <vector>
using namespace std;

class Frase{

private:
  int contador = 0;
  string verbo;
  string oracion;
  vector <string> lista;

public:
  Frase();
  void ingresarFrase();
  vector <string> separarPalabras(vector<string> c);
  int encontrarVerbo(vector<string> c);
  void verificarSujeto(Frase f);
  void verificarPredicado(Frase f);
  string getOracion();
  vector <string> getVector();

};

#endif
