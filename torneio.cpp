#include <iostream>

using namespace std;

int main(){
      char resultado;
      int cont = 0, grupo;

      for(int i = 0; i < 6; i++){
            cin >> resultado;

            if(resultado == 'V'){
                  cont++;
            }
      }

      if (1 <= cont && cont <= 2){
            grupo = 3;
      }
      else if (3 <= cont && cont <= 4){
            grupo = 2;
      }
      else if (5 <= cont){
            grupo = 1;
      }
      else {
            grupo = -1;
      }

       cout << grupo << endl;

      
      return 0;
}