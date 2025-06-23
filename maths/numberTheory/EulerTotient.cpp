#include <bits/stdc++.h>
using namespace std;

/*Função totiente de Euler phi(n);
retorna a quantidade de números coprimos no intervalo fechado [1,n];

propriedades:
    1-> para p primo: phi(p) = p-1;
    2-> para p primo e k >=1: existem (p^k) * 1/p; números em [1,p^k] divisíveis por p; -> phi(p^k)=p^k - p^k-1;
    3-> para a e b coprimos, phi(a*b) = phi(a) * phi(b); (discorre do teorema do resto chinês); 

    Portanto, sendo p_1^k_1 * p_2^k_2*...*p_i^k_i = n a fatoração em primos de um número n,
    phi(n) = phi(p_1^k_1)*...*phi(p_i^k_i) [Prop 3]
    phi(n) = (p_1^k_1 - p_1^(k_1 -1))* ... * (p_i^k_i - p_i^(k_i -1)) [Prop 2]
    phi(n) = p_1^k_1(1 - 1/p_1)*...*p_i^k_i(1 - 1/p_i)
    phi(n) = p_1^k1*p2_k2*...*p_i^ki*(1- 1/p_1)*(1- 1/p_2)*(1- 1/p_i);

*/

//O(sqrt(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    if (n > 1) // n é primo;
        result -= result / n;
    return result;
}

// Faz o que a função phi faz (n*(1- 1/p_i) = n - n/p_i) para cada fator primo p_i de n;
//O(nlog log n)
vector<int> phi_sieve(int n){ 
    vector<int> phi(n+1);
    for(int i = 0; i<=n; i++){
        phi[i]=i;
    }
    for(int i =2; i<=n; i++){
        if(phi[i]==i){ // i é primo
            for(int j =1; j*i <=n; j++){
                phi[j*i] -= phi[j*i]/i; //n - n/primo
            }
        }
    }
    return phi;
}


// fonte : https://cp-algorithms.com/algebra/phi-function.html