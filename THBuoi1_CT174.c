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
 void SelectionSort(recordtype a[], int n){ //sap xep chon
 	int i,j, lowindex; //lowindex luu tru vi tri khoa
 	keytype lowkey; //lowkey luu tru phan tu khoa
 	for(i=0;i<=n-2;i++){ //chay tu vi tri dau den vi tri n-2
 		lowkey=a[i].key; // gan khoa cho phan tu i (i=0)
 		lowindex=i; // gan vi tri cua phan tu i
 		for(j=i+1;j<=n-1;j++){ //chay kiem tra nhung phan tu phia sau cua i
 			if(a[j].key<lowkey){ //neu phan tu j < phan tu i
 				lowkey=a[j].key; //cap nhat khoa cho j
 				lowindex=j; //cap nhat khoa cho i
			 }
		}
		swap(&a[i],&a[lowindex]); // hoan doi
	 }
 }
 void InsertionSort(recordtype a[], int n){ //sap xep xen
	int i,j;
	//xem a[0] da co thu tu nen kh xet a[0]
	for(i=1; i<=n-1; i++){
		j=i; //bat dau xet tai vi tri 1
		while ((j>0)&&(a[j].key<a[j-1].key)) {
		// neu phan tu tai a[j] nho hon phan tu dung truoc no thi moi hoan doi
			swap(&a[j],&a[j-1]);
			j--;
		}
	}
} 
void BubbleSort(recordtype a[], int n){ //sap xep noi bot
 	int i,j;
 	for(i=0;i<=n-2;i++){ //chay tu vi tri dau den n-2 phan tu
 		for(j=n-1;j>=i+1;j--){ // bat dau chay tu vi tri cuoi
 			if(a[j].key<a[j-1].key){ // neu phan tu j < phan tu sau truoc no thi hoan doi 
 				swap(&a[j],&a[j-1]);
			 }
		 }
	 }
 }

void Read_Data(recordtype a[], int *n){
// Doc file txt va luu tru vao mang a[], xac dinh co bao nhieu phan tu luu vao bien n
	FILE *f; //khai bao bien tep tin f
	f=fopen("D:\\HocTap\\data.txt", "r");
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
	//Sap xep chon
	SelectionSort(a,n);
	printf("Ket qua sap xep chon: \n");
	Print_Data(a,n);
	printf("\n");
	//Sap xep xen
	InsertionSort(a,n);
	printf("Ket qua sap xep xen: \n");
	Print_Data(a,n);
	printf("\n");
	//Sap xep noi bot
	BubbleSort(a,n);
	printf("Ket qua sap xep noi bot: \n");
	Print_Data(a,n);
	return 0;
	
}
