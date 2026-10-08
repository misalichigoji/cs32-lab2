#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  this->tail->next = new Node;
  this->tail = this->tail->next;
  this->tail->s->setName(s.getName());
  this->tail->s->setPerm(s.getPerm());
  this->tail->next = nullptr;
} //done?

std::string StudentRoll::toString() const {
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
  if(orig.head == NULL)
  {
    this->head = NULL;
    this->tail = NULL;
    return;
  }
  Node* temp = orig.head;
  this->head = new Node;
  this->head->s->setName(orig.head->s->getName());
  this->head->s->setPerm(orig.head->s->getPerm());
  while(temp != orig.tail)
  {
    temp = temp->next;
    this->insertAtTail(*temp->s);
  }
}//done?

StudentRoll::~StudentRoll() {
  if(this->head == NULL)
    return;

  Node* temp = this->head;
  delete temp->s;
  this->head = temp;
  this->head = this->head->next;
  delete temp;
  while(temp != this->tail)
  {
    temp = this->head;
    delete temp->s;
    this->head = temp;
    this->head = this->head->next;
    delete temp;
  }
}//done?

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  if(this->head == NULL)
  {
    this->head = NULL;
    this->tail = NULL; 
    return *this;
  }

  Node* tempr = right.head;
  this->head = new Node;
  Node* templ = this->head;
  templ->s = tempr->s;
  while(tempr != right.tail)
  {
    tempr = tempr->next;
    templ->next = new Node;
    templ = templ->next;
    templ->s = tempr->s;
  }
  this->tail = templ;
  templ->next = NULL;
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}//done?





