// Linked List Assignment #1   Spring 2018 
/*
Done:
ptr makeNode( int )
void printList( ptr )
ptr insertFront( ptr, int )
int listLength( ptr )
 
 
More Linked List for you to add
  -  purpose & behavior explained in class
 
int isEmpty( ptr )            1: if list is empty
int isInList( ptr, int )      1: if val is in list
ptr getLoc( ptr, int )        ptr to location of val
int maxVal( ptr )             largest value
ptr maxLoc( ptr )             location of largest value
 ret ptr to biggest val in list
ptr insertBack( ptr, int )    add value to end of list
 
ptr insertAfter( ptr, ptr, int )
                             add value to list after loc
 
ptr removeFront( ptr )        delete first item
ptr removeBack( ptr )         delete last item
ptr removeThisOne( ptr, ptr ) delete item at this loc
				(ptr) is first of the list
*/


#include <stdio.h>
#include <stdlib.h>

struct boxtype
{
	int val;
	struct boxtype *link;
};

struct boxtype *makeNode( int x ){

	struct boxtype *node;
	node=malloc(sizeof(struct boxtype));
	node->val=x;
	node->link=NULL;

return node;}

struct boxtype *removeFront(struct boxtype *start){

	struct boxtype *tmp=start;
	if(tmp!=NULL){
		start=start->link;
		free(tmp);
	}
return start;}
int listLength( struct boxtype *front ){

	struct boxtype *tmp;
	tmp=front;

	int count=0;
	while(tmp!=NULL){
		tmp=tmp->link;
		count++;
	}

return count;}

struct boxtype *removeThisOne(struct boxtype *start,struct boxtype *search){

	struct boxtype *mov=start;
	struct boxtype *after=search->link;

	if(start==search)
		start=search->link;
	else{
		//Goto one spot before the location of search, set box before search to point to after
		while(mov->link!=search)
			mov=mov->link;

		//while puts mov at box before search
		//point link of mov's box at box after search to remove item from chain
		mov->link=after;

	}

	free(search);

return start;}

struct boxtype *removeBack(struct boxtype *start){


	struct boxtype *mov=start;
	if(mov==NULL)
		start=NULL; //Should already be the case, but needed a statement in the if.
					//Also don't want to be checking for &&mov!=NULL in other statements.
	else if(mov->link==NULL)
		start=removeFront(start); //If it ain't broke, don't fix it
									//Otherwise I would have essentially coded removeFront
									//inside of this else if when I already have a functional function..
	else{
		struct boxtype *prev;
		while(mov->link!=NULL){
			prev=mov;
			mov=mov->link;
		}

		prev->link=NULL;
		free(mov);
	}


return start;}




struct boxtype *insertAfter(struct boxtype *start,struct boxtype *search, int x){
	struct boxtype *tmp=makeNode(x);

	tmp->link=search->link;
	search->link=tmp;

return start;}

struct boxtype *getLoc(struct boxtype *start,int val){

	struct boxtype *mov=start;

	while(mov!=NULL){
		if(mov->val==val)
			return mov;
		mov=mov->link;
	}

return NULL;}

struct boxtype *insertBack(struct boxtype *start, int x){

	struct boxtype *mov=start;
	struct boxtype *new=makeNode(x);

	if(start==NULL)
		start=new;

	else{
		while(mov->link!=NULL)
			mov=mov->link;

		mov->link=new;	
	}


return start;}

int maxVal(struct boxtype *start){

	if(start==NULL)
		exit(1);
	//DO NOT return any value, that may cause more issues. Just exit when this case is encountered.


	struct boxtype *mov=start;
	int max=mov->val; //Initialize to first item in list

	while(mov!=NULL){
		if(mov->val>max)
			max=mov->val;

		mov=mov->link;
	}

return max;}

struct boxtype *maxLoc(struct boxtype *start){

	struct boxtype *mov=NULL;
	if(start!=NULL){
		int max=maxVal(start);
		mov=getLoc(start,max);	
	}
	//Should never avoid if with valid list, if it does it would mean no items in list (start==NULL). 
	//Return start (which would be NULL) if there is an empty list.

return mov;}

int isInList(struct boxtype *start,int val){

	struct boxtype *mov=start;

	while(mov!=NULL){
		if(mov->val==val)
			return 1;
		mov=mov->link;
	}

return 0;}

int isEmpty(struct boxtype *start){

	if(start==NULL)
		return 1;

return 0;}

void printList( struct boxtype *front ){

	struct boxtype *mov;
	mov=front;
	printf("List: ");
	while(mov!=NULL){
		printf("%d ",mov->val);
		mov=mov->link;
	}
	printf("\n");
}


struct boxtype *insertFront( struct boxtype *first, int num ){

