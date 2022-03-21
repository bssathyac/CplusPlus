/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>

class IObserver { // Interface or Abstract class
 public:
  virtual ~IObserver(){};
  virtual void Update(const std::string &message_from_subject) = 0; // pure virtual func
};

class ISubject { // Interface or Abstract class
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0; // pure virtual func
  virtual void Detach(IObserver *observer) = 0; // pure virtual func
  virtual void Notify() = 0; // pure virtual func
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public ISubject {
 public:
  virtual ~Subject() {
    std::cout << "Goodbye, I was the Subject.\n";
  }

  /**
   * The subscription management methods.
   */

  /* situations when a programmer makes a mistake while overriding that function. 
   * So, to keep track of such an error, C++11 has come up with the keyword override. 
   * It will make the compiler to check the base class to see if there is a virtual function with this 
   * exact signature. And if there is not, the compiler will show an error. */
  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override {
    list_observer_.remove(observer);
  }
  void Notify() override {
    HowManyObserver();
    // std::list<IObserver *>::iterator iterator = list_observer_.begin();
    // while (iterator != list_observer_.end())
    // {
    //   (*iterator)->Update(message_);
    //   ++iterator;
    // } /*  OR can be done as below  */
    for (const auto &it:list_observer_)
    {it->Update(message_); }
  }

  void CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }

  /**
   * Usually, the subscription logic is only a fraction of what a Subject can
   * really do. Subjects commonly hold some important business logic, that
   * triggers a notification method whenever something important is about to
   * happen (or after it).
   */
  void SomeBusinessLogic() {
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
  }

 private:
  std::list<IObserver *> list_observer_;
  std::string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) { // if the initializer list was not used then there will be compiler error
    // subject_= subject; Error "Observer::Observer(Subject &subject)" provides no initializer for: -- reference member "Observer::subject_"
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
  }

 private:
  std::string message_from_subject_;
  Subject &subject_; // basically it is supposed to be an error because this reference member p is not initialized
    // with some variable at the same step of its declaration. But it will run in this case. For us, this is the declaration but
    // not for compiler since it will be inited in the construtor of this class. Compiler considers that line as declaration and
    // initialization is done at same step.
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject); // pass by reference: actual value of subject ptr is deferenced here
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("The weather is hot today! :p");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great! ;)");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int theObserverPattern()
{
  ClientCode();
  return 0;
}