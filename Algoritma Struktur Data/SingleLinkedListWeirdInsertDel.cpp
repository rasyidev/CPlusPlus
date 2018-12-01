#include <iostream>
#include <stdlib.h>
using namespace std;
// Setiap nama variabel menggunakan huruf kecil pada kata pertama dilanjutkan huruf besar untuk kata selanjutnya.

#define First(L) (L).first
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Nil NULL

typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList {
infotype info;
address next;
} ElmtList;

typedef struct {
    address first;
} List;

void CreateEmpty(List *L) {
    (*L).first = NULL;
}

bool IsEmpty(List L) {
    return ((L).first == NULL);
}

address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->info = x;
    NewElmt->next = NULL;
    return NewElmt;
}

void Deallocation(address hapus) {
    free(hapus);
}

void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        NewElmt->next = (*L).first;
        (*L).first = NewElmt;
    }
}

void InsertAfter(address *PredElmt, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        NewElmt->next = (*PredElmt)->next;
        (*PredElmt)->next = NewElmt;
        }
}

void InsertLast(List *L, infotype x) {
    if (IsEmpty(*L)) {
        InsertFirst(&(*L), x);
    } else {
        address temp;
        temp = (*L).first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        InsertAfter(&temp, x);
    }
}

void DeleteFirst(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp;
        temp = (*L).first;
        *hapus = temp->info;
        (*L).first = (*L).first->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}

void DeleteAfter(address pred, infotype *hapus) {
    if (pred->next != NULL) {
        address temp;
        temp = pred->next;
        *hapus = temp->info;
        pred->next = temp->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}

void DeleteLast(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;

    while (temp->next != NULL) {
        predTemp = temp;
        temp = temp->next;
    }
    if (temp == (*L).first) {
        DeleteFirst(&(*L), &(*hapus));
    } else {
        DeleteAfter(predTemp, &(*hapus));
    }
    }
}

void print (List L){
    address temp = (L).first;
    cout <<"[";
    while (Next(temp) != NULL) {
        cout << Info(temp)<< ", ";
        temp = Next(temp);
    }
    cout << Info(temp) <<"]";
}

int main (){
	List L;
	CreateEmpty(&L);
	int n; // banyaknya bilangan
	int x; // input bilangan
	int hapus; // menyimpan sementara nilai sebelum dihapus
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		InsertLast(&L, x);
	}
	address P = First(L);
	while (P!=Nil){
		if(Info(P)%2==0){
			DeleteFirst(&L, &hapus);
		}
		else if(Info(P)%3==0){
			DeleteLast(&L, &hapus);
		}
		P = Next(P);
	}
	
	print(L);

}
