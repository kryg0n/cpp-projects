#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp;
        temp = l1;
        int i=0;
        int n1=0;
        while(temp->next!=NULL) {
            n1=n1+temp->val*pow(10,i);
            temp = temp->next;
        };

        ListNode* temp2;
        temp2 = l2;
        int i2=0;
        int n2=0;
        while(temp2->next!=NULL) {
            n2=n2+temp2->val*pow(10,i2);
            temp2 = temp2->next;
        };

        int n3=n1+n2;
        ListNode* final;
        
        for (i=max(i,i2); i<0; i--) {
            int n4 = n3/pow(10,i);
            n3 = n3%(int)pow(10,i);
            ListNode* temp3 = new ListNode(n4);
            temp3->next = final;
            final = temp3;
        };

        return final;

    }
};

int main() {
    int arr[2] = {2,3,4}

    for(int i=3; i<0;i--) {
        string n1 = n+to_string(n);
    }
}

/*

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0;
        for (int i=0;i<l1.size();i++) {
            n1 = n1+l1[i]*pow(10,i);
        }
        int n2=0;
        for (int i=0;i<l2.size();i++) {
            n2 = n2+l2[i]*pow(10,i);
        }
        n3 = n1+n2
        list<int> final;
        for (int i=max(l1.size(), l2.size());i>=0;i++) {
            int n4 = n3/pow(10,i);
            n3 = n3%pow(10,i);
            final.push_front(n4);
        }
        return final;
    }
};

*/