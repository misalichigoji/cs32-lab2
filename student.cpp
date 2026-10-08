  #include "student.h"
  #include <string>
  #include <cstring>

  Student::Student(const char * const name, int perm) {
    this->name = nullptr;
    this->setName(name);
    this->setPerm(perm);
  } //done

  int Student::getPerm() const {
    return perm;
  } //done

  const char * const Student::getName() const {
    return name;
  } //done

  void Student::setPerm(const int permNumber) {
    this->perm = permNumber;
  }//done

  void Student::setName(const char * const name) {
    delete[] this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
  } //done?


  Student::Student(const Student &orig) {
    this->setName(orig.getName());
    this->setPerm(orig.getPerm());
  } //done?

  Student::~Student() {
    delete[] this->name;
  } //done?

  Student & Student::operator=(const Student &right) {
    // The next two lines are standard, and you should keep them.
    // They avoid problems with self-assignment where you might free up 
    // memory before you copy from it.  (e.g. x = x)

    if (&right == this) 
      return (*this);

    // TODO... Here is where there is code missing that you need to 
    // fill in...
    this->setName(right.getName());
    this->setPerm(right.getPerm());




    // KEEP THE CODE BELOW THIS LINE
    // Overloaded = should end with this line, despite what the textbook says.
    return (*this); 

  }

  std::string Student::toString() const {
    std::string temp = this->getName();
    return "[" + temp + "," + std::to_string(this->getPerm()) + "]";
  }

