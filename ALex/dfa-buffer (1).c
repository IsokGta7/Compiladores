#include <stdio.h>

#define SIZE 5
#define Ignorado -1
#define x 41
int esLetra(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

//Identificadores
int TablaTransicionIden[][5] = {
      //a-z  _  0-9  ''  =
/*0*/  {1,   2,  10,  10,  10},
/*1*/  {3,   4,  5,  6,  7},
/*2*/  {3,   4,  5,  6,  7},
/*3*/  {8,   9,  5,  6,  7},
/*4*/  {8,   9,  5,  6,  7},
/*5*/  {8,   9,  5,  6,  7},
/*6*/  {10,  10,  10,  6,  7},
/*7*/  {10,  10,  10,  10,  10},
/*8*/  {8,   9,  5,  6,  7},
/*9*/  {8,   9,  5,  6,  7},
/*10*/ {10,  10,  10,  10,  10}};

int EstadosAceptacionIden[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};

//Palabras
int TablaTransicionPr[][19] = {
      //i  f   s   m  p  o  r  t  F  a  l  e  T  u  d  c  w  h  n
/*0*/  {1, 2,  x,  x, x, x, 3, x, 4, x, x, x, 5, x, 6, 7, 8, x, x},
/*1*/  {x, 9, 10, 11, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*2*/  {x, x,  x,  x, x, x, 12, x, x, x, x, x, x, x, x, x, x, x, x},
/*3*/  {x, x,  x,  x, x, x, x, x, x, x, x, 13, x, x, x, x, x, x, x},
/*4*/  {x, x,  x,  x, x, x, x, x, x, 14, x, x, x, x, x, x, x, x, x},
/*5*/  {x, x,  x,  x, x, x, 15, x, x, x, x, x, x, x, x, x, x, x, x},
/*6*/  {x, x,  x,  x, x, x, x, x, x, x, x, 16, x, x, x, x, x, x, x},
/*7*/  {x, x,  x,  x, x, x, x, x, x, x, 17, x, x, x, x, x, x, x, x},
/*8*/  {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, 18, x},
/*9*/  {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*10*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*11*/ {x, x,  x,  x, 19, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*12*/ {x, x,  x,  x, x, 20, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*13*/ {x, x,  x,  x, x, x, x, 21, x, x, x, x, x, x, x, x, x, x, x},
/*14*/ {x, x,  x,  x, x, x, x, x, x, x, 22, x, x, x, x, x, x, x, x},
/*15*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, 23, x, x, x, x, x},
/*16*/ {x, 24,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*17*/ {x, x,  x,  x, x, x, x, x, x, 25, x, x, x, x, x, x, x, x, x},
/*18*/ {26, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*19*/ {x, x,  x,  x, x, 27, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*20*/ {x, x,  x,  28, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*21*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, 29, x, x, x, x, x},
/*22*/ {x, x,  30,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*23*/ {x, x,  x,  x, x, x, x, x, x, x, x, 31, x, x, x, x, x, x, x},
/*24*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*25*/ {x, x,  32,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*26*/ {x, x,  x,  x, x, x, x, x, x, x, 33, x, x, x, x, x, x, x, x},
/*27*/ {x, x,  x,  x, x, x, 34, x, x, x, x, x, x, x, x, x, x, x, x},
/*28*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*29*/ {x, x,  x,  x, x, x, 35, x, x, x, x, x, x, x, x, x, x, x, x},
/*30*/ {x, x,  x,  x, x, x, x, x, x, x, x, 36, x, x, x, x, x, x, x},
/*31*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*32*/ {x, x,  37,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*33*/ {x, x,  x,  x, x, x, x, x, x, x, x, 38, x, x, x, x, x, x, x},
/*34*/ {x, x,  x,  x, x, x, x, 39, x, x, x, x, x, x, x, x, x, x, x},
/*35*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, 40},
/*36*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*37*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*38*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*39*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*40*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x},
/*41*/ {x, x,  x,  x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}};

int EstadosAceptacionPr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0
};

int simulaDFA(int state,char input)
{ 
        int inputIndex;
        
        if(esLetra(input))
        {
            inputIndex = 0;

        }else if (input == '_')
        {
            inputIndex = 1;
        }else if (input>='0' && input<='9')
        {
            inputIndex = 2;
        }else if (input == ' '){
            inputIndex = 3;
        }else if (input == '='){
            inputIndex = 4;
        }else
        {   
            //printf("Caracter no reconocido: %c\n", input);
            return 10;
        }
        
       state = TablaTransicionIden[state][inputIndex];
    
    return state;
}
int simulaDFA_Pr(int state,char input)
{
    int inputIndex;
    
    switch(input) {
        case 'i':
            inputIndex = 0;
            break;
        case 'f':
            inputIndex = 1;
            break;
        case 's':
            inputIndex = 2;
            break;
        case 'm':
            inputIndex = 3;
            break;
        case 'p':
            inputIndex = 4;
            break;
        case 'o':
            inputIndex = 5;
            break;
        case 'r':
            inputIndex = 6;
            break;
        case 't':
            inputIndex = 7;
            break;
        case 'F':
            inputIndex = 8;
            break;
        case 'a':
            inputIndex = 9;
            break;
        case 'l':
            inputIndex = 10;
            break;
        case 'e':
            inputIndex = 11;
            break;
        case 'T':
            inputIndex = 12;
            break;
        case 'u':
            inputIndex = 13;
            break;
        case 'd':
            inputIndex = 14;
            break;
        case 'c':
            inputIndex = 15;
            break;
        case 'w':
            inputIndex = 16;
            break;
        case 'h':
            inputIndex = 17;
            break;
        case 'n':
            inputIndex = 18;
            break;
        default:
            //printf("Caracter no reconocido: %c\n", input);
            return 41;
    }
    
    state = TablaTransicionPr[state][inputIndex];
    
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
        printf("Buffer vacío. No se puede desencolar.\n");
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
            statePr = simulaDFA_Pr(statePr, resultado);
        }

        if (ch == '\n')
        {
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

//{-|+|e}{1-9}^+{0|2|4|6|8} expresion regular para pares
//{0|1}*{00}{0|1}* er para cadenas con alfabeto {0,1} que tengan la cadena 00
//(0|1){4} para todas las cadenas de 4 digitos alfabeto {0,1}
//(a(a|b)*a)|a todas las que empiezan y terminan con a alf{a,b}
//(aa|aba|b)*a(aa|b|aba)* todas las que tengan impar de a
// b*(a?b)*
//
//
//  (a-z|A-Z)|_)+ (0-9|a-z|A-Z|_)* ( )*=
//  !(if|while|for|...)( )*=

/*
    /+
    /-
    /*
    //
    /=
    /(
    /)
    /[
    /]
    /<
    />
    /,
    /:
    /!=
    /==

*/