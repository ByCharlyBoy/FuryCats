#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

#pragma region AllCaps

//Crear el programa
#define PROGRAMA int main() {
#define FIN_DEL_PROGRAMA return 0; }
#define FORZAR_TERMINACION_DEL_PROGRAMA exit(-1);

//Crear variables
#define CREAR_COLECCION(tipo, nombre) vector<tipo> nombre;
#define CREAR_VARIABLE(tipo, nombre) tipo nombre;
#define APUNTADOR_DE(tipoDeVariable) tipoDeVariable*
#define REFERENCIA &
#define POR_REFERENCIA REFERENCIA
#define ALOCAR_MEMORIA(variable, tipo, ...) variable = new tipo(__VA_ARGS__);
#define DESTRUIR_VARIABLE(variable) delete variable;

//Tipos de variables
#define COLECCION(tipo) vector<tipo> 
#define ENTERO int
#define DECIMAL float
#define BOOLEANO bool
#define LETRA char
#define ORACION string

//Operaciones con arreglos
#define ELEMENTO_DE_LA_COLECCION(indice) [indice]
#define AGREGAR_A_LA_COLECCION(arreglo, variable) arreglo.push_back(variable);

//Comparaciones entre variables
#define ES_IGUAL_A ==
#define SEA_IGUAL_QUE ES_IGUAL_A
#define ES_IGUAL_QUE ES_IGUAL_A
#define NO_ES_IGUAL_A !=
#define NO_ES_IGUAL_QUE NO_ES_IGUAL_A
#define NO_SEA_IGUAL_QUE NO_ES_IGUAL_A
#define ES_MENOR_O_IGUAL_A <=
#define ES_MENOR_O_IGUAL_QUE ES_MENOR_O_IGUAL_A
#define SEA_MENOR_O_IGUAL_QUE ES_MENOR_O_IGUAL_A
#define ES_MAYOR_O_IGUAL_A >=
#define ES_MAYOR_O_IGUAL_QUE ES_MAYOR_O_IGUAL_A
#define SEA_MAYOR_O_IGUAL_QUE ES_MAYOR_O_IGUAL_A
#define ES_MENOR_A <
#define ES_MENOR_QUE ES_MENOR_A
#define SEA_MENOR_QUE ES_MENOR_A
#define ES_MAYOR_A >
#define ES_MAYOR_QUE ES_MAYOR_A
#define SEA_MAYOR_QUE ES_MAYOR_A

//Constantes
#define NULO nullptr
#define VERDADERO true
#define FALSO false

//Operadores logicos
#define Y &&
#define O ||
#define NO !

//Operadores binarios
#define Y_BINARIO &
#define O_BINARIO |
#define MOVER_A_LA_IZQUIERDA << 
#define MOVER_A_LA_DERECHA >> 

//Iteraciones
#define PARA for(
#define CADA(x) auto &x :
#define MIENTRAS while(
#define HAZ ){
#define FIN_DE_LA_ITERACION }
#define TERMINAR_LA_ITERERACION break;

//Comparaciones
#define SI if(
#define SI_NO else if(
#define ENTONCES ){
#define FIN_DE_LA_COMPROBACION }
#define TERMINAR_LA_COMPROBACION FIN_DE_LA_COMPROBACION

//Operaciones con variables
#define ES = 
#define MAS +
#define MENOS -
#define POR *
#define ENTRE /
#define INCREMENTAR(x) ++x;
#define DISMINUIR(x) --;
#define RESIDUO_DE %
#define ASIGNAR_A(asignada, asignacion) asignada = asignacion;
#define DATOS_DE_APUNTADOR(variable) *variable
#define ACCESO_A_MIEMBROS_DE_APUNTADOR ->
#define ACCESO_A_MIEMBROS_DE_DATOS .
#define CON_EL_VALOR_DE(val) val
#define EL_VALOR_DE(val) val

