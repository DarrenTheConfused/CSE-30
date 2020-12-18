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


bool find(string word, ResizableArray& arr){
    for (long i = 0; i < arr.count; i++){
        if (word == arr[i]){
            return true;
        }
    }
    return false;
}

long f(string s){
    while (s.length() < 4){
        s += ' ';
    }

    return s[0]*pow(128, 3) + s[1]*pow(128, 2) + s[2]*128 + s[3];
}

void insert(string word, LinkedList* table){
    long index = f(word);
    table[index].append(word);
}

bool find(string word, LinkedList* table){
    long index = f(word);
    return table[index].search(word);
}

int main(){

    const long N = 10;

    fstream file;

    ResizableArray words;
    LinkedList* table = new LinkedList[N];

    file.open("words3.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){
            words.append(tp);
            insert(tp, table);
        }
        file.close();
    }
    else{
        cout << "Could not read file..." << endl;
    }

    timestamp start = current_time();

    int count = 0;
    for (long i = 0; i < words.count; i++){
        // if (reverse(words[i]) ==  words[i]){
        string rev = reverse(words[i]);
        if (find(rev, words)){
            //cout << words[i] << endl;
            count++;
        }
    }

    timestamp end = current_time();

    long diff = time_diff(start, end);

    cout << "There were " << count << " words that match. It took " << diff << " .ms" << endl;

    return 0;
}




















