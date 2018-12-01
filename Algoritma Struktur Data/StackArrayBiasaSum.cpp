#include <iostream>
using namespace std;
#define Nil 0
#define MaxEl 20

typedef int infotype;
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
	int temp;
	while(TOP(S)!=Nil){
		POP(&S,&temp);
		cout << temp << endl;;
	}
}

int main (){
	stack S;
	CreateEmpty(&S);
	int n;//jumlah kasus
	int input; // Push data
	int sum=0; 
	cin >> n;
    for(int i=0; i<n; i++){
    	cin >> input;
    	sum = sum + input;
    	Push(&S, input);
	}
	PrintInfo(S);
	cout << sum;
    
    return 0;
}
