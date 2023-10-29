#include "checkers.h"
#include <regex.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h>
#include <string.h> 
// flavius, obrigado por passar a logica de como alguns checkers devem ser feitos

int checkCPF(char* cpf){
  if (strlen(cpf) != 11) {
    printf("CPF inválido.\n");
    return 1;
  }

  int digito1 = 0, digito2 = 0;
  for (int i = 0; i < 9; i++) {
    digito1 += (cpf[i] - '0') * (10 - i);
    digito2 += (cpf[i] - '0') * (11 - i);
  }
  digito1 = (digito1 % 11) < 2 ? 0 : 11 - digito1;
  digito2 = (digito2 % 11) < 2 ? 0 : 11 - digito2;

  if (cpf[9] != digito1 || cpf[10] != digito2) {
    return 1;
  }

  return 0;
}


int checkDigito(char* array){
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

int checkTelefone(char* array){
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
    } else {
        return 0;
    }
}

int checkNome(char* nome) {
    for (int i=0; nome[i]!='\0'; i++) {
        if (!checkLetra(nome[i])) {
            return 0;
        }
    }
    return 1;
}

void clear(){
  system("cls||clear");
}