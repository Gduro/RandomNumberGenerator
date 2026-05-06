#include <iostream>
#include <cstdlib>
#include <ctime>

void genRand( int n, int max, int min, int *temps)
{
    int *ptr = (int*) realloc(temps,n*sizeof(int));
    if(ptr== nullptr){
        return;
    }
    temps=ptr;
    for (int i = 0; i < n; ++i) {
        temps[i]=min+rand()%(max-min+1);
        printf("%d ",temps[i]);

    }

    printf("\n");

}
int main() {
    srand(time(NULL));
    int *temps = nullptr;
    int n;
    int max;
    int min;
    int on=1;
    printf("Enter max of generated num: \n");
    scanf("%d", &max);
    printf("Enter min of generated num: \n");
    scanf("%d",&min);
    do{
        printf("How many numbers do u want to generate? \n");
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        genRand(n,max,min,temps);

    } while (on);
    free(temps);
    return 0;
}
