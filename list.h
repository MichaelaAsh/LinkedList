/*==============================================================================*/
typedef struct NODE{
 int value;
 double key1;
 double key2;

 struct NODE* next;
 struct NODE* sort1;
 struct NODE* sort2;
 } Node;
/*==============================================================================*/
double rand_d (double b, double a) {

   double rand_num = ((double) rand() / (double) RAND_MAX) * ((b - a ) + a);
   return rand_num;

}
 /*==============================================================================*/
Node *create_list (int max_nodes) {

  int i = 0;

  Node *head = NULL;
  Node *temp = NULL;


  for (i = 0; i < max_nodes; i++) {
    /* create individual node*/
    temp = malloc(sizeof(Node));

    temp -> value = rand()%11;
    temp -> key1  =  rand_d (50.0, 10.0);
    temp -> key2  = rand_d(90.0, 10.0);
    temp -> next = NULL;

    if (head == NULL) {
      head = temp;
    } else {

      if ( head != NULL) {
        temp -> next = head;
        head = temp;
      }

    }

  } /* end of for loop */

  return head;

}

/*==============================================================================*/
void display_list (Node *head) {

  Node *node = head;

  while ( node != NULL) {
    printf("%2d, %.2f, %.2f\n", node -> value, node -> key1, node -> key2 );
    node  = node -> next;
  }

}
/*==============================================================================*/
Node *ascend_sort1(Node *og_link){

	if(og_link == NULL){
		return NULL;
	}

	Node * sort1_head = og_link;
	Node *temp = og_link -> next;

	while(temp != NULL){
		Node * p1 = sort1_head;
		Node *p2 = sort1_head-> sort1;

		/*if the next is smaller than the current number, the new min is now the next number*/
		if(temp -> key1 <= sort1_head -> key1){
			Node * newMin = temp;
			temp->sort1=sort1_head;
			sort1_head = newMin;
		}else{
			/*p2 not null, p1(current one) lt temp , p2(next one) lt temp*/
			while(p2!=NULL   &&    p1->key1 < temp->key1   &&   p2->key1 <= temp->key1){
				p1 = p1 -> sort1;
				p2 = p2 -> sort1;
			}

			p1 -> sort1 = temp;
			temp -> sort1 = p2;

		}
		temp = temp -> next;
	}

	return sort1_head;
}
 /*==============================================================================*/
 void display_sort1 (Node *head) {

   Node *node = head;

   while ( node != NULL) {
     printf("%2d, %.2f, %.2f\n", node -> value, node -> key1, node -> key2 );
     node  = node -> sort1;
   }

 }

 /*==============================================================================*/
 void display_sort2 (Node *head) {

   Node *node = head;

   while ( node != NULL) {
     printf("%2d, %.2f, %.2f\n", node -> value, node -> key1, node -> key2 );
     node  = node -> sort2;
   }

 }
 /*==============================================================================*/
 Node *ascend_sort2(Node *og_link){

 	if(og_link == NULL){
 		return NULL;
 	}

 	Node * sort1_head = og_link;
 	Node *temp = og_link -> next;

 	while(temp != NULL){
 		Node * p1 = sort1_head;
 		Node *p2 = sort1_head-> sort2;

 		/*if the next is smaller than the current number, the new min is now the next number*/
 		if(temp -> key2 <= sort1_head -> key2){
 			Node * newMin = temp;
 			temp->sort2 =sort1_head;
 			sort1_head = newMin;
 		}else{
 			/*p2 not null, p1(current one) lt temp , p2(next one) lt temp*/
 			while(p2!=NULL   &&    p1->key2 < temp->key2   &&   p2->key2 <= temp->key2){
 				p1 = p1 -> sort2;
 				p2 = p2 -> sort2;
 			}

 			p1 -> sort2 = temp;
 			temp -> sort2 = p2;

 		}
 		temp = temp -> next;
 	}

 	return sort1_head;
 }
 /*==============================================================================*/
void change_value (Node *head) {

  Node *node = head;
  int i = 1;

  while ( node != NULL) {
        if (i == 3) {
           node -> value = node -> value*10;
        }
    node  = node -> next;
    i++;
  }

  head = node;

}
/*==============================================================================*/
