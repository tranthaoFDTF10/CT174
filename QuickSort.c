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
 //Ham tim chot
int FindPivot(recordtype a[], int i,int j){
	keytype firstkey; //gia tri khoa
	int k; //k la mot bien de chay so sanh
	k = i+1;// luc dau cho k vi tri thu 1
	firstkey = a[i].key; // khoa duoc gan cho phan tu a[0]
	while ( (k <= j) && (a[k].key == firstkey) ) k++; //k chay tu a[1] neu bang thi k++
	if (k > j) return -1; //neu k>j khong tim thay phan tu nao lon hon no thi dung
	else{
		if (a[k].key>firstkey) return k; //neu a[k] > phan tu tu khoa tra ve phan tu tai vi tri k
		else return i; //nguoc lai tra ve phan tu tai vi tri i
	}
}
//Ham tim 
int Partition(recordtype a[], int i, int j, keytype pivot){
//Phan hoach mang a theo chi so i,j va chot
	int L, R;
	L = i; //chi so ben trai bat dau tu 0
	R = j; //chi so ben phai bat dau tu n-1
	while(L<=R){
		while(a[L].key < pivot) L++; //phan tu tai vi tri L < chot thi L++
		while(a[R].key >=pivot) R--; //phan tu tai vi tri R >= chot thi R--
		if(L<R) swap(&a[L],&a[R]); //Neu L< R hoan doi
	}
	return L;
}
void QuickSort(recordtype a[], int i, int j){
	keytype pivot;// chot
	int pivotindex, k;//pivotindex la chi so chot, k la chi so phan hoach
	pivotindex = FindPivot(a,i,j); //tim vi tri cua chot
	if(pivotindex!=-1){
		pivot=a[pivotindex].key;// chot=khoa cua phan tu a co chi so cua chot
		k=Partition(a,i,j,pivot);// tien hanh phan hoach mang a sau khi tim thay chot
		QuickSort(a,i,k-1); //de quy sap xep mang con ben trai
		QuickSort(a,k,j);//de quy sap xep mang con ben phai
	}
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
	
	QuickSort(a,0,n-1);
	printf("Ket qua sap xep QuickSort la: \n");
	Print_Data(a,n);
	printf("\n");
	return 0;
}
