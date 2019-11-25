//
// Created by Christian Ledgard on 11/24/19.
//
#include <iostream>

using namespace std;

long long binomialCoeff (int n, int k)
{
    int maximun = max(n - k, k);
    long long resultado = 1;

    for ( int i = maximun + 1, p = 1; i <= n; i++, p++) {
        resultado *= i;
        resultado /= p;
    }
    return resultado;
}

int main(){

    int n = 0;

    cin >> n;

    for (int j = 0; j < n; ++j) {
        string input, var1,var2, potStr;
        int potencia;
        bool flag = false;

        cin >> input;

        for (int i = 1; i < input.size(); ++i) {
            if(input[i] == ')')
                break;
            if(input[i] == '+'){
                flag = true;
                continue;
            }
            if(flag){
                var2 += input[i];
            }else{
                var1 += input[i];
            }
        }

        for (int k = 0; k < input.size(); ++k) {
            if(!flag){
                potStr+=input[k];
            }
            if(input[k] == '^')
                flag = false;
        }

        potencia = stoi(potStr);


        cout << "Case " << j+1 << ": ";
        for (int a = potencia, b = 0; b <= potencia; ++b, --a) {

            if(binomialCoeff(potencia,b) == 0)
                continue;
            else if (binomialCoeff(potencia,b) != 1){
                cout << binomialCoeff(potencia,b) << "*";
            }

            if(a != 0 and a != 1){
                cout << var1 << "^" <<  a;
            } else if(a == 1){
                cout << var1;
            }

            if(b != 0 and a != 0){
                cout << "*";
            }

            if(b != 0 and b != 1){
                cout << var2 << "^" <<  b;
            } else if(b == 1){
                cout << var2;
            }

            if(b<potencia)
                cout << "+";
        }

        cout << endl;

    }



    return 0;
}