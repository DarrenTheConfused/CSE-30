// #include <iostream>
// #include <Array.h>
// #include <LinkedList.h>

// using namespace std;

#include <iostream>
#include <RandomSupport.h>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>

using namespace std;

//get linkedList value from index
int get(Node* head, int positionTail){
    if(head == NULL){
        return -1;
    }
    int counter = 0;
    int forward = 0;
    Node* temp = head;
    Node* node = head;

    while(temp->next != NULL){
        forward++;
        temp = temp->next;
        if(forward - counter > positionTail){
            node = node->next;
            counter++;
        }
    }

    return node->data;

}

void push(Node** head, long num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = (*head);
    (*head) = newNode;
}


int main(int argc, char* argv[]){

	randomizer device = new_randomizer();
	uniform_distribution dist = new_distribution(1, 10);

	long size = 1000;
	long index = sample(dist, device);
    long zero = 0;
    long last = size - 1;
    long r2 = sample(dist, device);
	cout << "Size of Array:                  "  << size << endl;
    cout << "Size of Linked List:            "  << size << endl;
	cout << "Random index number is:         " << index << endl << endl;

	LinkedList linkedList;
	ResizableArray array;
    LinkedList* pointer = &linkedList;
    Node* temp = pointer->head;
    Node** H = &temp;

	for (long i = 0; i < size; i++){
		long r = sample(dist, device);
		linkedList.append(r);
		array.append(r);
	}
    long answer = 5;
    cout << "Please pick a function" << endl << endl;
    cout << "1. Random Access" << endl;
    cout << "2. Insert at beginning" << endl;
    cout << "3. Insert at the end" << endl;
    cin >> answer;

    long duration1 = 0;
    long duration2 = 0;
    long x = 0;
    long y = 0;

    if(answer == 1){
        //start time
	    timestamp start1 = current_time();
        x = linkedList.get(temp, index);
        timestamp end1 = current_time();
        duration1 = time_diff(start1, end1);
        
        timestamp start2 = current_time();
        y = array.get(index);
	    //end time
	    timestamp end2 = current_time();
        duration2 = time_diff(start2, end2);
    }
    if(answer == 2){ 
        //start time
	    timestamp start1 = current_time();
        linkedList.prepend(r2);
        timestamp end1 = current_time();
        duration1 = time_diff(start1, end1);

        timestamp start2 = current_time();
        array.insert(0, r2);
	    //end time
	    timestamp end2 = current_time();
        duration2 = time_diff(start2, end2);
    }
    if(answer == 3){   
        //start time
	    timestamp start1 = current_time();
        linkedList.append(r2);
        timestamp end1 = current_time();
        duration1 = time_diff(start1, end1);

        timestamp start2 = current_time();
        array.append(r2);
        timestamp end2 = current_time();
        duration2 = time_diff(start2, end2);
	    //end time
    }
    else{
        cout << "You didn't answer correctly..." << endl;
        cout << "Running function 1..." << endl << endl;
        //start time
	    timestamp start1 = current_time();
        linkedList.get(temp, index);
        timestamp end1 = current_time();
        duration1 = time_diff(start1, end1);
        
        timestamp start2 = current_time();
        array.get(index);
	    //end time
	    timestamp end2 = current_time();
        duration2 = time_diff(start2, end2);
    }

	
	
	//display duration
	cout << "Total time taken for linkedList:               " << duration1 << " ms." << endl;
    cout << "Total time taken for Array:                    " << duration2 << " ms." << endl;
	cout << "Value obtained from get(index) of LinkedList: " << x << endl;
    cout << "Value obtained from get(index) of Array:      " << y << endl;
    cout << "Value inserted in linkedList:   " << r2 << endl;
    cout << "Value inserted in array:        " << r2 << endl;

	//print elements
	// cout << "Linked List: " << linkedList << endl;
	// cout << "Array:       " << array << endl;

	return 0;
}














// int main(){
    // Your code here...
//    cout<<"this is a test"<<endl;
//   return 0;
// }
