#include <stdio.h>
#include <math.h>

int main(){
  int x, y;
  scanf("%d%d", &x,&y);

  x = (x<0)?-x:x;
  y = (y<0)?-y:y;
  if(x==0 || y ==0){
	  printf("%d", (x==0)?y:x);
  }
  else if(x%y == 0 || y%x == 0){
    printf("%d", (x<y)?x:y);
  }
  else{
    int num = 1;
	int count = (x<y)?x:y;
    for(int i=1; i<=count ;i++){
      if(x%i == 0 && y%i ==0)
        num = i;
    }
    printf("%d", num);
  }  
}
