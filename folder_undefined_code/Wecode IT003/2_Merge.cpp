//Merge List
#include <bits/stdc++.h>

using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

struct SinglyLinkedList {
	SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
		this->head = nullptr;
        this->tail = nullptr;
    }

	void insert_node(int node_data);
};

void SinglyLinkedList::insert_node(int node_data)
{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
}



void print_singly_linked_list(SinglyLinkedListNode* node,char sep=' ') {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << '\n';
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){
   SinglyLinkedList *H3=new SinglyLinkedList();
    SinglyLinkedListNode*p1=head_list1; SinglyLinkedListNode*p2=head_list2;

    while(p1!=nullptr&&p2!=nullptr)
    {
        if(p1->data<=p2->data) {
            SinglyLinkedListNode* n= new SinglyLinkedListNode(p1->data);
            if(H3->head==nullptr) H3->head=n;
            else H3->tail->next=n;
            H3->tail=n;
            p1=p1->next;}
        else if(p2->data<=p1->data) {
            SinglyLinkedListNode* n= new SinglyLinkedListNode(p2->data);
        if(H3->head==nullptr) H3->head=n;
            else H3->tail->next=n;
            H3->tail=n;
            p2=p2->next;
            }
    }
    while(p1!=nullptr)
    {
       SinglyLinkedListNode* n= new SinglyLinkedListNode(p1->data);
            if(H3->head==nullptr) H3->head=n;
            else H3->tail->next=n;
            H3->tail=n;
            p1=p1->next;
    }
    while(p2!=nullptr)
    {
       SinglyLinkedListNode* n= new SinglyLinkedListNode(p2->data);
        if(H3->head==nullptr) H3->head=n;
            else H3->tail->next=n;
            H3->tail=n;
            p2=p2->next;
    }
     return H3->head;
}



int main (){
    cin.tie(0); std::ios::sync_with_stdio(false);
    
    int tests;
    cin >> tests;
    
    
    
    
    for (int t = 0; t < tests; t++){
		int llist1_num, llist2_num;
		cin >> llist1_num >> llist2_num;
		
		SinglyLinkedList* llist1 = new SinglyLinkedList();
		
		
		for (int i = 0; i < llist1_num; i++){
			int llist1_item;
			cin >> llist1_item;
			
			llist1->insert_node(llist1_item);
		}
		
		SinglyLinkedList* llist2 = new SinglyLinkedList();

		
		for (int i = 0; i < llist2_num; i++){
			int llist2_item;
			cin >> llist2_item;
			
			llist2->insert_node(llist2_item);
		}
		
		SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
		
		print_singly_linked_list(llist3);
		
		free_singly_linked_list(llist3);
		
		
	}
}
