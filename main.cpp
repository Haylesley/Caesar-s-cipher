#include <iostream>
#include <string>

using namespace std;

string encrypt_caesar(const string &text, int shift) { // &text это использование ссылки
    string result = "";
    
    // Приводим смещение в диапазон [0, 25]
    shift = shift % 26;

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            // Для строчных букв
            result += (c - 'a' + shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            // Для заглавных букв
            result += (c - 'A' + shift + 26) % 26 + 'A';
        } else {
            result += c;
        }
    }

    return result;
}

string decrypt_caesar(const string &text, int shift) {
    // Для расшифровки достаточно сдвинуть в обратную сторону
    return encrypt_caesar(text, -shift);
}

int main() {
    string text;
    int shift;

    // Пример ввода
    cout << "Enter the encryption text: ";
    getline(cin, text);
    cout << "Enter the shift value: ";
    cin >> shift;

    // Шифрование
    string encrypted = encrypt_caesar(text, shift);
    cout << "Ciphertext: " << encrypted << endl;

    // Расшифровка
    string decrypted = decrypt_caesar(encrypted, shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
