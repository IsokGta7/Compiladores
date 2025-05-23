
#include <iostream>
#include <string>
#include <cctype>
#define SIZE 5
#define Ignorado -1
#define x 41


//CREO QUE ESTO NO SE NECESITA BORRAR
int esLetra(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


const int NumEstados =136; // N�mero total de estados en el DFA
const int NumSimbolos = 29; // N�mero total de s�mbolos en el alfabeto (0 y 1)

const char FinDeLexema = '\0'; // Car�cter que indica el fin de la cadena


int TablaTransicion[NumEstados][NumSimbolos] = {
//{   0, 1,  2,  3,  4,   5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}
    {133,  1, 10, 15, 19, 23, 38, 43, 47, 58, 68, 74, 80, 89, 91, 95,107,115,125,128,134,134,134,134,134,134,133,135,134},                  //0
    {134,134,134,134,134,134,134,134,134,3,134,134,9,134,134,134,134,134,134,134,2,4,134,134,134,134,134,134,134},          //1
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},  //2
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},  //3
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,5,134,134,134,134,134,134,134,134,134,134,134,134,134,134},     //4
    {134,134,134,134,134,134,134,134,134,134,134,134,134,6,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},    //5
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,7,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,8,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,11,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,12,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,13,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,14,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,16,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,17,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,18,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,20,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,21,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,22,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,24,134,134,134,34,134,134,134,26,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,25,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,31,27,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,28,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,29,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,30,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,32,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,33,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,35,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,36,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,37,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,39,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,40,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,41,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,42,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,44,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,45,134,46,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,48,134,134,134,134,134,134,134,134,134,134,134,134,53,134,134,134,134},
    {134,49,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,51,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,50,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,52,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,54,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,55,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,56,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,57,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,62,134,134,134,134,134,134,134,134,134,134,134,59,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,60,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,61,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,63,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,64,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,65,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,66,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,67,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,69,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,70,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,71,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,72,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,73,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,75,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,76,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,77,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,78,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,79,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,81,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,82,134,134,134,134,134,88,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,83,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,84,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,85,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,86,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,87,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,90,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,92,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,93,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,94,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,96,134,100,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,97,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,98,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,99,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,101,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,102,134,134,134,134,134,134,134,134,134,134},
    {134,103,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,104,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,105,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,106,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,112,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,108,134,134,134},
    {134,109,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,110,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,111,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,113,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,114,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,121,134,134,116,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,117,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,118,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,119,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,120,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,122,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,123,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,124,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,126,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,127,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,129,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,130,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,131,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,132,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134},
    {135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135}
  };

bool EstadosAceptacion[NumEstados] = {0,0,1,1,0,0,0,0,1,1,  0,0,0,0,1,0,0,0,1,0,  0,0,1,0,0,1,1,0,0,0,  1,0,0,1,0,0,0,1,
0,0,  0,0,1,0,0,1,1,0,0,0,  1,0,1,0,0,0,0,1,0,0,  1,1,0,0,0,0,0,1,0,0,  0,0,0,1,0,0,0,0,0,1,  0,0,0,0,0,0,0,1,1,0,  1,0,0,0,1,
0,0,0,0,1,  0,0,0,0,0,0,1,0,0,0,  0,1,0,0,1,0,0,0,0,0,  1,0,0,0,1,0,0,1,0,0,  0,0,1,0,1,0};

