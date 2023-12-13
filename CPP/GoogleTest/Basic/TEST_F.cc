#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <deque>
template <typename T>
class Queue {
 public:
  void Enqueue(const T& elem) { _deque.push_back(elem); }

  T* Dequeue(void) {
    T& ret = _deque.front();
    _deque.pop_front();
    return &ret;
  }

  std::size_t size() const { return _deque.size(); }

 private:
  std::deque<T> _deque;
};

class QueueTest : public testing::Test {
 protected:
 void SetUp() override {
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
 }
 protected:
  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
    int * n = q0_.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.size(), 0);
    delete n;

    n = q2_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(q2_.size(), 1);
    delete n;
}

int main(int argc, char **argv) {
    // sprintf()
    std::cout << "test " << std::string(__FILE__) << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
