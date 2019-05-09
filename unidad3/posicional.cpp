#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> revierte_digitos(int numero){
  vector<int> digitos;
  int cociente = numero;
  int residuo;
  while( cociente > 0 ){
    residuo = cociente % 10;
    cociente = cociente / 10;
    digitos.push_back(residuo);
  }
  return digitos;
}

int maximo(int a, int b){
  if (a > b){
    return a;
  }
  else{
    return b;
  }
}

int signo(int num){
  if(num >= 0){
    return 1;
  }
  else{
    return -1;
  }
}

class Nivel {
  private:
    int valor;
  public:
    Nivel(int _valor);
    int get_valor();
    void agrega(int cantidad);
};
Nivel::Nivel(int _valor){
  valor = _valor;
}
int Nivel::get_valor(){
  return valor;
}
void Nivel::agrega(int cantidad){
  valor = valor + cantidad;
}

class Entero {
private:
  vector<Nivel> niveles;
public:
  Entero(int valor);
  Entero(vector<int> digitos_revertidos);
  vector<Nivel> get_niveles();
  Entero suma(Entero termino);// suma(+)
  Entero inverso_aditivo(); // -Entero
  Entero resta(Entero termino); // resta(-)
  Entero multiplica(Entero factor); // multiplicación (*)
  Entero copia();
  Entero cajas();
  Entero hacia_arriba(int salto);
  Nivel nivel(int indice);
  void agrega_a_nivel(int indice, int cantidad);
  vector<Entero> divide(Entero divisor); // retorna cociente y residuo
};
Entero::Entero(int valor){
  vector<int> digitos_revertidos = revierte_digitos(valor);
  Nivel nivel(0);
  for (int i=0; i < digitos_revertidos.size(); i++){
    nivel = Nivel(digitos_revertidos[i]);
    niveles.push_back(nivel);
  }
}
Entero::Entero(vector<int> digitos_revertidos){
  Nivel nivel(0);
  for (int i=0; i < digitos_revertidos.size(); i++){
    nivel = Nivel(digitos_revertidos[i]);
    niveles.push_back(nivel);
  }
}
vector<Nivel> Entero::get_niveles(){
  return niveles;
}
ostream& operator<<(ostream& output, Entero entero){
  vector<Nivel> niveles = entero.get_niveles();
  for (int i = niveles.size()-1; i > -1; i--){
    output << "|" << niveles[i].get_valor();
  }
  output << "|";
  return output;
}
Entero operator+(Entero entero, Entero termino){
  return entero.suma(termino);
}
Entero operator-(Entero entero, Entero termino){
  return entero.resta(termino);
}
Entero operator*(Entero entero, Entero factor){
  return entero.multiplica(factor);
}
vector<Entero> operator/(Entero entero, Entero divisor){
  return entero.divide(divisor);
}
// SUMA ######################################################
Entero Entero::suma(Entero termino){
  vector<int> digitos_resultado;
  vector<Nivel> corto, largo;
  if (get_niveles().size() > termino.get_niveles().size()){
    largo = get_niveles();
    corto = termino.get_niveles();
  }
  else {
    largo = termino.get_niveles();
    corto = get_niveles();
  }
  // añade niveles a cero al número más corto
  for (int i = corto.size(); i < largo.size(); i++){
    corto.push_back(Nivel(0));
  }
  // suma nivel a nivel
  for (int i = 0; i < largo.size(); i++){
    digitos_resultado.push_back(corto[i].get_valor() + largo[i].get_valor());
  }
  return Entero(digitos_resultado);
}
// 'RESTA'  ###################################################
Entero Entero::inverso_aditivo(){
  vector<int> digitos_resultado;
  int valor_invertido;
  for (int i=0; i < niveles.size(); i++){ // Ciclo sobre mis niveles
    valor_invertido = -1 * niveles[i].get_valor(); // negativo del nivel i
    digitos_resultado.push_back(valor_invertido); 
  }
  return Entero(digitos_resultado);
}
Entero Entero::resta(Entero termino){
  Entero inverso_aditivo_termino = termino.inverso_aditivo();
  return suma(inverso_aditivo_termino);
}
// MULTIPLICA  ################################################
Entero Entero::multiplica(Entero factor){
  vector<Nivel> niveles_factor = factor.get_niveles();
  vector<int> digitos_resultado;
  int imax = niveles.size();
  int jmax = niveles_factor.size();
  int kmax = 0;     // Niveles del resultado (antes de "normalizar")
  int valor_ij = 0; // Producto de dos niveles (i mio, j de factor)
  int dir_ij = 0;   // Dónde "acumular" un producto de dos niveles
  if( imax > 1 && jmax > 1){
    kmax = imax*jmax - 1;
  }
  else{
    kmax = maximo(imax,jmax);
  }
  // Inicializa el resultado
  for(int k=0; k < kmax; k++){      // con la cantidad adecuada de digitos,
    digitos_resultado.push_back(0); // con cada digito a cero
  }
  for(int i=0; i < imax; i++){ // Ciclo sobre mis niveles
    for(int j=0; j < jmax; j++){ // Ciclo sobre los niveles de factor
      valor_ij = niveles[i].get_valor() * niveles_factor[j].get_valor();
      dir_ij = i + j;
      digitos_resultado[dir_ij] += valor_ij;
    }
  }
  return Entero(digitos_resultado);
}
// DIVIDE ########################################################
Entero Entero::copia(){
  vector<int> digitos_resultado;
  int valor;
  for (int i=0; i < niveles.size(); i++){ // Ciclo sobre mis niveles
    valor = niveles[i].get_valor(); 
    digitos_resultado.push_back(valor); 
  }
  return Entero(digitos_resultado);
}
Entero Entero::cajas(){
  vector<int> digitos_resultado;
  for (int i=0; i < niveles.size(); i++){ // Ciclo sobre mis niveles
    digitos_resultado.push_back(0); 
  }
  return Entero(digitos_resultado);
}
Entero Entero::hacia_arriba(int salto){
  vector<int> digitos_resultado;
  // Añade "salto" niveles con valor cero
  for (int i=0; i < salto; i++){
    digitos_resultado.push_back(0); 
  }
  int valor;
  for (int i=0; i < niveles.size(); i++){ // Ciclo sobre mis niveles
    valor = niveles[i].get_valor(); 
    digitos_resultado.push_back(valor);
  }
  return Entero(digitos_resultado);
}
Nivel Entero::nivel(int indice){
  return niveles[indice];
}
void Entero::agrega_a_nivel(int indice, int cantidad){
  niveles[indice].agrega(cantidad);
}
vector<Entero> Entero::divide(Entero divisor){
  vector<Entero> cociente_residuo;
  Entero residuo = copia();  // Inicializa al residuo como el divisor
  Entero cociente = cajas(); // Inicializa al cociente en cero
  vector<int> _cociente;
  int residuo_size = residuo.get_niveles().size();
  int divisor_size = divisor.get_niveles().size();
  int salto = residuo_size - divisor_size;
  int residuo_cabeza;
  int _signo;
  cout << residuo << " / " << divisor << endl;
  while(salto >= 0){
    residuo_cabeza = residuo.nivel(divisor_size + salto - 1).get_valor();
    _signo = signo(residuo_cabeza);
    while(residuo_cabeza != 0){
      cout << "residuo: " << residuo << endl;
      if (_signo > 0){
        residuo = residuo - divisor.hacia_arriba(salto);}
      else{
        residuo = residuo + divisor.hacia_arriba(salto);}
      cociente.agrega_a_nivel(salto,_signo);
      residuo_cabeza = residuo.nivel(divisor_size + salto - 1).get_valor();
      _signo = signo(residuo_cabeza);
    }
    salto -= 1;
  }
  cout << "residuo: " << residuo << endl;
  cout << "cociente: " << cociente << endl;
  cociente_residuo.push_back(cociente);
  cociente_residuo.push_back(residuo);
  return cociente_residuo;
}


