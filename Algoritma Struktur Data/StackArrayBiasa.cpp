#include <iostream>
using namespace std;
#define Nil -1
#define MaxEl 20

typedef char infotype;
typedef int address;
typedef struct{
    infotype Data[MaxEl];
    address TOP;
}stack;
#define TOP(S) (S).TOP
#define InfoTop(S) (S).Data[(S).TOP]

void CreateEmpty(stack *S){
    TOP(*S)= Nil;
}

bool IsEmpty (stack S){
    return (TOP(S)==Nil);
}

bool IsFull(stack S){
    return (TOP(S)==MaxEl);
}

void Push(stack *S, infotype x){
    if(!IsFull(*S)){
        TOP(*S)= TOP(*S)+1;
        InfoTop(*S) = x;
    }
}

void POP(stack *S, infotype *x){
    if(!IsEmpty(*S)){
        *x= InfoTop(*S);
        TOP(*S) = TOP(*S)-1;
    }
}

void PrintInfo(stack S){
	for(int i=0; i<TOP(S)+1; i++){
		cout << S.Data[i] << " ";
	}
}

int main (){
	int n;//jumlah kasus
	cin >> n;
    stack S[n];
    string kata;
    char hapus; // menyimpan nilai sebelum setelah dipop
    for(int i=0; i<n; i++){
    	CreateEmpty(&S[i]);
    	cin >> kata;
    	for(int j=0; j<kata.length(); j++){
    		switch(kata[j]){
    			case '1': Push(&S[i], kata[j]); break;
    			case '2': Push(&S[i], kata[j]); break;
    			case '3': Push(&S[i], kata[j]); break;
    			case '4': Push(&S[i], kata[j]); break;
    			case '5': Push(&S[i], kata[j]); break;
    			case '6': Push(&S[i], kata[j]); break;
    			case '7': Push(&S[i], kata[j]); break;
    			case '8': Push(&S[i], kata[j]); break;
    			case '9': Push(&S[i], kata[j]); break;
    			case '0': Push(&S[i], kata[j]); break;
    			case '_': POP(&S[i], &hapus); break;
			}
		}
	}
	
	for(int k=0; k<n; k++){
		PrintInfo(S[k]);
		cout << endl;
	}
    
    return 0;
}
