#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stdexcept>

// Definición de las estructuras necesarias
struct NodoArbol {
    std::string simbolo;
    std::vector<NodoArbol*> hijos;
};

class TokenStream {
public:
    TokenStream(const std::vector<std::string>& tokens) : tokens(tokens), index(0) {}

    bool has_more_tokens() const {
        return index < tokens.size();
    }

    std::string peek() const {
        if (has_more_tokens()) {
            return tokens[index];
        }
        return "";
    }

    void next() {
        if (has_more_tokens()) {
            ++index;
        }
    }

private:
    std::vector<std::string> tokens;
    size_t index;
};

// Declaración de las funciones
void parse_INSTRUCCION(TokenStream& token_stream, NodoArbol* nodo);
void parse_EXP(TokenStream& token_stream, NodoArbol* nodo);
void parse_F(TokenStream& token_stream, NodoArbol* nodo);
NodoArbol* derivar(TokenStream& token_stream);
void parse_error(const std::string& expected, const std::string& found);
void match(TokenStream& token_stream, const std::string& expected);

// Implementación de las funciones
void parse_INSTRUCCION(TokenStream& token_stream, NodoArbol* nodo) {
    std::string token = token_stream.peek();
    if (token == "identificador") {
        NodoArbol* child = new NodoArbol;
        child->simbolo = "INSSIM";
        nodo->hijos.push_back(child);
        match(token_stream, token);
    } else if (token == "if") {
        NodoArbol* child = new NodoArbol;
        child->simbolo = "INSIF";
        nodo->hijos.push_back(child);
        match(token_stream, token);
    } else if (token == "while") {
        NodoArbol* child = new NodoArbol;
        child->simbolo = "INSWHIL";
        nodo->hijos.push_back(child);
        match(token_stream, token);
    } else {
        parse_error("identificador, if, while", token);
    }
}

void parse_EXP(TokenStream& token_stream, NodoArbol* nodo) {
    NodoArbol* exps_node = new NodoArbol;
    exps_node->simbolo = "EXPS";
    nodo->hijos.push_back(exps_node);
    parse_F(token_stream, exps_node);
    NodoArbol* expb_node = new NodoArbol;
    expb_node->simbolo = "EXPB";
    nodo->hijos.push_back(expb_node);
    parse_EXP(token_stream, expb_node);
}

void parse_F(TokenStream& token_stream, NodoArbol* nodo) {
    std::string token = token_stream.peek();
    if (token == "identificador" || token == "if" || token == "while") {
        NodoArbol* child = new NodoArbol;
        child->simbolo = token;
        nodo->hijos.push_back(child);
        match(token_stream, token);
    } else {
        parse_error("identificador, if, while", token);
    }
}

// Función principal de derivación
NodoArbol* derivar(TokenStream& token_stream) {
    NodoArbol* root = new NodoArbol;
    root->simbolo = "INSTRUCCIÓN"; // Símbolo inicial de la gramática
    parse_INSTRUCCION(token_stream, root);
    return root;
}

// Funciones para manejar errores y coincidencias
void parse_error(const std::string& expected, const std::string& found) {
    throw std::runtime_error("Error de parseo: se esperaba '" + expected + "' pero se encontró '" + found + "'");
}

void match(TokenStream& token_stream, const std::string& expected) {
    if (token_stream.has_more_tokens() && token_stream.peek() == expected) {
        token_stream.next();
    } else {
        parse_error(expected, token_stream.peek());
    }
}

// Código original modificado

#define SIZE 5
#define Ignorado -1
#define x 41

