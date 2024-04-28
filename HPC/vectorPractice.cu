#include<stdio.h>
#include<cuda.h>


__global__ void arrAdd(int *x , int *y , int*z){
    int id = blockidx.x;
    z[id] =  x[id] + y[id];
}

int main(){

    int a[6] , b[6] , c[6];
    int *d , *e , *f;   
    printf("\n Enter elememts of first array \n")
    for(int i = 0 ; i < 6 ; i++){
        scanf("%d" , &a[i]);
    }

    printf("\n Enter elememts of second array \n")
    for(int i = 0 ; i < 6 ; i++){
        scanf("%d" , &b[i]);
    }

    cudaMalloc((void**)&d , 6*sizeof(int));
    cudaMalloc((void**)&e , 6*sizeof(int));
    cudaMalloc((void**)&f , 6*sizeof(int));

    cudaMemcpy(d , a , 6*sizeof(int) , cudaMemcpyHosttoDevice);
    cudaMemcpy(e , b , 6*sizeof(int) , cudaMemcpyHosttoDevice);

    arrAdd<<<6,1>>>(d,e,f);

    cudaMemcpy(c , f , 6*sizeof(int) , cudaMemcpyDevicetoHost);

    for(int i = 0 ; i < 6 ; i++){
        printf("%d" , c[i]);
    }

    cudaFree(d);
    cudaFree(e);
    cudaFree(f);

    return 0;
    
}