//Entrada y salida de datos
#define IMPRIMIR cout << 
#define RECOGER_ENTRADA(dondeSeVaAGuardar) cin >> dondeSeVaAGuardar;
#define IMPRIMIR_COLECCION(arreglo) PARA CADA(i) EN(arreglo) HAZ IMPRIMIR i FIN_DE_LINEA FIN
#define FIN_DE_LA_LINEA << endl;
#define TERMINAR_LA_LINEA FIN_DE_LA_LINEA

//Funciones
#define FUNCION(regreso, nombre, recibe) regreso nombre recibe {
#define DECLARAR_FUNCION(nombre, regreso, recibe) regreso nombre recibe;
#define FUNCION_DE_CLASE(nombre, regreso, recibe, clase) regreso clase::nombre recibe {
#define QUE_REGRESA_UN(tipoDeVariable) tipoDeVariable
#define NOMBRE_DE_FUNCION(nombre) nombre
#define Y_RECIBE(...) (__VA_ARGS__)
#define RECIBE(...) (__VA_ARGS__)
#define REGRESAR_VALOR(x) return x;
#define LLAMAR_FUNCION(nombre, ...) nombre(__VA_ARGS__);
#define FIN_DE_LA_FUNCION }
#define LLAMADO(nombre) nombre
#define LLAMADA(nombre) nombre

//Estructuras
#define ESTRUCTURA(nombre) typedef struct nombre{
#define FIN_DE_LA_ESTRUCTURA(nombre) }nombre;
#define LLENAR_ESTRUCTURA(variable, ...) variable = { __VA_ARGS__ };

//Clases
#define HEREDA_DE : 
#define CLASE_PUBLICA(nombre) public nombre
#define CLASE_PRIVADA(nombre) private nombre
#define CLASE_PROTEGIDA(nombre) protected nombre
#define CLASE(nombre, ...) class nombre __VA_ARGS__ {
#define CONSTRUCTOR(clase, ...) clase (__VA_ARGS__){
#define FIN_DEL_CONSTRUCTOR }
#define DECLARAR_CONSTRUCTOR(clase, ...) clase (__VA_ARGS__);
#define IMPLEMENTAR_CONSTRUCTOR(clase, ...) clase::clase (__VA_ARGS__) {
#define DESTRUCTOR(clase, ...) ~clase (__VA_ARGS__){
#define FIN_DEL_DESTRUCTOR }
#define DECLARAR_DESTRUCTOR(clase, ...) ~clase (__VA_ARGS__);
#define IMPLEMENTAR_DESTRUCTOR(clase, ...) clase::~clase (__VA_ARGS__) {
#define ACCESO_PUBLICO public:
#define ACCESO_PRIVADO private:
#define ACCESO_PROTEGIDO protected:
#define FIN_DE_LA_CLASE };
#define Y_LE_PERTENECE_A_LA_CLASE(nombre) nombre

//Pausar el programa
#define PAUSAR_EL_PROGRAMA  cin.ignore( numeric_limits<streamsize>::max(), '\n' ) ;

//Generación de numeros aleatorios
#define NUMERO_ALEATORIO_EN_RANGO(min, max) ((rand() % (max - min)) + min)
#define NUMERO_ALEATORIO rand()

//Enumeraciones
#define ENUMERACION(nombre) typedef enum nombre {
#define FIN_DE_LA_ENUMERACION(nombre) }nombre;

//Expresiones vacias
#define LUEGO 
#define LUGARES 
#define DESPUES
#define UN
#define CON_TIPO
#define QUE
#define LA
#define EL
#define EN 
#define DE
#define COMO_UN

#define ADEMAS_DE ,
#pragma endregion

#pragma region NoCaps
//crear el programa
#define programa int main() {
#define fin_del_programa return 0; }
#define forzar_terminacion_del_programa exit(-1);

