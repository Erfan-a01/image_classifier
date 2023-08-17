#include <math.h>


//********************************distance of two array*********************************
float distance_of_two_array(int array1[],int array2[],int n) {
    float sum=0;
    for (int i=0;i<n;i++) {
        sum+=pow(array1[i]-array2[i],2)
    }
    return sum;
}
//**********************************distance of matrix**********************************
void distance_mat(int array[],int save[],int matrix[][28],int n) {
    int sum;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=pow(matrix[i][j]-array[i],2);
        }
        save[i]=sum;
        sum=0;
    }
}
//*******************************mean function*********************************************
float mean_cal(int x,int y,float submatrix[][28]){
    float sum=0,mean;
    int finalx=x+7;
    int finaly=y+7;
    for (x;x<finalx;x++){
        for (y;y<finaly;y++){
            sum+=submatrix[x][y];
        }
    }
    mean=sum/49;
    return mean;
}
//*******************************std calculatar*********************************************
float std_cal(int x,int y,float submatix[][28]){
    float sum=0;
    int finalx=x+7;
    int finaly=y+7;
    float mean=mean_cal(int x,int y,float submatrix);
    for (x;x<finalx;x++){
        for (y;y<finaly;y++){
            sum+=pow((submatrix[x][y]-mean),2);
        }
    }
    float std=sqrt((1/48)sum);
    return std;
}
//****************************feature vector calculater*************************************
void feature_cal(float matrix[][28],float array[16]){
    int k=0;
    for (int i=0;i<28;i+=7){
        for (int j=0;j<28;j+=7){
            array[k]=mean(i,j,matrix);
            k++;
            array[k]=std(i,j,matrix);
            k++;
        }
    }

}
//-------------------------------------------------------------------