int simulaDFA(int state,char s) {


        //std::cout<<"PRIMER STATE: "<<state<<std::endl;
      int sIndex = (isalpha(s)) ? 0 : (isdigit(s))? 27:(s == '_')? 26: -1;//int sIndex = (isalpha(s)) ? 0 : (isdigit(s))? 2:(s == '-')? 1;

    switch(s) {
        case 'i':
            sIndex = 1;
            break;
        case 'F':
            sIndex = 2;
            break;
        case 'T':
            sIndex = 3;
            break;
        case 'N':
            sIndex = 4;
            break;
        case 'a':
            sIndex = 5;
            break;
        case 'b':
            sIndex = 6;
            break;
        case 'd':
            sIndex = 7;
            break;
        case 'e':
            sIndex = 8;
            break;
        case 'f':
            sIndex = 9;
            break;
        case 'g':
            sIndex = 10;
            break;
        case 'l':
            sIndex = 11;
            break;
        case 'n':
            sIndex = 12;
            break;
        case 'o':
            sIndex = 13;
            break;
        case 'p':
            sIndex = 14;
            break;
        case 'c':
            sIndex = 15;
            break;
        case 'w':
            sIndex = 16;
            break;
        case 'r':
            sIndex = 17;
            break;
        case 't':
            sIndex = 18;
            break;
        case 'y':
            sIndex = 19;
            break;
         case 's':
            sIndex = 20;
            break;
        case 'm':
            sIndex = 21;
            break;
        case 'u':
            sIndex = 22;
            break;
        case 'k':
            sIndex = 23;
            break;
        case 'x':
            sIndex = 24;
            break;
         case 'h':
            sIndex = 25;
            break;

    }
        if(sIndex==-1){
            state=34;
            sIndex=0;
        }

        state = TablaTransicion[state][sIndex];



        //std::cout<<"QUE ESTADO"<<state<<std::endl;


    return state;
}


typedef struct
{
    char buffer[SIZE];
    int head;
    int tail;
} BufferCircular;

int comentario = 0;
int bloquecomen = 0;
int comillas = 0;
int espacio = 0;
void initBuffer(BufferCircular *cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
}

int BufferVacio(const BufferCircular *cbuf)
{
    return (cbuf->head == cbuf->tail);
}

int BufferLleno(const BufferCircular *cbuf)
{
    return ((cbuf->tail + 1) % SIZE == cbuf->head);
}

int enqueue(BufferCircular *cbuf, int value)
{

    if (BufferLleno(cbuf))
    {
        std::cout<<"Buffer lleno. No se puede encolar.\n";
    }
    if (value == '#')
    {
        comentario = 1;
    }

    if (value == '"')
    {
        comillas++;
        if (comillas == 3)
        {
            bloquecomen = !bloquecomen;
            comillas = 0;
            return Ignorado;
        }
        return Ignorado;
    }
    else if (comillas > 0)
    {
        comillas = 0;
    }

    if (bloquecomen == 1)
    {
        return Ignorado;
    }

    if (comentario == 1)
    {
        if (value == '\n')
        {
            comentario = 0;
        }
        return Ignorado;
    }


    else if (value == '\n')
    {
        return Ignorado;
    }

    if (value == ' ')
    {
        espacio++;
    }
    else if (espacio > 0)
    {
        espacio = 0;
    }
    if (espacio > 1)
    {
        return Ignorado;
    }
    else
    {
        cbuf->buffer[cbuf->tail] = value;
        cbuf->tail = (cbuf->tail + 1) % SIZE;
        return value;
    }

}

int dequeue(BufferCircular *cbuf)
{
    int value = 0;

    if (!BufferVacio(cbuf))
    {
        value = cbuf->buffer[cbuf->head];
        cbuf->head = (cbuf->head + 1) % SIZE;
    }
    else
    {
        std::cout<<"Buffer vac�o. No se puede desencolar.\n";
    }

    return value;
}

int main()
{
    BufferCircular cbuf;
    initBuffer(&cbuf);

    FILE *file = fopen("archivo.txt", "r");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char ch;
    int state= 0;

    while ((ch = fgetc(file)) != EOF)
    {
        if (BufferLleno(&cbuf))
        {
            while (!BufferVacio(&cbuf))
            {
                dequeue(&cbuf);
            }
        }
        int resultado = enqueue(&cbuf, ch);

        if (resultado != Ignorado)
        {
            printf("Encolando: %c\n", resultado);
            state= simulaDFA(state, resultado);
        }


    }
    // para la situacion en cuando quede en un estado intermedio de reconocer una palabra reservada se vaya a identificador

    if((!EstadosAceptacion[state] && state!=135)){ //poner los estados
        state=42;
        }

    while (!BufferVacio(&cbuf))
    {
        dequeue(&cbuf);
    }
    //std::cout<<"EL ESTADO ES EL "<<state;

    if (EstadosAceptacion[state] == 1){
            std::cout<<"Identificador\n";
        }else{
            std::cout<<"Rechazado\n";
        }

    fclose(file);
    return 0;
}



