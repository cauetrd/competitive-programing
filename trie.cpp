#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define QTD_CARACTERES 26 //alfabeto minusculo
#define LETRA_BASE 'a' //primeira letra pra fazer indexação

struct Nodo
{
    Nodo* filhos[QTD_CARACTERES];
    bool fimDePalavra;
    ll ocorrencias =0;


    Nodo() {
        fimDePalavra = false;
        ocorrencias = 0;
        for(int i = 0; i<QTD_CARACTERES; i++){
            filhos[i] = NULL;
        }
    }
};

struct Trie
{
    Nodo* raiz;
    char letraBase = LETRA_BASE;


    public:

    Trie() {
        raiz = new Nodo();
    }

    void insert(string s){
        Nodo* cur = raiz;
        for(char c : s){
            if(cur->filhos[c- letraBase] == NULL){
                Nodo* novoNodo = new Nodo();

                cur->filhos[c-letraBase] = novoNodo;   
            }
            cur->ocorrencias++;
            cur = cur->filhos[c-letraBase];
        }
        cur->ocorrencias++;
        cur->fimDePalavra = true;
    }

    bool searchWord(string s){
        Nodo* cur = raiz;

        for(char c : s){
            if(cur->filhos[c-letraBase]== NULL){
                return false;
            }

            cur = cur->filhos[c-letraBase];
        }

        return cur->fimDePalavra;
    }

    ll countPrefix(string s){
        Nodo* cur = raiz;

        for(char c: s){
            if(cur->filhos[c-letraBase]==NULL){
                return false;
            }

            cur = cur->filhos[c-letraBase];
        }
        return cur->ocorrencias;
    }
};

int main() {

    string s = "doguinho";
    string p = "dogao";
    string q = "dogg";
    string m = "doguimio";

    Trie trie;
    trie.insert(s);
    cout << trie.countPrefix("dog") << endl;
    cout << trie.searchWord("doguinho") << endl;
    trie.insert(p);
    trie.insert(q);

    cout << trie.countPrefix("dog") << endl;
    cout << trie.searchWord("dog") << endl;
    cout << trie.countPrefix("doga") << endl;
    cout << trie.searchWord("dogao") << endl;
    cout << trie.countPrefix("oi") << endl;
    cout << trie.searchWord("sim");
    
    

    




}
