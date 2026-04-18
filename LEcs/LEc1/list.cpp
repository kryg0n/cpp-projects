#include <iostream>
#include <string>

using namespace std;

// first define a node
class ListNode {

    private:
        // node struct
        int data;
        ListNode* next;

    public:
        //constructor that only takes in data
        ListNode (int);
        //constructor that takes in both
        ListNode (int, ListNode*);

        // to get the ppointer to next node since it is private
        ListNode* get_Next() {
            return next;
        };
        // GEt data
        int get_Data() {
            return data;
        };
};

//now we make a list
class List {
    private:
        //Potinter to the first node
        ListNode* first;
        //name of the list like an label
        string name;
    public:
        //constructor to create list with a name
        List(string);
        //constructor to init a list without name
        List();

        // Count a list
        //start at first until you find a nullptr
        int Count() {
            //number to store the count
            int result=0;
            //make a temp Lost NOde pointer ans store pointer to first in it
            ListNode* temp=first;
            //loop over the list till nullptr
            while (temp!=NULL){
                result++;
                //update temp to now store the pointer of the next node
                temp=temp->get_Next();
            };
            //return our count
            return result;
        };

        //print a list
        //print the first continue till nullptr
        void Print(){
            //make a temp node pointer and save first in it
            ListNode* temp=first;
            while (temp!=NULL) {
                //print node data
                cout<<temp->get_Data();
                //make the temp node ptr into next
                temp=temp->get_Next();
            }

        }


        //simple search a list
        //check if the value is equal to the node data
        ListNode* Search(int val){
            //make a temp node pointer and save first in it
            ListNode* temp=first;
            //traverse till nullptr
            while (temp!=NULL) {
                //check if the data is same as val
                if (temp->get_Data()==val) {
                    return temp;
                };
                //move onto next
                temp=temp->get_Next();
            }
            return NULL;
        }

        //excercise
        //there are M nodes and N is passed, find data in nth node from the end, if no n print -1
        int findNfromEnd(int n){
            
        }

};