//crear variables
#define crear_coleccion(tipo, nombre) vector<tipo> nombre;
#define crear_variable(tipo, nombre) tipo nombre;
#define apuntador_de(tipodevariable) tipodevariable*
#define referencia &
#define por_referencia referencia
#define alocar_memoria(variable, tipo, ...) variable = new tipo(__VA_ARGS__);
#define destruir_variable(variable) delete variable;

//tipos de variables
#define coleccion(tipo) vector<tipo> 
#define entero int
#define decimal float
#define booleano bool
#define letra char
#define oracion string

//operaciones con arreglos
#define elemento_de_la_coleccion(indice) [indice]
#define agregar_a_la_coleccion(arreglo, variable) arreglo.push_back(variable);

//comparaciones entre variables
#define es_igual_a ==
#define sea_igual_que es_igual_a
#define es_igual_que es_igual_a
#define no_es_igual_a !=
#define no_es_igual_que no_es_igual_a
#define no_sea_igual_que no_es_igual_a
#define es_menor_o_igual_a <=
#define es_menor_o_igual_que es_menor_o_igual_a
#define sea_menor_o_igual_que es_menor_o_igual_a
#define es_mayor_o_igual_a >=
#define es_mayor_o_igual_que es_mayor_o_igual_a
#define sea_mayor_o_igual_que es_mayor_o_igual_a
#define es_menor_a <
#define es_menor_que es_menor_a
#define sea_menor_que es_menor_a
#define es_mayor_a >
#define es_mayor_que es_mayor_a
#define sea_mayor_que es_mayor_a

//constantes
#define nulo nullptr
#define verdadero true
#define falso false

//operadores logicos
#define y &&
#define o ||
#define no !

//operadores binarios
#define y_binario &
#define o_binario |
#define mover_a_la_izquierda << 
#define mover_a_la_derecha >> 

//iteraciones
#define para for(
#define cada(x) auto &x :
#define mientras while(
#define haz ){
#define fin_de_la_iteracion }
#define terminar_la_itereracion break;

//comparaciones
#define si if(
#define si_no else if(
#define entonces ){
#define fin_de_la_comprobacion }
#define terminar_la_comprobacion fin_de_la_comprobacion

//operaciones con variables
#define es = 
#define mas +
#define menos -
#define por *
#define entre /
#define incrementar(x) ++x;
#define disminuir(x) --;
#define residuo_de %
#define asignar_a(asignada, asignacion) asignada = asignacion;
#define datos_de_apuntador(variable) *variable
#define acceso_a_miembros_de_apuntador ->
#define acceso_a_miembros_de_datos .
#define con_el_valor_de(val) val
#define el_valor_de(val) val

//entrada y salida de datos
#define imprimir cout << 
#define recoger_entrada(dondesevaaguardar) cin >> dondesevaaguardar;
#define imprimir_coleccion(arreglo) para cada(i) en(arreglo) haz imprimir i fin_de_linea fin
#define fin_de_la_linea << endl;
#define terminar_la_linea fin_de_la_linea

//funciones
#define funcion(regreso, nombre, recibe) regreso nombre recibe {
#define declarar_funcion(nombre, regreso, recibe) regreso nombre recibe;
#define funcion_de_clase(nombre, regreso, recibe, clase) regreso clase::nombre recibe {
#define que_regresa_un(tipodevariable) tipodevariable
#define nombre_de_funcion(nombre) nombre
#define y_recibe(...) (__VA_ARGS__)
#define recibe(...) (__VA_ARGS__)
#define regresar_valor(x) return x;
#define llamar_funcion(nombre, ...) nombre(__VA_ARGS__);
#define fin_de_la_funcion }
#define llamado(nombre) nombre
#define llamada(nombre) nombre

//estructuras
#define estructura(nombre) typedef struct nombre{
#define fin_de_la_estructura(nombre) }nombre;
#define llenar_estructura(variable, ...) variable = { __VA_ARGS__ };

