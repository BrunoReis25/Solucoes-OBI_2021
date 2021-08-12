#include <iostream>

using namespace std;

int main(){
      int j, numero;
      int N, vetor[100002];
      long int soma = 0;
      
      
      cin >> N;

      j = 0;
      for(int i = 0; i < N; i++){

            cin >> numero;

             if (numero == 0){
                  j--;
                  vetor[j] = 0;
            }
            else{
                  vetor[j] = numero;
                  j++;
            }

      }
      vetor[j] = 0;

      j = 0;
      while(vetor[j] != 0){
            soma += vetor[j];
            j++;
      }

      cout << soma;

      return 0;
}