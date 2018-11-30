#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int infotype;
typedef struct TElmtStack *address;
typedef struct TElmtStack{
	infotype Info;
	address Next;
}ElmtStack;

typedef struct{
	address Head;
	address Tail;
}Queue;

// Selector

#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define InfoHead(Q) (Q).Head->Info
#define InfoTail(Q) (Q).Tail->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

address Allocation(infotype x){
	address P;
	P = (ElmtStack*)malloc(sizeof(ElmtStack));
	Info(P) = x;
	Next(P) = NULL;
	return P;
}

address Dealocation(address P){
	free(P);
}

bool IsEmpty(Queue Q){
	return (Head(Q) == NULL && Tail(Q) == NULL);
}

void CreateEmpty(Queue *Q){
	Head(*Q) = NULL;
	Tail(*Q) = NULL;
}

void Add(Queue *Q, infotype x){
	address P;
	P = Allocation(x);

	if(IsEmpty(*Q)){
		Head(*Q) = P;
		Tail(*Q) = P;
		//cout << "kosong";
	}else{
		Next(P) = Head(*Q);
		Head(*Q) = P;
	}
}

void Del(Queue *Q, infotype *X){
	if(!IsEmpty(*Q)){
		address temp = Tail(*Q);		
		*X = InfoTail(*Q);
		if(Next(Head(*Q)) == NULL){
			Head(*Q) = NULL;
			Tail(*Q) = NULL;
		}else{
			address prev = Head(*Q);
			while(Next(prev) != Tail(*Q)){
				prev = Next(prev);
			}
			Tail(*Q) = prev;
			Next(Tail(*Q)) = NULL;
		}
		Next(temp) = NULL;
		Dealocation(temp);
	}
}

void PrintInfo(Queue Q){
	if(IsEmpty(Q)){
		cout << "Antrian Kosong";
	}else{
		address Last = Head(Q);
		while(Last!=NULL){
			cout << Info(Last) << " ";
			Last = Next(Last);
		}
	}
}
int main() {
    Queue Q;
    CreateEmpty(&Q);
	
	int pilih, input;
	
	do{
		cout<<endl;
		cout <<"-----------------\n";
		cout<<"| 1. Add data   |"<<endl;
		cout<<"| 2. Del data   |"<<endl;
		cout<<"| 3. Clear      |"<<endl;
		cout<<"| 4. Exit       |"<<endl;
		cout <<"-----------------\n";
		cout<<endl;
		
		cout<<"Pilih	: ";
		cin>>pilih;
		
		system("CLS");
		
		switch(pilih){
			case 1 : {
				PrintInfo(Q);
				cout << endl;
				cout <<"-----------------\n";
				cout<<"| 1. Add data   |"<<endl;
				cout<<"| 2. Del data   |"<<endl;
				cout<<"| 3. Clear      |"<<endl;
				cout<<"| 4. Exit       |"<<endl;
				cout <<"-----------------\n";
				cout<<endl;

				cout<<"Add 	: ";

				cin>>input;
				system("CLS");
				Add(&Q, input);
				PrintInfo(Q);
				break;
				
			}
			case 2 : {
				if(!IsEmpty(Q)){
					int ambil;
					Del(&Q, &ambil);
					//cout<<endl;
				}
				PrintInfo(Q);
				break;
			}		
			case 3 : {
				CreateEmpty(&Q);
				PrintInfo(Q);
				break;
			}
		}
		
	}while(pilih >= 1 && pilih <=3);
	
}