//clases
#define hereda_de : 
#define clase_publica(nombre) public nombre
#define clase_privada(nombre) private nombre
#define clase_protegida(nombre) protected nombre
#define clase(nombre, ...) class nombre __VA_ARGS__ {
#define constructor(clase, ...) clase (__VA_ARGS__){
#define fin_del_constructor }
#define declarar_constructor(clase, ...) clase (__VA_ARGS__);
#define implementar_constructor(clase, ...) clase::clase (__VA_ARGS__) {
#define destructor(clase, ...) ~clase (__VA_ARGS__){
#define fin_del_destructor }
#define declarar_destructor(clase, ...) ~clase (__VA_ARGS__);
#define implementar_destructor(clase, ...) clase::~clase (__VA_ARGS__) {
#define acceso_publico public:
#define acceso_privado private:
#define acceso_protegido protected:
#define fin_de_la_clase };
#define y_le_pertenece_a_la_clase(nombre) nombre

//pausar el programa
#define pausar_el_programa  cin.ignore( numeric_limits<streamsize>::max(), '\n' ) ;

//generación de numeros aleatorios
#define numero_aleatorio_en_rango(min, max) ((rand() % (max - min)) + min)
#define numero_aleatorio rand()

//enumeraciones
#define enumeracion(nombre) typedef enum nombre {
#define fin_de_la_enumeracion(nombre) }nombre;

//expresiones vacias
#define luego 
#define lugares 
#define despues
#define un
#define con_tipo
#define que
#define la
#define el
#define en 
#define de
#define como_un

#define ademas_de ,
#pragma endregion

#pragma region Camel Caps
//crear El Programa
#define Programa int main() {
#define Fin_del_programa return 0; }
#define Forzar_terminacion_del_programa exit(-1);

//crear Variables
#define Crear_coleccion(Tipo, Nombre) vector<Tipo> Nombre;
#define Crear_variable(Tipo, Nombre) Tipo Nombre;
#define Apuntador_de(Tipodevariable) Tipodevariable*
#define Referencia &
#define Por_referencia Referencia
#define Alocar_memoria(Variable, Tipo, ...) Variable = new Tipo(__VA_ARGS__);
#define Destruir_variable(Variable) delete Variable;

//tipos De Variables
#define Coleccion(Tipo) vector<tipo> 
#define Entero int
#define Decimal float
#define Booleano bool
#define Letra char
#define Oracion string

//operaciones Con Arreglos
#define Elemento_de_la_coleccion(Indice) [Indice]
#define Agregar_a_la_coleccion(Arreglo, Variable) Arreglo.push_back(Variable);

//comparaciones Entre Variables
#define Es_igual_a ==
#define Sea_igual_que Es_igual_a
#define Es_igual_que Es_igual_a
#define No_es_igual_a !=
#define No_es_igual_que No_es_igual_a
#define No_sea_igual_que No_es_igual_a
#define Es_menor_o_igual_a <=
#define Es_menor_o_igual_que Es_menor_o_igual_a
#define Sea_menor_o_igual_que Es_menor_o_igual_a
#define Es_mayor_o_igual_a >=
#define Es_mayor_o_igual_que Es_mayor_o_igual_a
#define Sea_mayor_o_igual_que Es_mayor_o_igual_a
#define Es_menor_a <
#define Es_menor_que Es_menor_a
#define Sea_menor_que Es_menor_a
#define Es_mayor_a >
#define Es_mayor_que Es_mayor_a
#define Sea_mayor_que Es_mayor_a

//constantes
#define Nulo nullptr
#define Verdadero true
#define Falso false

//operadores Logicos
#define Y &&
#define O ||
#define No !

//operadores Binarios
#define Y_binario &
#define O_binario |
#define Mover_a_la_izquierda << 
#define Mover_a_la_derecha >> 

//iteraciones
#define Para for(
#define Cada(X) auto &x :
#define Mientras while(
#define Haz ){
#define Fin_de_la_iteracion }
#define Terminar_la_itereracion break;

