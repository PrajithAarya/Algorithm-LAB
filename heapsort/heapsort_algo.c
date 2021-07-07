#include<stdio.h>
#include<stdlib.h>
void heap_tree_construction(int a[],int n);
void heap_sort(int a[],int n);
void heap_adj(int a[],int n);


int main(){
int i,n,a[10];
printf("ENTER THE NUMBER OF ELEMENTS\n");
scanf("%d",&n);
printf("ENTER THE ELEMENTS OF THE ARRAY\n");
for(i=0;i<n;i++){
     scanf("%d",&a[i]);
}
heap_sort(a,n);
printf("SORTED ARRAY:\n");
for(i=0;i<n;i++){
     printf("%d\n",a[i]);
}
}

void heap_tree_construction(int a[],int n){
     int r,c,i;
     int item;
     for(i=1;i<n;i++){
       item=a[i];
       c=i;
       r=(c-1)/2;
       while(c>0 && item>a[r]){
            a[c]=a[r];
            c=r;
            r=(c-1)/2;
       }
       a[c]=item;
     }
}

void heap_adj(int a[],int n){
     int item;
     int r,c;
     r=0;
     item=a[r];
     c=2*r+1;
     while(c<=n-1){
          if((c+1)<=n-1){
               if(a[c]<a[c+1])
               c=c+1;
          }
          if(item<a[c]){
               a[r]=a[c];
               r=c;
               c=2*r+1;
          }else{
               break;
          }
     }
     a[r]=item;
}


void heap_sort(int a[],int n){
int i,temp;
heap_tree_construction(a,n);
for(i=n-1;i>0;i--){
     temp=a[0];
     a[0]=a[i];
     a[i]=temp;
     heap_adj(a,i);
}
}
