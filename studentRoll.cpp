#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  if(this->head == NULL)
  {
    this->head = new Node;
    this->tail = this->head;
  }
  else
  {
    this->tail->next = new Node;
    this->tail = this->tail->next;
  }
  this->tail->s = new Student(s);
  this->tail->next = nullptr;
} //done?

std::string StudentRoll::toString() const {
  if(this->head == NULL)
    return "[]";
  Node* temp = this->head;
  std::string fullstr = "";

  std::string tempy = temp->s->getName();
  tempy = "[" + tempy + "," + std::to_string(temp->s->getPerm()) + "]";  
  fullstr += tempy;
  while(temp != this->tail)
  {
    temp = temp->next;
    tempy = temp->s->getName();
    tempy = "[" + tempy + "," + std::to_string(temp->s->getPerm()) + "]";  
    fullstr += tempy;
  }
  return fullstr;
} //done?

StudentRoll::StudentRoll(const StudentRoll &orig) {

  this->head = NULL;
  this->tail = NULL;

  Node* temp = orig.head;

  while(temp != NULL)
  {
    this->insertAtTail(*temp->s);
    temp = temp->next;
  }
}//done??

StudentRoll::~StudentRoll() {

  Node* temp = this->head;
  while(temp != this->tail)
  {
    Node* nexty = temp->next;
    delete temp->s;
    delete temp;
    temp = nexty;
  }
  if(temp != NULL)
  {
    delete temp->s;
    delete temp;
  }
  head = NULL;
  tail = NULL;
}//done?

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  
  Node* temp = this->head;
  while(temp != NULL)
  {
    Node* nexty = temp->next;
    delete temp->s;
    delete temp;
    temp = nexty;
  }
  
  temp = right.head;
  while(temp != NULL)
  {
    insertAtTail(*temp->s);
    temp = temp->next;
  }
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}//done?





