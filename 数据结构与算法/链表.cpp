#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

//增
void add(ListNode* head, ListNode* p, int index){
    ListNode* root = head;
    for(int i = 0; i < index - 1; i ++){
        root = root->next;
    }
    p->next = root->next; 
    root->next = p;
}

//删
void remove(ListNode* head, int index){
    ListNode* root = head;
    for(int i = 0; i < index - 1; i++){
        root = root->next;
    }
    if(root->next == nullptr){
        return;
    }
    ListNode* node = root->next;
    root->next = node->next;
    delete node;
}

//访问
ListNode* access(ListNode* head, int index){
    ListNode* root = head;
    for(int i = 0; i < index ; i++){
        if(root == nullptr){
            return nullptr;
        }
        root = root->next;
    }
    return root;
}

//查
int find(ListNode* head, int val){
    int index = 0;
    while(head != nullptr){
        if(head->val == val){
            return index;
        }
        head = head->next;
        index ++;
    }
    return -1;
}


int main(){
    //初始化链表
    // 1 -> 2 -> 3 -> 5 -> 4
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode* head = n1;
    while(head != nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
    printf("\n");

    ListNode* head2 = n1;
    add(head2, new ListNode(8), 3);
    while(head2 != nullptr){
        cout<<head2->val<<"->";
        head2 = head2->next;
    }
    printf("\n");

    ListNode* head3 = n1;
    remove(head3, 2);
    while(head3 != nullptr){
        cout<<head3->val<<"->";
        head3 = head3->next;
    }
    printf("\n");

    ListNode* head4 = n1;
    ListNode* node = access(head4, 4);
    cout<<node->val<<"\n";

    ListNode* head5 = n1;
    cout<<find(head5, 8);

}