#include "checkers.h"
#include <regex.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h>
#include <string.h> 

// flavius, obrigado por passar a logica de como alguns checkers devem ser feitos

int checkCPF(char cpf[]) {
    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11){
      return 0;
    }
        
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) || (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0)){
        return 0;
    }
    else {
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--)
            digito1 += (cpf[i] - '0') * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;
        else {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--)
                digito2 += (cpf[i] - '0') * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - '0') != digito2)
                return 0;
        }
    }
    return 1;
}


int checkDigito(char array[]){
  int flag; 
  for(int i = 0; array[i]!='\0'; i++){
    if(array[i] >= '0' || array[i] <='9'){ 
      flag = 1; 
    } else{
      flag = 0; 
    }
  }
  return flag;
}

int checkTelefone(char array[]){
  if(strlen(array)==11){
    int flag = checkDigito(array);
    if(flag == 1){
      return 1;
    }
  }
  return 0; 
}

int checkLetra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else if(c == ' '){
        return 1; 
    } 
    else {
        return 0;
    }
}

int checkNome(char nome[]) {
    int flag; 
    for (int i=0; i < strlen(nome) ; i++) {
      if(checkLetra(nome[i]) == 1 ){
        flag=1; 
      }else{
        flag=0;
      }
  }
    return flag;
}

void clear(){
  system("cls||clear");
}