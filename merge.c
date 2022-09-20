/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * sort the list
 */
void sort(struct ListNode* head){
    struct ListNode* current;
    struct ListNode* temp;
    int swap;
    for(current = head ; current != NULL ; current = current->next){
        for(temp = current->next ; temp != NULL ; temp = temp->next){
            if(current->val > temp->val){
                swap = current->val;
                current->val = temp->val;
                temp->val = swap;
            }
        }
    }
}

/*
 * create new node and insert data 
 */
struct ListNode* newNode(int num){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = num;
    return node;
}

/* 
 ****** This is the function must called ******
 * the function take the lists and the number of lists and return one list containe all the lists number sorted
 * exemples are in the README.md file
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;
    int i,count = 0;
    for(i=0 ; i<listsSize ; i++){
        while(lists[i] != NULL){
            struct ListNode* temp = newNode(lists[i]->val);
            count++;
            if(head == NULL){
                head = temp;
                current = head;
                current->next = NULL;
            }
            else{
                temp->next = NULL;
                current->next = temp;
                current = current->next;
            }
            lists[i] = lists[i]->next;
        }
    }
    sort(head);
    return head;
}
