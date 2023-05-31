#include <stdio.h>
#include <stdlib.h>


const int GAMESIZE = 100;

int main(){
int8_t * gameboard[GAMESIZE];
int win_len;
}

int8_t tictactoe_check(int8_t * gameboard, int win_len){
  int x = 0,o= 0;
  int8_t result = 0;
  for(int i = 0; i< GAMESIZE; i++){
    //check rows
    if(gameboard[i] != 0){
      if(gameboard[i] == 1){
        x++;
        o = 0;
      }else{
        o++; 
        x = 0;
      }
    }
    result = check_result(x,o, win_len);
    if(i%10 == 0 && i != 0){
      x = 0;
      o = 0;
    }
  }
  for(int i = 0; i < 10; i++){
    //check colums
    x = 0;
    o = 0;
    for(int j = i; j < GAMESIZE; j = j +10){
      if(gameboard[j] != 0){
        if(gameboard[j] == 1){
          x++;
          o = 0;
        }else{
          o++; 
          x = 0;
        }
        result = check_result(x,o, win_len);

      }
    }
  }
  for(int i = 0; i < 19; i++){ //19 = 10 columnas + 9 filas sin comprobar.
    //check diags
    int j = 0;
    if(i < 10){
      j = i;
    }else j = 10 * (i - 10);
    for(j; j < GAMESIZE; j = j +11){
      if(gameboard[j] != 0){
        if(gameboard[j] == 1){
          x++;
          o = 0;
        }else{
          o++; 
          x = 0;
        }
        result = check_result(x,o, win_len);
      }
      //this way it only cheks until the end of the row.
      if((j + 11) % 10 == 0) j = GAMESIZE; 
      }
  }
  return result;
}

int8_t check_result(int x, int o, int win_len){
  int8_t result = 0;
   if(x == win_len){
      result = 1;
    } else if (o == win_len) {
      result = 2;
    }
  return result;
}