int main(){
  Entero e1(52);
  Entero e2(73);
  Entero e3(3);
  // div 1
  Entero e4(276);
  Entero e5(12);
  // div 2
  Entero e6(2783);
  Entero e7(23);
  // div 3 BASE X
  vector<int> n1 = {2,-3,0,1};
  vector<int> d1 = {2,1};
  Entero e8(n1);
  Entero e9(d1);
  // div 4 BASE X
  vector<int> n2 = {-1,6,-4,7,-2,4};
  vector<int> d2 = {1,-1,1};
  Entero e10(n2);
  Entero e11(d2);
  cout << "SUMAS:" << endl;
  cout << e1 << " + " << e2 << " = "  << e1 + e2 << endl;
  cout << e1 << " + " << e3 << " = "  << e1 + e3 << endl;
  cout << "RESTAS:" << endl;
  cout << e1 << " - " << e2 << " = "  << e1 - e2 << endl;
  cout << e1 << " - " << e3 << " = "  << e1 - e3 << endl;
  cout << e3 << " - " << e1 << " = "  << e3 - e1 << endl;
  cout << "MULTIPLICACIONES:" << endl;
  cout << e1 << " * " << e2 << " = "  << e1 * e2 << endl;
  cout << e1 << " * " << e3 << " = "  << e1 * e3 << endl;
  cout << e3 << " * " << e1 << " = "  << e3 * e1 << endl;
  cout << "COPIAS:" << endl;
  cout << "e1 -> " << e1.copia() << endl;
  cout << "CAJAS:" << endl;
  cout << "e1 -> " << e1.cajas() << endl;
  cout << "e1 * e2 -> "  << (e1 * e2).cajas() << endl;
  cout << "SALTOS:" << endl;
  cout << "1 << e1 " << e1.hacia_arriba(1) << endl;
  cout << "3 << e3 " << e3.hacia_arriba(3) << endl;
  cout << "DIVISIONES:" << endl;
  vector<Entero> qr = e4/e5;
  qr = e6/e7;
  qr = e8/e9;
  qr = e10/e11;
  return 0;
}