// CREO QUE ESTO NO SE NECESITA BORRAR
int esLetra(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

const int NumEstados = 136; // Número total de estados en el DFA
const int NumSimbolos = 29; // Número total de símbolos en el alfabeto (0 y 1)
const char FinDeLexema = '\0'; // Carácter que indica el fin de la cadena

int TablaTransicion[NumEstados][NumSimbolos] = {
    // El contenido de la tabla de transiciones se omite por brevedad.
};

bool EstadosAceptacion[NumEstados] = {
    // El contenido de los estados de aceptación se omite por brevedad.
};

int simulaDFA(int state, char s) {
    int sIndex = (isalpha(s)) ? 0 : (isdigit(s)) ? 27 : (s == '_') ? 26 : -1;

    switch (s) {
        case 'i': sIndex = 1; break;
        case 'F': sIndex = 2; break;
        case 'T': sIndex = 3; break;
        case 'N': sIndex = 4; break;
        case 'a': sIndex = 5; break;
        case 'b': sIndex = 6; break;
        case 'd': sIndex = 7; break;
        case 'e': sIndex = 8; break;
        case 'f': sIndex = 9; break;
        case 'g': sIndex = 10; break;
        case 'l': sIndex = 11; break;
        case 'n': sIndex = 12; break;
        case 'o': sIndex = 13; break;
        case 'p': sIndex = 14; break;
        case 'c': sIndex = 15; break;
        case 'w': sIndex = 16; break;
        case 'r': sIndex = 17; break;
        case 't': sIndex = 18; break;
        case 'y': sIndex = 19; break;
        case 's': sIndex = 20; break;
        case 'm': sIndex = 21; break;
        case 'u': sIndex = 22; break;
        case 'k': sIndex = 23; break;
        case 'x': sIndex = 24; break;
        case 'h': sIndex = 25; break;
    }

    if (sIndex == -1) {
        state = 34;
        sIndex = 0;
    }

    state = TablaTransicion[state][sIndex];
    return state;
}

struct BufferCircular {
    char buffer[SIZE];
    int head;
    int tail;
};

int comentario = 0;
int bloquecomen = 0;
int comillas = 0;
int espacio = 0;

void initBuffer(BufferCircular *cbuf) {
    cbuf->head = 0;
    cbuf->tail = 0;
}

int BufferVacio(const BufferCircular *cbuf) {
    return (cbuf->head == cbuf->tail);
}

int BufferLleno(const BufferCircular *cbuf) {
    return ((cbuf->tail + 1) % SIZE == cbuf->head);
}

int enqueue(BufferCircular *cbuf, int value) {
    if (BufferLleno(cbuf)) {
        std::cout << "Buffer lleno. No se puede encolar.\n";
    }
    if (value == '#') {
        comentario = 1;
    }

    if (value == '"') {
        comillas++;
        if (comillas == 3) {
            bloquecomen = !bloquecomen;
            comillas = 0;
            return Ignorado;
        }
        return Ignorado;
    } else if (comillas > 0) {
        comillas = 0;
    }

    if (bloquecomen == 1) {
        return Ignorado;
    }

    if (comentario == 1) {
        if (value == '\n') {
            comentario = 0;
        }
        return Ignorado;
    } else if (value == '\n') {
        return Ignorado;
    }

    if (value == ' ') {
        espacio++;
    } else if (espacio > 0) {
        espacio = 0;
    }
    if (espacio > 1) {
        return Ignorado;
    } else {
        cbuf->buffer[cbuf->tail] = value;
        cbuf->tail = (cbuf->tail + 1) % SIZE;
        return value;
    }
}

int dequeue(BufferCircular *cbuf) {
    int value = 0;
    if (!BufferVacio(cbuf)) {
        value = cbuf->buffer[cbuf->head];
        cbuf->head = (cbuf->head + 1) % SIZE;
    } else {
        std::cout << "Buffer vacío. No se puede desencolar.\n";
    }
    return value;
}

// Función para dividir el texto en tokens
std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::string token;
    for (char ch : str) {
        if (std::isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    BufferCircular cbuf;
    initBuffer(&cbuf);

    FILE *file = fopen("archivo.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char ch;
    int state = 0;
    std::string content;
    
    while ((ch = fgetc(file)) != EOF) {
        content += ch;
    }
    fclose(file);

    std::vector<std::string> tokens = tokenize(content);

    // Creación del token stream y llamada a la función de análisis sintáctico
    TokenStream token_stream(tokens);
    try {
        NodoArbol* arbol = derivar(token_stream);
        std::cout << "Análisis sintáctico exitoso. Nodo raíz: " << arbol->simbolo << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
