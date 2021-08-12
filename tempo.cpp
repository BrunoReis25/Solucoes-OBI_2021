#include <iostream>
#include <algorithm>

using namespace std;


int e_amigo (int num, int(*mat)[2], int tam){ // verifica se já é um amigo, 
                                              //se for a função retorna a posição desse amigo.
      
      for(int i = 0; i < tam; i++){
            if(num == mat[i][0]){
                  return i;
            }
      }
      return -1;
}


int main(){
      int N, amigos[20][2] = {0}, num[20], tempo[20], num_amigos = 0;
      char eventos[22];

      cin >> N;

      tempo[0] = 0;
      int k = 0;
      for(int i = 0; i < N; i++){
            cin >> eventos[i] >> num[i];
            if(i < N-1){ 
                  // cria um arranjo do mesmo tamanho do arranjo de entrada, 
                  //mas que cronometra o tempo até aquele evento.
                  if(eventos[i] == 'T'){ 
                        tempo[i] = 0;
                        tempo[i+1] = tempo[i-1] + num[i];
                  }
                  else if(eventos[i] == 'R' || eventos[i] == 'E'){
                        tempo[i+1] = tempo[i] + 1;
                  }
            }

            // adiciona na matriz apenas uma vez cada amigo.
           if(e_amigo(num[i], amigos, k) == -1 && eventos[i] != 'T') {
                 if( k > 0)
                        if(num[i]  > amigos[k-1][0]){
                              amigos[k][0] = num[i];
                        }
                        else{
                              int aux = amigos[k-1][0];
                              amigos[k-1][0] = num[i];
                              amigos[k][0] = aux;
                        }
                  else
                      amigos[k][0] = num[i]; 
                      
                 amigos[k][1] = 0;
                 k++;
           } 
      }

      for(int i = 0; i < N; i++){

           if(eventos[i] == 'R'){
                 bool achou = false;
                 int posi = e_amigo(num[i], amigos, k);

                 for(int j = i + 1; j < N; j++){

                       if(num[i] == num[j] && eventos[j] == 'E'){
                             amigos[posi][1] +=  tempo[j] - tempo[i];
                             achou = true;
                             break;
                       }     
                  }

                  if(achou == false){
                        amigos[posi][1] = -1;
                  }
           }
            
      }

      for(int i = 0; i < k; i++){
            cout << amigos[i][0] << " " << amigos[i][1] << endl;
      }

      return 0;
}