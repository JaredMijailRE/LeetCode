#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    int L;
    cin >> L;
    cin.ignore();  // Para ignorar el salto de línea después del número de caracteres
    
    string program;
    getline(cin, program);
    
    // Mapa de delimitadores de cierre a apertura
    unordered_map<char, char> matchingDelimiter = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    // Pila para rastrear delimitadores de apertura
    stack<pair<char, int>> s;
    
    for (int i = 0; i < L; ++i) {
        char currentChar = program[i];
        
        // Ignorar los espacios
        if (currentChar == ' ') {
            continue;
        }
        
        // Si es un delimitador de apertura, agregarlo a la pila
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            s.push({currentChar, i});
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            // Si la pila está vacía o el delimitador no coincide, reportar el error
            if (s.empty() || s.top().first != matchingDelimiter[currentChar]) {
                cout << currentChar << " " << i << endl;
                return 0;
            } else {
                // Si coincide, quitar el elemento de la pila
                s.pop();
            }
        }
    }
    
    // Si la pila no está vacía, significa que hay delimitadores de apertura no emparejados
    if (!s.empty()) {
        cout << s.top().first << " " << s.top().second << endl;
    } else {
        cout << "ok so far" << endl;
    }
    
    return 0;
}

