#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

void shuffle(uint8_t * list, uint16_t list_size);

int main() {

    srand (time(NULL));
    uint8_t size=rand()%8;
    uint8_t *list;
    list = malloc(8 * size);
    for (int i=0; i<size;i++){
        list[i]=rand()%10;
    }
    for (int i=0;i<size;i++){
    printf("%d",list[i]);
    }
    printf("\n");
    shuffle(list,size);
    for (int i=0;i<size;i++){
    printf("%d",list[i]);
    }
    return 0;
}

void shuffle(uint8_t * list, uint16_t list_size){

    int i = 0,j;
    int range=list_size;
    uint8_t* scratch;
    scratch = malloc(sizeof(list));
    int index = rand()%range;  
    for (j=0;j<list_size;j++){
        scratch[j] = list[j] ;
    }
    for (int i=0;i<list_size;i++){
    printf("%d",scratch[i]);
    }
    printf("\n");
    /*while(i = 0){
      index=rand()%range;
      if(scratch[index] != -1){
        list[i] = scratch[index];
        scratch[index]=-1;
        i = 1;
      }    
      for(int k = 0; k < list_size; k++){
        if(scratch[k] != -1){
          i = 0;
        }
      }
    }*/
    for (i=list_size-1;i>=0;i--){
            while(scratch[index] == -1){
              index=rand()%range;
            }
            if(scratch[index] != -1){
            list[i]  = scratch[index];
            scratch[index]=-1;
            }else i++;
    }
} 