	struct boxtype *tmp;
	tmp=makeNode(num);
	tmp->link=first;

return tmp;}
/*
int main()
{
    struct boxtype *b, *start;
    int i, x;

    start = NULL;

    for ( i = 0; i < 10; ++i )
    {
        x = rand() % 100;
        if ( x % 2 == 0 )
            start = insertFront( start, x );
        else
            start = insertBack( start, x );
        printList( start );
    }
    printf("Len %d\n", listLength( start ) );


    while ( !isEmpty( start ) )
    {
        x = start->val;
        printf("%d\n", x);
        start = removeFront( start );
        printList( start );
    }


    while ( !isEmpty( start ) )
    {
        start = removeBack( start );
        printList( start );
    }


    int mv;
    struct boxtype *ml;
    while ( !isEmpty( start ) )
    {
        mv = maxVal( start );
        ml = maxLoc( start );
        printf("big  %d\n", mv );
        start = removeThisOne( start, ml );
        printList( start );
    }

    return 0;
}
*/
		//Main A

/*
int main()
{
    struct boxtype *one, *two;
    int i, x;

    one = NULL;
    two = NULL;

    for ( i = 0; i < 7; ++i )
    {
        x = rand() % 80 + 1;
        one = insertFront( one, x );
        two = insertBack( two, x );
    }

    int tot = 99;

    while ( !isEmpty( two ) )
    {
        x = two->val;
        tot += x%29;
        two = removeFront( two );
    }

    while ( !isEmpty( one ) )
    {
        x = one->val;
        tot += x%29;
        one = removeBack( one );
    }
    printf("%d\n", tot);

    return 0;
}
*/
		//Main B
/*
int main()
{
    struct boxtype *two;
    int i, x;

    two = NULL;

    for ( i = 0; i < 20; ++i )
    {
        x = rand() % 200 + 1;
        two = insertBack( two, x );
    }

    int tot = 99;
    int n = 11;

    int mv;
    struct boxtype *ml;
    while ( !isEmpty( two ) )
    {
        mv = maxVal( two );
        ml = maxLoc( two );
        if ( mv % 2 )
            tot = tot + mv + n;
        else
            tot = tot - mv + n;
        n++;
        two = removeThisOne( two, ml );
    }
    printf("%d\n", tot);
    return 0;
}
*/



		//Main C
/*
int main()
{
    struct boxtype *one, *two;
    struct boxtype *p, *q;
    int i, x=14;

    one = NULL;
    two = NULL;

    for ( i = 10; i <= 80; i+=10 )
    {
        one = insertFront( one, i );
        two = insertBack( two, i );
    }

    two = removeFront( two );
    two = removeBack( two );
    one = removeFront( one );
    one = removeBack( one );
    p = getLoc( one, 50 );
    q = getLoc( two, 50 );
    x += listLength( p );
    x += listLength( q );
    printf("%d\n", x);
    return 0;
}
*/


		//Main D


int main()
{
    struct boxtype *two;
    int i, x;

    two = NULL;

    srand(331);
    for ( i = 0; i < 9; ++i )
    {
        x = rand() % 200 + 1;
        printf("%d ", x);
        two = insertBack( two, x );
    }
    printf("\n");


    int mv;
    struct boxtype *ml;
    for ( i = 0; i < 2; ++i )
    {
        mv = maxVal( two );
        ml = maxLoc( two );
        printf("%d ", mv);
        two = removeThisOne( two, ml );
    }
    printf("\n");
    return 0;
}









/*

int main(){

	struct boxtype *b, *start;
	nt i, x;

	start = NULL; 

	b=makeNode(5);

	start=b;
	b =makeNode(20);

	b->link=start;

	start=b;

	printf("%d %d\n",start->val,start->link->val);


	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		if ( x % 2 == 0 )
			start = insertFront( start, x );
		else{
			start = insertBack( start, x );
			printf("Insert back %d\n",x);}
		printList( start );
	}
	printf("Len %d\n", listLength( start ) );


	while ( !isEmpty( start ) )
	{
		x = start->val;
		printf("Front %2d\n", x);
		start = removeFront( start );
		printList( start );
	}


	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		if ( x % 2 == 0 )
			start = insertFront( start, x );
		else{
			start = insertBack( start, x );
			printf("Insert back %d\n",x);}
		printList( start );
	}
	while ( !isEmpty( start ) )
	{
		start = removeBack( start );
		printList( start );
	}

	printf("remove back done\n");
	printf("%d\n",start);
	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		printf("%d\n",x);
		if ( x % 2 == 0 ){
			printf("insfront\n");
			start = insertFront( start, x );
		}else{
			printf("insback\n");
			start = insertBack( start, x );
		}
		printList( start );
	}
	printf("Insert done\n");
	int mv;
	struct boxtype *ml;
	while ( !isEmpty( start ) )
	{
		mv = maxVal( start );
		ml = maxLoc( start );
		printf("big  %d\n", mv );
		start = removeThisOne( start, ml );
		printList( start );   
	}
	x=rand()%100;
	start=insertFront(start,x);
	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		printf("%d\n",x);
		ml=maxLoc(start);
		start=insertAfter(start,ml,x);
		printList( start );
	}
	for ( i = 0; i < 10; ++i )
	{
		ml=maxLoc(start);
		start=removeThisOne(start,ml);
		printList( start );
	}
printf("Done\n");
	return 0;
}*/
