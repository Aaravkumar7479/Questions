#include<stdio.h>
#include<math.h>
// It is Two class problem

typedef struct Data{
    float x;
    float y;
    int label; //label = (0,1) only we take two class problem.
}Data;


float distance(Data a ,Data b){     
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int main(){
    int k,n;
    printf("Enter the number of training sample : ");
    scanf("%d",&n);
    Data train[n]; 
    printf(" Enter all training data \n");
    for(int i=0;i<n ;i++) {
    scanf(" %f %f %d",&train[i].x ,&train[i].y,&train[i].label);
    }
    printf("Enter the value of k:");
     scanf("%d",&k);

     



    Data test; // new test variable of of class Data
    printf("Enter the test data (X Y) :");
    scanf("%f %f",&test.x,&test.y);

    float dist[n]; // store value of all distance in array dist
    int labels[n]; // store corresponding label in array labels
    for(int i=0;i<n ;i++){
        dist[i]=distance(train[i],test);
        labels[i]=train[i].label;

    }
    /*printf("\n Distances between your Test data and training  data : \n");
    for(int i=0;i<n ;i++) printf("%f ",dist[i]);*/
    printf("\n");
    
    // Bubble sort  
    int i,j;
    for( i=0;i<n-1 ;i++){ // n-1 passes 
        for(j=0;j<=n-2 ;j++){
            if(dist[j]>dist[j+1]){
                float temp=dist[j];
                dist[j]=dist[j+1];
                dist[j+1]=temp;
                int lab=labels[j]; // labels also swapping
                labels[j]=labels[j+1];
                labels[j+1]=lab;
            }
        } 
    }

    /*printf("\n Sorted  Euclidean Distance , label\n");
    for(int i=0;i<n ;i++) {
    printf("%f  %d\n",dist[i],labels[i]);
    }*/


     int count0=0;
    int count1=0;

    for(int i=0;i<k ;i++) {
        if(labels[i]==0) count0++;
        else if(labels[i]==1) count1++;

    }
    if(count0==count1){

        printf("According to your k value , Tie case happens both  Classes get the same number of votes ,\n Therefore give another value of k. ");
        return 0;
    }

    int predicted = (count0>count1) ? 0 :1; // Ternary or conditional operator

    printf(" \n Predicted class for your test data is :%d ", predicted);

    return 0;
} 