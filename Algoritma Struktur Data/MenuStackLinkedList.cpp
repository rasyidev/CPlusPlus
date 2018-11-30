#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtStack *address;
typedef struct TElmtStack{
    infotype info;
    address next;
} ElmtStack;

typedef struct stack {
    address top;
};

bool IsEmpty(stack s) {
    return ((s).top == NULL);
}

void CreateEmpty(stack *s) {
    (*s).top = NULL;
}

address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtStack*) malloc (sizeof(ElmtStack));

    NewElmt->info = x;
    NewElmt->next = NULL;

    return NewElmt;
}

void Deallocation(address hapus) {
    free(hapus);
}

void push(stack *s, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);

    if (NewElmt != NULL) {
        NewElmt->next = (*s).top;
        (*s).top = NewElmt;
    }
}


void pop(stack *s, infotype *hapus) {
    if (!IsEmpty(*s)) {
        address temp;
        temp = (*s).top;
        *hapus = temp->info;
        (*s).top = (*s).top->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}

void print(stack s){
	if(IsEmpty(s)){
		cout << "Tumpukan Kosong";
	}else{
		address temp;
		temp = (s).top;
    	while (temp != NULL) {
        	cout << temp->info<<" ";
	        temp = temp->next;
   		}
	}
	cout<<endl<<endl;
}

int main() {
    stack s;
    CreateEmpty(&s);
	
	int pilih, input;
	
	do{
		print(s);
		cout <<"-----------------\n";
		cout<<"| 1. Push data  |"<<endl;
		cout<<"| 2. Pop data   |"<<endl;
		cout<<"| 3. Clear      |"<<endl;
		cout<<"| 4. Exit       |"<<endl;
		cout <<"-----------------\n";
		cout<<endl;
		
		cout<<"Pilih	: ";
		cin>>pilih;
		
		system("CLS");
		
		switch(pilih){
			case 1 : {
				print(s);
				cout <<"-----------------\n";
				cout<<"| 1. Push data  |"<<endl;
				cout<<"| 2. Pop data   |"<<endl;
				cout<<"| 3. Clear      |"<<endl;
				cout<<"| 4. Exit       |"<<endl;
				cout <<"-----------------\n";
				cout<<endl;
					cout<<"Push	: ";
					cin>>input;
					push(&s, input);
					system("CLS");
					//print(s);
					break;
			}
			case 2 : {
				if(!IsEmpty(s)){
					int ambil;
					pop(&s, &ambil);
				}
				break;
			}
			case 3 : {
				CreateEmpty(&s);
				break;
			}
		}
		
	}while(pilih >= 1 && pilih <=3);
	
}

