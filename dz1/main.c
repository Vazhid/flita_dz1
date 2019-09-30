//
//  main.c
//  dz1
//
//  Created by Vazhid on 02/09/2019.
//  Copyright © 2019 Vazhid. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    
    int lenth_array;
    printf("Сколько эллементов в множестве: ");
    scanf("%d", &lenth_array); getchar();
    
    char *bin_array[lenth_array];
    for(int i = 0; i < lenth_array; i++){
        bin_array[i] = calloc(1, sizeof(char));
    }
    
    int x = 0, y = 0;
    char c;
    _Bool flag_end = 1;
    printf("Введите %d-й элемент: ",x+1);
    while( flag_end && (c=getchar()) != EOF){
        if(c >=  '0' && c <= '1'){
            bin_array[x][y] = c;
            y++;
            bin_array[x] = (char*) realloc(bin_array[x], y+1);
        } else if (c == '\n'){
            if(x+2 <= lenth_array)
                printf("Введите %d-й элемент: ",x+2);
            
            bin_array[x] = (char*) realloc(bin_array[x], y+1);
            bin_array[x][y] = '\0';
            x++;
            y=0;
        }
        if (x >= lenth_array){
            flag_end = 0;
        }
    }
    
    int *dec_array;
        dec_array = calloc(lenth_array, sizeof(int));

    for(int i = 0; i< lenth_array; i++){
        dec_array[i] = 0;
        int j = 0, lenth = 0;
        while (bin_array[i][lenth] != '\0')
            lenth++;
        lenth-=1;
        
        while(bin_array[i][j] != '\0'){
            dec_array[i] += (bin_array[i][j] - '0') * pow(2,lenth-j);
            j++;
        }
    }
    for(int i=0; i< lenth_array; i++){
        printf("%s -> %d\n", bin_array[i], dec_array[i]);
        
    }
    
    
    return 0;
}

