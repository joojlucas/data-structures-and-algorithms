#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 100

#ifdef _WIN32
#define CLS "cls"

#elif __linux__
#define CLS "clear"
#endif

typedef struct node
{
  double value;
  struct node *next;
} Node;

typedef struct
{
  Node *headList;
  Node *tailList;
  int size;
} Stack;

Stack *stack;
Stack *result;
char string[BUFF];

void create_Stack();
void push(Stack *stack, double value);
void pop();
void freeList(Stack *s);
void pause();
void operation(Stack *s1, Stack *s2, const char operator);

int main()
{
  int i, j;
  int k = -1;
  char lastOp;

  create_Stack();

  while (k != 0)
  {
    system(CLS);
    printf("\tCalculadora pos-fixada\n\n");

    if (stack->headList != NULL)
      printf("Resultado: \t\t %.2lf\n\n", stack->headList->value);
    if (result->headList != NULL)
      printf("Resultado: \t\t %.2lf\n\n", result->headList->value);
    else
      printf("Resultado:\n\n");
    printf("------------------------------------------------\n");
    printf("1 - Nova operacao.\n");
    printf("0 - Sair.\n");

    scanf("%d", &k);

    switch (k)
    {
    case 1:
      if (stack->size > 0)
        freeList(stack);
      if (result->size > 0)
        freeList(result);

      memset(string, 0, sizeof(char) * BUFF);

      printf("Informe uma operacao pos-fixada de inteiros: ");
      setbuf(stdin, NULL);
      fgets(string, BUFF, stdin);

      string[strlen(string) - 1] = '\0';

      i = 0;
      while (string[i] != '\0')
      {
        if ((string[i] >= 48 && string[i] <= 57) || ((string[i] == '+' || string[i] == '-') && (string[i + 1] >= 48 && string[i + 1] <= 57)))
        {
          push(stack, atof(string));
          j = i + 1;
          while (((string[j] >= 48 && string[j] <= 57) || string[j] == '.') && string[j] != '\0')
            j++;
          memset(string, 32, sizeof(char) * j);
          i = j;
        }
        else if (string[i] == '*' || string[i] == '+' || string[i] == '-' || string[i] == '/')
        {
          operation(stack, result, string[i]);
          lastOp = string[i];
          string[i] = ' ';
        }
        else
          i++;
      }
      operation(result, stack, lastOp);

      break;

    case 0:
      system(CLS);
      printf("Limpando Pilha...\n");
      k = 0;
      freeList(stack);
      freeList(result);
      break;

    default:
      system(CLS);
      printf("invalido!\n");
      pause();
      break;
    }
  }

  return 0;
}

void create_Stack()
{
  stack = (Stack *)malloc(sizeof(Stack));
  result = (Stack *)malloc(sizeof(Stack));

  stack->headList = NULL;
  stack->tailList = NULL;
  stack->size = 0;

  result->headList = NULL;
  result->tailList = NULL;
  result->size = 0;
}

void push(Stack *s, double value)
{
  Node *temp = NULL;

  if (s->size == 0)
  {
    temp = (Node *)malloc(sizeof(Node));

    temp->next = NULL;
    temp->value = value;

    s->headList = s->tailList = temp;
    s->size++;
  }
  else
  {
    temp = (Node *)malloc(sizeof(Node));

    temp->next = NULL;
    temp->value = value;

    s->tailList->next = temp;
    s->tailList = temp;

    s->size++;
  }
}

void pop()
{
  Node *temp = NULL;

  if (stack->size == 0)
  {
    stack->headList = NULL;
    stack->tailList = NULL;
    stack->size = 0;
  }
  else if (stack->size == 1)
  {
    free(stack->headList);
    stack->headList = NULL;
    stack->tailList = NULL;
    stack->size = 0;
  }
  else if (stack->size > 1)
  {
    temp = stack->headList;
    stack->headList = stack->headList->next;
    free(temp);
    stack->size--;
  }
}

void freeList(Stack *s)
{
  while (s->size != 0)
    pop(s);
}

void pause()
{
  setbuf(stdin, NULL);
  printf("\nPressione ENTER para continuar...");
  getchar();
}

void operation(Stack *s1, Stack *s2, const char operator)
{
  double res;

  if (s1->size != 0)
  {
    res = s1->headList->value;
    pop(s1);

    while (s1->headList != NULL)
    {
      if (operator== '+')
        res += s1->headList->value;
      else if (operator== '-')
        res -= s1->headList->value;
      else if (operator== '*')
        res *= s1->headList->value;
      else if (operator== '/')
        res /= s1->headList->value;
      pop(s1);
    }
    push(s2, res);
  }
  else
    operation(s2, s1, operator);
}