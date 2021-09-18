#include <stdio.h>
#include<conio.h>
#include<malloc.h>
typedef int keytype; //dinh nghia bien keytype la kieu so nguyen
typedef float othertype; // dieu nghia bien othertype la kieu so thuc
typedef struct{
	keytype key; //bien key co kieu so nguyen
	othertype otherfields; //bien otherfields co kieu so thuc
}recordtype;

 void swap(recordtype *x, recordtype *y){ 
 // ham swap hoan doi mau tin x va mau tin y cho nhau
 	recordtype temp; // su dung mau tin tam 
 	temp = *x; 
 	*x = *y;
 	*y = temp;
 }
void PushDown(recordtype a[ ], int first,int last){
//day first xuong
	int r= first;
	while (r <= (last-1)/2){ //r la nhung nuc co con last=n-1
		if (last == 2*r+1) { //chi co mot con trai
			if (a[r].key > a[last].key) swap(&a[r],&a[last]);
			r = last;
		} 
		else if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key)){
			swap(&a[r],&a[2*r+1]);
			r = 2*r+1 ;
		}
		 else if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key)){
			swap(&a[r],&a[2*r+2]);
			r = 2*r+2 ;
		}
		else
			r = last;
	}
}
void HeapSort(recordtype a[], int n){
	int i;
	for (i = (n-2)/2; i>=0; i--)
	PushDown(a, i, n-1);
	for (i = n-1; i>=2; i--) {
		swap(&a[0],&a[i]);
		PushDown(a, 0, i-1);
	}
	swap(&a[0],&a[1]);
}
void Read_Data(recordtype a[], int *n){
// Doc file txt va luu tru vao mang a[], xac dinh co bao nhieu phan tu luu vao bien n
	FILE *f; //khai bao bien tep tin f
	f=fopen("D:\\HocTap\\data1.txt", "r");
	int i=0; //ban dau i=0; dung de luu tru chi so
	if(f!=NULL){ 
		while(!feof(f)){ //neu chua toi cuoi tep tin
			fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
			//doc gia tri dau la so nguyen, gia tri hai so thuc
			i++;
		}
	} else printf("Loi mo file\n");
	fclose(f);
	*n=i; //bien n luu chi so dong cua i
}
void Print_Data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

int main(){
	recordtype a[20];
	int n;
	Read_Data(a,&n);
	printf("Du lieu ban dau: \n");
	Print_Data(a,n);
	//Ham heapsort
	HeapSort(a,n);
	printf("Ket qua sap xep heapsort: \n");
	Print_Data(a,n);
	printf("\n");
	return 0;
	
}