/*
#include <stdio.h>

#define SIZE 5
#define Ignorado -1
#define x 41
int esLetra(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


//Palabras
int TablaTransicionPr[44][23] = {
 //{ 1,      2, 3, 4, 5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}
//{A-Z-lis, i, F, T, d,  f,  c,  w,  r,  a,  s,  e,  u,  o,  t,  p,  h,  l,  n,  m,  -, 0-9, A-Z}
    {41, 1,  9, 14, 18, 21, 25, 30, 35, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 41, 43, 42},// estado 0
    {42, 42, 42, 42, 42,  3, 42, 42, 42, 42,  2, 42, 42, 42, 42, 42, 42, 42, 42,  4, 42, 42, 42},//1
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 2 is
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 3 if
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,  5, 42, 42, 42, 42, 42, 42, 42},// 4 im
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,  6, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 5 imp
    {42, 42, 42, 42, 42, 42, 42, 42,  7, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 6 impo
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,  8, 42, 42, 42, 42, 42, 42, 42, 42},// 7 impor
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 8 import acept
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 10, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 9 F
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 11, 42, 42, 42, 42, 42},// estado 10 Fa
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 12, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},//11 Fal
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 13, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 12 Fals
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 13 False acept
    {42, 42, 42, 42, 42, 42, 42, 42, 15, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 14 T
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 16, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 15 Tr
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 17, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 16 Tru
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 17 True acept
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 19, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 18 d
//{A-Z-lis, i, F, T, d,  f,  c,  w,  r,  a,  s,  e,  u,  o,  t,  p,  h,  l,  n,  m,  -, 0-9, A-Z}
    {42, 42, 42, 42, 42, 20, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 19 de
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// estado 20 def
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 22, 42, 42, 42, 42, 42, 42, 42, 42, 42},//21 f
    {42, 42, 42, 42, 42, 42, 42, 42, 23, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 22 fo
    {33, 33, 33, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 24, 42, 42, 42},// 23 for acept
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 24 form acepta
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 26, 42, 42, 42, 42, 42},// 25 c
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 27, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 26 cl
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 28, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 27 cla
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 29, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 28 clas
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 29 class acepta
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 31, 42, 42, 42, 42, 42, 42},// estado 30 w
    {42, 32, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 31 wh
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 33, 42, 42, 42, 42, 42},// 32 whi
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 34, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 33 whil
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 34 while acepta
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 36, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 35 r
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 37, 42, 42, 42, 42, 42, 42, 42, 42},// 36 re
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 38, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 37 ret
    {42, 42, 42, 42, 42, 42, 42, 42, 39, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 38 retu
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 40, 42, 42, 42, 42},// 39 retur
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 40 return aceptaa
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 41
    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42},// 42
    {43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43},// 43 basura


bool EstadosAceptacion[44] = {0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0};

int simulaDFA(int state,char input)
{
       int state = 0;
    //std::string es;
   // for (char lookahead = 0; input[lookahead] != FinDeLexema && !EstadosAceptacion[state]; lookahead++) {
        std::cout<<"PRIMER STATE: "<<state<<std::endl;

       // char s = input[lookahead];

        int sIndex = (isalpha(input)) ? 0 : (isdigit(input))? 21:(input == '_')? 20: -1;

    switch(s) {
        case 'i':
            sIndex = 1;
            break;
        case 'F':
            sIndex = 2;
            break;
        case 'T':
            sIndex = 3;
            break;
        case 'd':
            sIndex = 4;
            break;
        case 'f':
            sIndex = 5;
            break;
        case 'c':
            sIndex = 6;
            break;
        case 'w':
            sIndex = 7;
            break;
        case 'r':
            sIndex = 8;
            break;
        case 'a':
            sIndex = 9;
            break;
        case 's':
            sIndex = 10;
            break;
        case 'e':
            sIndex = 11;
            break;
        case 'u':
            sIndex = 12;
            break;
        case 'o':
            sIndex = 13;
            break;
        case 't':
            sIndex = 14;
            break;
        case 'p':
            sIndex = 15;
            break;
        case 'h':
            sIndex = 16;
            break;
        case 'l':
            sIndex = 17;
            break;
        case 'n':
            sIndex = 18;
            break;
        case 'm':
            sIndex = 19;
            break;
    }

        if(sIndex==-1){
            state=34;
            sIndex=0;
        }




        state = TablaTransicion[state][sIndex];
        //std::cout<<state<<std::endl;

        //si no se a terminado la cadena y ya esta en estado de aceptacion... que siga leyendo




    //}

    return EstadosAceptacion[state];


}

typedef struct
{
    char buffer[SIZE];
    int head;
    int tail;
} BufferCircular;

int comentario = 0;
int bloquecomen = 0;
int comillas = 0;
int espacio = 0;
void initBuffer(BufferCircular *cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
}

int BufferVacio(const BufferCircular *cbuf)
{
    return (cbuf->head == cbuf->tail);
}

int BufferLleno(const BufferCircular *cbuf)
{
    return ((cbuf->tail + 1) % SIZE == cbuf->head);
}

int enqueue(BufferCircular *cbuf, int value)
{

    if (BufferLleno(cbuf))
    {
        printf("Buffer lleno. No se puede encolar.\n");
    }
    if (value == '#')
    {
        comentario = 1;
        // return Ignorado;
    }

    if (value == '"')
    {
        comillas++;
        if (comillas == 3)
        {
            bloquecomen = !bloquecomen;
            comillas = 0;
            return Ignorado;
        }
        return Ignorado;
    }
    else if (comillas > 0)
    {
        comillas = 0;
    }

    if (bloquecomen == 1)
    {
        return Ignorado;
    }

    if (comentario == 1)
    {
        if (value == '\n')
        {
            comentario = 0;
        }
        return Ignorado;
    }
    // if (bloquecomen==1)
    // {
    //     if (value=="'''"||value=='"""')
    //     {
    //         bloquecomen=0;
    //     }
    //     return Ignorado;
    // }

    else if (value == '\n')
    {
        return Ignorado;
    }

    if (value == ' ')
    {
        espacio++;
    }
    else if (espacio > 0)
    {
        espacio = 0;
    }
    if (espacio > 1)
    {
        return Ignorado;
    }
    else
    {
        // printf("valor ignorado\n");
        cbuf->buffer[cbuf->tail] = value;
        cbuf->tail = (cbuf->tail + 1) % SIZE;
        return value;
    }

}

int dequeue(BufferCircular *cbuf)
{
    int value = 0;

    if (!BufferVacio(cbuf))
    {
        value = cbuf->buffer[cbuf->head];
        cbuf->head = (cbuf->head + 1) % SIZE;
    }
    else
    {
        printf("Buffer vac�o. No se puede desencolar.\n");
    }

    return value;
}

int main()
{
    BufferCircular cbuf;
    initBuffer(&cbuf);

    FILE *file = fopen("archivo.txt", "r");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char ch;
    int stateIden = 0;
    int statePr = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        if (BufferLleno(&cbuf))
        {
            while (!BufferVacio(&cbuf))
            {
                //printf("Desencolando: %c\n", dequeue(&cbuf));
                dequeue(&cbuf);
            }
        }
        int resultado = enqueue(&cbuf, ch);

        if (resultado != Ignorado)
        {
            //printf("%c\n", resultado);
            printf("Encolando: %c\n", resultado);
            stateIden = simulaDFA(stateIden, resultado);
            //statePr = simulaDFA_Pr(statePr, resultado);
        }

        if (ch == '\n')
        {
            if (EstadosAceptacion[stateIden] == 1)
            {
                printf("Identificador\n");
            }else if (EstadosAceptacionPr[statePr] == 1)
            {
                printf("Palabra reservada\n");
            }else
            {
                printf("Rechazado\n");
            }

            stateIden = 0;
            statePr = 0;
        }

    }

    while (!BufferVacio(&cbuf))
    {
        //printf("Desencolando: %c\n", dequeue(&cbuf));
        dequeue(&cbuf);
    }
    if (EstadosAceptacionIden[stateIden] == 1)
            {
                printf("Identificador\n");
            }else if (EstadosAceptacionPr[statePr] == 1)
            {
                printf("Palabra reservada\n");
            }else
            {
                printf("Rechazado\n");
            }

    fclose(file);
    return 0;
}
*/
