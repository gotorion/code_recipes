#include <iostream>
class Subject {
public:
  virtual ~Subject() = default;
  virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
  void request() const { std::cout << "Handling request.\n"; }
};

class Proxy : public Subject {
private:
  RealSubject *real_subject_;
  bool check_access() const {
    std::cout << "checking access\n";
    return true;
  }

  void log_access() const { std::cout << "logging access\n"; }

public:
  Proxy(RealSubject *real_subject) : real_subject_(real_subject) {}
  ~Proxy() { delete real_subject_; }
  void request() const {
    if (check_access()) {
      real_subject_->request();
      log_access();
    }
  }
};

void ClientCode(const Subject &subject) { subject.request(); }

int main() {
  RealSubject *real_subject = new RealSubject();
  ClientCode(*real_subject);

  Proxy *proxy = new Proxy(real_subject);
  ClientCode(*proxy);
  delete proxy;
}