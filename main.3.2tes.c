#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>


int test3(int a, int b);
double f(double x);
double chord_method (double x1, double x2, double eps, int N);
double m_of_hlv (double x1, double x2, double eps, int N);


int main()
{

    double x1, x2, root;
     double  eps;
     int N ;
     int answer;
     int method ;
 int d = 12;
 int  c = 3;
// test3(d,c);
 printf("\nresult=%d\n", test3(d,c));


    do{
            printf("x1=");
            scanf("%lf", &x1);
            printf("x2=");
            scanf("%lf", &x2);
            printf("N=");
            scanf("%d", &N);
            printf("eps=");
            scanf("%lf", &eps);


    }while(f(x1)*f(x2)< 0 );



    printf("\n choose a method 1-chord ; \n 2- m_of_hlv");
    printf("\n\nYour method:");
    scanf("%d",&method);
    while(method!=1 && method!=2)
        {
            printf("Error. Please, enter variant again(1 or 2):");
            scanf("%d",&method);

          }
          if(method==1)
          {
               root =chord_method(x1, x2, eps, N);
               printf("\n\nroot=%lf", root);
          }
          else
            {

    root = m_of_hlv(x1, x2, eps, N);

    printf("\n\nroot=%lf", root);
            }




    return 0;
}

int test3( int a, int b){
 int x;
if (a>b){
    x = a;
}
    else
    x = b;



}


//-------------------



double m_of_hlv (double x1, double x2, double eps, int N)
{

    int iter_count=0;
    int answer;
    double xi;
    clock_t start, end;
    double delta_t;


    start = clock();


    do{

         iter_count++;
         xi = (x1 + x2) / 2  ;

    if(f(xi)* f(x1) < 0 )
         x1 = xi;
    else
         x2 = xi;

         if ( iter_count%N == 0 )
            {

            printf("\n\n %d itertations done", iter_count);
            printf("\ncurrent x = %lf", xi);
            printf(" f(x) = %lf", f(xi));
            printf("\nYou want continue or exit?\n1-exit\n2-continue");
            printf("\nyour answer:");
            scanf("%d", &answer);
            while(answer!=1 && answer!=2)
          {
            printf("Error. Please, enter variant again(1 or 2):");
            scanf("%d",&answer);

          }

          if(answer==1){
            printf("\nPress any key to exit");
            getch();
            exit(0);
          }


         }


    }while(fabs(x1-x2) >= eps );



     end = clock();
     delta_t =(double) (end - start) / CLOCKS_PER_SEC;
     printf("\n\n delta_t = %lf", delta_t);

      return xi;
    }







//-------------------



double chord_method (double x1, double x2, double eps, int N)
{


    double xi;
     int iter_count=0;
    int answer;
    clock_t start, end;
    double delta_t;


    start = clock();


    do{
        iter_count++;
         xi = (f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));

    if(f(xi)>0 )
         x1 = xi;
    else
         x2 = xi;

          if ( iter_count%N == 0 )
            {

            printf("\n\n %d itertations done", iter_count);
            printf("\ncurrent x = %lf", xi);
            printf(" f(x) = %lf", f(xi));
            printf("\nYou want continue or exit?\n1-exit\n2-continue");
            printf("\nyour answer:");
            scanf("%d", &answer);
            while(answer!=1 && answer!=2)
          {
            printf("Error. Please, enter variant again(1 or 2):");
            scanf("%d",&answer);

          }

          if(answer==1){
            printf("\nPress any key to exit");
            getch();
            exit(0);
          }


         }


    }while(fabs(f(xi))> eps );





    end = clock();
     delta_t =(double) (end - start) / CLOCKS_PER_SEC;
     printf("\n\n delta_t = %lf", delta_t);




    return xi;

}



//------------------



double f(double x)
{
    double y;
    y = (0.4*pow(x - 100, 3)+0.3*pow (x,2)-0.2*x+200);
    return y;
}
