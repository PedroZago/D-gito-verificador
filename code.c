#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n)
{
  if (n <= 1)
  {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int calcularSomaDigitos(int numero)
{
  int soma = 0;

  while (numero != 0)
  {
    soma += numero % 10;
    numero /= 10;
  }

  return soma;
}

int calcularDigitoVerificador(char *codigo)
{
  int n = 15;
  int soma = 0;
  int codigoLength = strlen(codigo);

  for (int i = codigoLength - 1; i >= 0; i--)
  {
    int peso = fibonacci(n);
    soma += (codigo[i] - '0') * peso;
    n--;
  }

  return calcularSomaDigitos(soma) % 5;
}

int main()
{
  char codigo[10];
  printf("Digite o código de nove dígitos: ");
  scanf("%9s", codigo);

  while (strlen(codigo) != 9)
  {
    printf("O código deve ter exatamente nove dígitos. Digite novamente: ");
    scanf("%9s", codigo);
  }

  int digitoVerificador = calcularDigitoVerificador(codigo);
  printf("O dígito verificador do código %s é %d.\n", codigo, digitoVerificador);

  return 0;
}