#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <BST.h>
#include <cmath>

using namespace std;

string reverse(string word){
    reverse(word.begin(), word.end());
    return word;
}


const long N = 1000000;
LinkedList* table = new LinkedList[N];


bool find(string word, ResizableArray& arr){
    for (long i = 0; i < arr.count; i++){
        if (word == arr[i]){
            return true;
        }
    }
    return false;
}

long f(string s){

    //long i = 0; i < s.length(); i++
    /*
    long t = 0;
    long i = 0;
    for(long j = 0; j < s.length() + 1; j++){
        if(i != 0){
            t += s[j]*pow(128, (s.length() - (i)));
            i++;
        }
        else{
            t += s[j]*pow(128, (s.length() - (i)));
            i++;
        }
    }
    */

    while (s.length() < 4){
        s += ' ';
    }
    long k = s[0]*pow(128, 3) + s[1]*pow(128, 2) + s[2]*128 + s[3];
    return (k % N);
}

void insert(string w, LinkedList* list){
    long index = f(w);
    list->append(w);
}

bool find(string w, LinkedList* list){
    long index = f(w);
    return list->search(w);
}


Node* getNode(long pos,string data){ 
    // allocating space 
    Node* newNode = new Node(); 
  
    // inserting the required data 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
}

// function to insert a Node at required position 
void insertPos(Node** current, long pos, string data) { 
    // This condition to check whether the 
    // position given is valid or not.
    long size = N; 
    if (pos < 1 || pos > size + 1){
        cout << "Invalid position!" << endl;
    }
    else { 
  
        // Keep looping until the pos is zero 
        while (pos--) { 
  
            if (pos == 0) { 
  
                // adding Node at required position 
                Node* temp = getNode(pos, data); 
  
                // Making the new Node to point to  
                // the old Node at the same position 
                temp->next = *current; 
  
                // Changing the pointer of the Node previous  
                // to the old Node to point to the new Node 
                *current = temp; 
            } 
            else
              // Assign double pointer variable to point to the  
              // pointer pointing to the address of next Node  
              current = &(*current)->next; 
        } 
        size++; 
    } 
}


bool binarySearch(ResizableArray arr, string word) {
    int lower = 0;
    int upper = arr.count - 1;
    int mid = (lower + upper)/2;
    if (lower <= upper) {
        mid = (lower + upper)/2;
        if (arr[mid].compare(word) < 0){
            lower = mid + 1;
        }
        else if (arr[mid].compare(word) > 0){
            upper = mid - 1;
        }
        else {
            return true;
        }
    }
   return false;
}

/*
void sort(ResizableArray arr){
    string temp;
    int n = arr.count - 1;
    for(int i=0;i<n;i++){
        for(int j = 1; j < n-i; j++){
            if(arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
*/

bool comparator(string a,string b)
{
    return a<b;
}


    void sort(ResizableArray arr){
        string temp;
        int n = arr.count - 1;
        for(int i=0;i<n;i++){
            for(int j = 1; j < n-i; j++){
                if(arr[j - 1] > arr[j]) {
                    temp = arr[j - 1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }


int main(){

    //const long N = 1000000;

    fstream file;

    ResizableArray words;
    ResizableArray reverseWords;
    //LinkedList* table = new LinkedList[N];

    // string bruh = "BRUH";
    // insert(bruh, table);

    long i = 0;

    file.open("words3.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){
            insert(tp, table); // Segmentation fault/error thing

            /* 
            if(i == 0){
                table->head = getNode(f(tp), tp);
                table->append(getNode(f(tp), tp)->data);
                //insertPos(&table->head, f(tp), tp);
            }
            else{
                table->head->next = getNode(f(tp), tp);
                table->append(getNode(f(tp), tp)->data);
                //insertPos(&table->head->next, f(tp), tp);
            }
            i++;
            */

            words.append(tp);
            reverseWords.append(reverse(tp));
        }
        file.close();
    }
    else{
        cout << "Could not read file..." << endl;
    }



    sort(reverseWords);
    sort(words);
    timestamp start = current_time();

    int count = 0;
    
    for (Node* n = table->head; n->next != NULL; n = n->next){
        string rev = reverse(n->data);
        if (find(rev, table)){
            count++;
        }
    }
    
   int lower = 0;
   int upper = reverseWords.count - 1;

    /*  
    for (long i = 0; i < words.count; i++){
        string rev = reverse(words[i]);
        if (binarySearch(words, rev)){
            count++;
        }
    }
    */

    timestamp end = current_time();
    long diff = time_diff(start, end);



    cout << "There were " << count << " words that match. It took " << diff << " .ms" << endl;

    return 0;

    
}




















