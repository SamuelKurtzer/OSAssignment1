/**
 *student: Samuel Desmond Kurtzer
 *ID:A1687068
 *project was completed alone.
 *
 **/
#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false !true

typedef struct _process{
	char* ID;
	int init;
	int age;
	int priority;
	int cpu;
	int numOfTimesServiced;
}process;

typedef struct _node{
	struct _node* next;
	struct _node* prev;
	process* data;
	//for accessability
	int priority;
}node;

process initProcess(char* ID, int init, int age, int priority, int cpu){
	process temp;
	temp.ID = ID;
	temp.init=init;
	temp.age=age;
	temp.priority=priority;
	temp.cpu=cpu;
	temp.numOfTimesServiced=0;
	return temp;
}

node initNode(process* d){
	node temp;
	temp.next=NULL;
	temp.data=d;
	temp.prev=NULL;
	temp.priority=d->priority;
	return temp;
}

typedef struct _ll{
	node* head;
	node* ageHead;
	node* ageTail;
	node* tail;
}ll;

ll initList(){
	ll temp;
	temp.head=NULL;
	temp.ageHead=NULL;
	temp.ageTail=NULL;
	temp.tail=NULL;
	return temp;
}

void add(ll* list, node* addee){
	if(list->head==NULL){
		list->head=addee;
	}else if(list->tail==NULL){
		list->tail=addee;
		list->tail->next=list->head;
		list->tail->prev=list->head;
		list->head->next=list->tail;
		list->head->prev=list->tail;
	}else{
		list->tail->next=addee;
		addee->next=list->head;
		addee->prev=list->tail;
		list->tail=addee;
	}
}

void rotate(ll* list){
	list->tail=list->head;
	list->head=list->head->next;
}

process removeNode(ll* list, node* toDelete){
	node* walker=list->head;
	process* ret;
	if(list->head==toDelete){
		list->head=list->head->next;
		list->tail->next=list->head;
		walker->next=NULL;
		ret=walker->data;
	}else if(list->tail==toDelete){
		node* next=list->tail->next;
		node* prev=list->tail->prev;
		next->prev=prev;
		prev->next=next;
		walker->next=NULL;
		walker->prev=NULL;
		ret=walker->data;
	}
	else{
		node* forwards=toDelete->next;
		node* backwards=toDelete->prev;
		forwards->prev=backwards;
		backwards->prev=forwards;
		walker->next=NULL;
		walker->prev=NULL;
		ret=walker->data;
	}
	return *ret;
}


int main(int argc, char* argv[]){
	
	//queue init
	ll queue1=initList();
	ll queue2=initList();
	ll queue3=initList();
	ll queue4=initList();

	
	//get code here
	int tick = 0;
	process arr[100];
	ll* currentList;
	int nextTimeToAdd=arr[0].init;
	int currentNodeVal=0
	while(true){
		if(nextTimeToAdd==tick){
			//add new processes here
			while(arr[currentNodeVal]==tick){
				node temp=initNode();

			}
			//also check if new processes need to be the currently running nodes.
		}
		//increment the current process.
		
		//check if the current process needs to be moved to the back of the line or demoted to another queue.
		//queue 1 runs are 5  ticks and priority is reduced
		//queue 2 runs are 10 ticks long and needs their priority reduced by one every 2 runs or 20 cycles.
		//queue 3 runs are 20 ticks


		//promote processes
		tick++;
	}
    return 0;
}
