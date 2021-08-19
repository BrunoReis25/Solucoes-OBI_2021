#include <iostream>
#include <string>

using namespace std;

int main(){
      bool naipes[4][13] = {false}, erro[4] = {false};// erro representa os montes 
                                                      //e se algum deles tem alguma carta faltando
      string cartas;
      
      getline(cin, cartas);

      for(int i = 2; i < cartas.size() ; i+= 3){
            
            int num = 10 * (cartas[i - 2] - '0') + (cartas[i - 1] - '0') - 1;
            switch (cartas[i]) {
                  case 'C':
                        if(naipes[0][num] == true){ //se duas cartas iguais foram incluidas,
                                                    //entao ocorre um erro
                              erro[0] = true;
                        }
                        naipes[0][num] = true;
                  break;
                  case 'E':
                        if(naipes[1][num] == true){
                              erro[1] = true;
                        }
                        naipes[1][num] = true;
                  break;
                  case 'U':
                        if(naipes[2][num] == true){
                              erro[2] = true;
                        }
                        naipes[2][num] = true;
                  break;
                  case 'P':
                        if(naipes[3][num] == true){
                              erro[3] = true;
                        }
                        naipes[3][num] = true;
            }
      }

      for(int i = 0; i < 4; i++){
            int cont = 0;
            if(erro[i] != true){ // imprime apenas os montes que tem carta faltando
                 for(int j = 0; j < 13; j++){
                        if(naipes[i][j] == false){
                              cont++;
                   }
            }
            cout << cont << endl; 
            }
            else{
                  cout << "erro" << endl;
            }
      }


}