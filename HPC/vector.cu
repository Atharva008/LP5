#include<stdio.h>
#include<cuda.h>


__global__ void arrAdd(int *x , int *y , int *z){
    int id = blockIdx.x;
    z[id] = x[id] + y[id];
}


int main(){
    int a[6] , b[6] ,  c[6];
    int d* , e* , f*;
    printf("\n Enter 6 elements in first array \n");
    for(int i = 0 ; i < 6 ; i++){
        scanf("%d" , &a[i]);
    }
    printf("\n Enter 6 elements in second array \n")
    for(int i = 0 ; i < 6 ; i++){
        scanf("%d" , &b[i]);
    }


    cudaMalloc((void**)&d , 6*(sizeof(int)))
    cudaMalloc((void**)&e , 6*(sizeof(int)))
    cudaMalloc((void**)&f , 6*(sizeof(int)))

    cudaMemcpy(d,a,6*(sizeof(int)),cudaMemcpyHosttoDevice)
    cudaMemcpy(e,b,6*(sizeof(int)),cudaMemcpyHosttoDevice)

    arrAdd<<<6,1>>>(d,e,f);

    cudaMemcpy(c,f,6*(sizeof(int)),cudaMemcpyDevicetoHost)
    printf("\n Sum of vectors is \n")
    for(int i = 0 ; i < 6 ; i++){
        printf("%d\t" , c[i]);
    }

    cudaFree(d);
    cudaFree(e);
    cudaFree(f);

}