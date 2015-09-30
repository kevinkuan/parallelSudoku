#include <stdio.h>
#include <stdlib.h>

int *a;
int NUMS;
int SQRT;

int test_col(int x)
{
  int i, j;
  int col = x % NUMS;

  for (i = 0; i < NUMS; i++){
    if (a[NUMS*i + col] != 0){
      for (j = i+1; j < NUMS; j++){
	if (a[NUMS*j + col] == a[NUMS*i + col])
	  return 0;
      }
    }
  }
  return 1;
}


int test_line(int x)
{
  int i, j;
  int line = x / NUMS;

  for (i = 0; i < NUMS; i++){
    if (a[NUMS*line + i] != 0){
      for (j = i+1; j < NUMS; j++){
	if (a[NUMS*line + j] == a[NUMS*line + i])
	  return 0;
      }
    }
  }
  return 1;
}


int test_square(int x)
{
  int i, j;
  int col1, line1;
  int col0, line0;

  int col = (x % NUMS) - (x % SQRT);
  int line = (x / NUMS) - ((x / NUMS) % SQRT);

  col0 = col;
  line0 = line;
  for (i = 0; i < NUMS; i++){
    if (a[NUMS*line0 + col0] != 0){
      col1 = col0;
      line1 = line0;
      for (j = i+1; j < NUMS; j++){
	col1 = col1 + 1;
	if (col1 % SQRT == 0){
	  col1 = col;
	  line1 = line1+1;
	}
	if (a[NUMS*line1 + col1] == a[NUMS*line0 + col0])
	  return 0;
      }
    }
    col0 = col0 + 1;
    if (col0 % SQRT == 0){
      col0 = col;
      line0 = line0+1;
    }
  }
  return 1;
}


int main(int argc, char **argv)
{
  char *filename;
  FILE *f;
  int input;
  int i;

  if (argc == 1){
    printf("Reads from stdin puzzle values\nusage: check <num> < <puzzle>\nwhere for a sudoku of n lines by n rows, num = sqrt(n), and puzzle is the file with the sudoku puzzle\n"); 
    exit(0);
  }

  SQRT = atoi(argv[1]);
  NUMS = SQRT * SQRT;

  printf("NUMS is: %d\n", NUMS);

   a = malloc(NUMS*NUMS*sizeof(int));

  for(i = 0; i < NUMS*NUMS; i++ ){
    scanf("%i", &input);
    printf("Scanning a[%d]: %d\n", i,input);
    a[i] = input;
  }

  for (i = NUMS * NUMS - 1; i >= 0; i--){

    if (a[i] <= 0 || a[i] > NUMS) {
      printf("failed test\n");
      break;
    }

    //printf("testing value: %i\n", i);
    if (!test_col(i)){
      printf("failed test\n");
      break;
    }
    
    if (!test_line(i)){
      printf("failed test\n");
      break;
    }
    
    if (!test_square(i)){
      printf("failed test\n");
      break;
    }
    
  }

  if (i < 0)
    printf("valid sudoku\n");
}
