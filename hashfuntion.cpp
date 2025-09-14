
// hashtable :-  teachnique that maps a large set of data to small set of data. 
      //  implaments an associative array, a struture that can map unique keys to specific values.
      //  hash function to compute an index(a hash value) into array of "buckets" or "slots" from which the desired value can be found.

//  core components in c++
//  key - 
//  value-
//  hash function -
//  Array of buckets
//  collision Handling -


// working : 
    //  insertions -
          //  take key and pass it through the hash function to get an index
          //  index = hash(key) % array_size.
          //  go to bucket at that index in array.
          //  append key-value pair to the linked list in bucket

    //  deletion -
          // compute the index from the key
          // find key-value pair in linked list at index
          // remove the element from list

    //  lookup -
        //   compute index from the key using hash function 
        //   go to the bucket at that index
        //   perform linear search thorough the linked list in that bucket for the exact key

// Implementations -
  // 1. std::unordered_map
    //   
  // 2. std::unordered_set
    // 



    // 
    // 

#include <iostream>
#include<cstring>

//Linked List
struct hashMap{
     // key is string   
    char* key;
    // value is also string
    char* value;
    struct node* next;
);

// like constructor
void setNode(struct node* node, char* key, char* value){
  node->key = key;
  node->value = value;
  node->next = node;
return ;
}

int hashFunction(struct hashMap* mp, char* key) {
   int bucketIndex;
   int sum = 0 , factor = 31;
   for(int i = 0; i< strlen(key); i++){
      sum = ((sum % mp->capacity) + (((int)key[i])*factor)% mp->capacity)% mp->capacity;
      factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
   }
  bucketIndex = sum;
  return bucketIndex;
}

void insert(struct hashMap* mp, char* key , char* value) {
    // get bucket index for given
   //  key - value pair
  int bucketIndex = hashFunction(map ,  key);
  struct node* newNode = (struct node*) malloc(sizeof(struct node));  // creating new node
  // Setting value of node
  setNode(newNode , key , value);
  // Bucket index is empty ......no collision
  if(mp->arr[bucketIndex] == NULL) {
      mp->arr[bucketIndex] = newNode;
  }
    //Collision
  else {
    // Adding newNode at the head of linked list which is present at bucket index ....insertion at head in linked list
    newNode->next = ,p->arr[bucketIndex];
    mp->arr[bucketIndex] = newNode;
  }
  return ;
}

void deletekey(struct hashMap* m[, char* key) {
  // getting bucket index for this given key
  int bucketIndex = hashFunction(mp , key);
  struct node* prevNodse = nullptr;
  // points to the head of linked list present at bucket index
  struct node* currNode = mp->arr[bucketIndex];
  while (currNode != nullptr) {
      // key is matched at delete this node from linked list
      if(strcmp(key , currNode->key) == 0) {
            //Head node deletion
            if (currNode == mp->arr[bucketIndex]){
                mp->arr[bucketIndex] = currNode->next;
            }
            //last node or middle node
            else {  
                preNode->next = currNode->next;
            }
            free(currNode);
            break;
      }
preNsoe = currNode;
currNode = currNode->next;
return ;
  }


