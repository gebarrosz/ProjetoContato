#include <iostream>
#include <string>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() {
        dia = 1;
        mes = 1;
        ano = 2000;
    }

    Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }
};

class Contato {
private:
    string nome;
    string email;
    string telefone;
    Data dtnasc;

public:
    Contato() : dtnasc() {}

    Contato(string n, string e, string t, Data d) {
        nome = n;
        email = e;
        telefone = t;
        dtnasc = d;
    }

    void setNome(string n) { nome = n; }
    void setEmail(string e) { email = e; }
    void setTelefone(string t) { telefone = t; }
    void setDataNascimento(Data d) { dtnasc = d; }

    string getNome() { return nome; }
    string getEmail() { return email; }
    string getTelefone() { return telefone; }
    Data getDataNascimento() { return dtnasc; }

    int idade() {
        int anoAtual = 2025;
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
    Contato contatos[5];

    for (int i = 0; i < 5; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Contato " << (i + 1) << ":" << endl;

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        // Validação do dia
        do {
            cout << "Dia de nascimento (1 a 31): ";
            cin >> dia;
            if (dia < 1 || dia > 31) {
                cout << "Dia invalido! Tente novamente." << endl;
            }
        } while (dia < 1 || dia > 31);

        // Validação do mês
        do {
            cout << "Mes de nascimento (1 a 12): ";
            cin >> mes;
            if (mes < 1 || mes > 12) {
                cout << "Mes invalido! Tente novamente." << endl;
            }
        } while (mes < 1 || mes > 12);

        cout << "Ano de nascimento: ";
        cin >> ano;
        cin.ignore(); // limpar buffer

        Data nascimento(dia, mes, ano);
        contatos[i] = Contato(nome, email, telefone, nascimento);

        cout << endl;
    }

    cout << "Contatos cadastrados:" << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}