//comparaciones
#define Si if(
#define Si_no else if(
#define Entonces ){
#define Fin_de_la_comprobacion }
#define Terminar_la_comprobacion Fin_de_la_comprobacion

//operaciones Con Variables
#define Es = 
#define Mas +
#define Menos -
#define Por *
#define Entre /
#define Incrementar(X) ++X;
#define Disminuir(X) --X;
#define Residuo_de %
#define Asignar_a(Asignada, Asignacion) Asignada = Asignacion;
#define Datos_de_apuntador(Variable) *Variable
#define Acceso_a_miembros_de_apuntador ->
#define Acceso_a_miembros_de_datos .
#define Con_el_valor_de(Val) Val
#define El_valor_de(Val) Val

//entrada Y Salida De Datos
#define Imprimir cout << 
#define Recoger_entrada(Dondesevaaguardar) cin >> Dondesevaaguardar;
#define Imprimir_coleccion(Arreglo) Para Cada(I) en(Arreglo) Haz Imprimir I luego TERMINAR_LA_LINEA Fin
#define Fin_de_la_linea << endl;
#define Terminar_la_linea Fin_de_la_linea

//funciones
#define Funcion(Regreso, Nombre, Recibe) Regreso Nombre Recibe {
#define Declarar_funcion(Nombre, Regreso, Recibe) Regreso Nombre Recibe;
#define Funcion_de_clase(Nombre, Regreso, Recibe, Clase) Regreso Clase::Nombre Recibe {
#define Que_regresa_un(Tipodevariable) Tipodevariable
#define Nombre_de_funcion(Nombre) Nombre
#define Y_recibe(...) (__VA_ARGS__)
#define Recibe(...) (__VA_ARGS__)
#define Regresar_valor(X) return X;
#define Llamar_funcion(Nombre, ...) Nombre(__VA_ARGS__);
#define Fin_de_la_funcion }
#define Llamado(Nombre) Nombre
#define Llamada(Nombre) Nombre

//estructuras
#define Estructura(Nombre) typedef struct Nombre{
#define Fin_de_la_estructura(Nombre) }Nombre;
#define Llenar_estructura(Variable, ...) Variable = { __VA_ARGS__ };

//clases
#define Hereda_de : 
#define Clase_publica(Nombre) public Nombre
#define Clase_privada(Nombre) private Nombre
#define Clase_protegida(Nombre) protected Nombre
#define Clase(nombre, ...) class nombre __VA_ARGS__ {
#define Constructor(nombre, ...) nombre (__VA_ARGS__){
#define Fin_del_constructor }
#define Declarar_constructor(nombre, ...) nombre (__VA_ARGS__);
#define Implementar_constructor(nombre, ...) nombre::nombre (__VA_ARGS__) {
#define Destructor(nombre, ...) ~nombre (__VA_ARGS__){
#define Fin_del_destructor }
#define Declarar_destructor(nombre, ...) ~nombre (__VA_ARGS__);
#define Implementar_destructor(nombre, ...) nombre::~nombre (__VA_ARGS__) {
#define Acceso_publico public:
#define Acceso_privado private:
#define Acceso_protegido protected:
#define Fin_de_la_clase };
#define Y_le_pertenece_a_la_clase(Nombre) Nombre

//pausar El Programa
#define Pausar_el_programa  cin.ignore( numeric_limits<streamsize>::max(), '\n' ) ;

//generación De Numeros Aleatorios
#define Numero_aleatorio_en_rango(Min, Max) ((rand() % (Max - Min)) + Min)
#define Numero_aleatorio rand()

//enumeraciones
#define Enumeracion(Nombre) typedef enum Nombre {
#define Fin_de_la_enumeracion(Nombre) }Nombre;

//expresiones Vacias
#define Luego 
#define Lugares 
#define Despues
#define Un
#define Con_tipo
#define Que
#define La
#define El
#define En 
#define De
#define Como_un

#define Ademas_de ,
#pragma endregion
