#include <stdio.h>
#include <math.h>

void dct(int m, int n, double i[m][n], double f[m][n]){
    double s;
    int u,v,x,y;
    for(u=0;u<m;u++){
        for(v=0;v<n;v++){
            s=0;
            for(x=0;x<m;x++)
                for(y=0;y<n;y++)
                    s+=i[x][y]*cos(((2*x+1)*u*M_PI)/(2*n))*cos(((2*y+1)*v*M_PI)/(2*m));
            if(!u)
                s*=1/sqrt(2);
            if(!v)
                s*=1/sqrt(2);
            s*=2/(sqrt(n*m));
            f[u][v]=round(s);
        }
    }
}

void aff(int m, int n, double a[8][8]){
    int x,y;
    for(x=0;x<m;x++){
        for(y=0;y<n;y++)
            printf("%4g",a[x][y]);
        printf("\n");
    }
}

int main(){

    int m=8,n=8;
    double f[m][n];
    double i[8][8]={{62,65,65,68,72,84,42,18},
    {48,57,60,60,66,66,51,24},
    {45,54,58,60,65,60,48,26},
    {37,48,53,56,53,48,40,33},
    {58,50,52,64,60,51,42,31},
    {64,58,64,72,75,74,49,50},
    {82,72,65,76,76,72,53,38},
    {79,71,60,67,55,58,48,40}};

    dct(m,n,i,f);

    aff(m,n,i);
    printf("\n");
    aff(m,n,f);

	return 0;
}
