#include <iostream>

using namespace std;

// Node for SLL
struct ListNode {
    int data;
    ListNode* next;

    //constructor/init
    ListNode(int val) : data(val), next(nullptr) {}
};