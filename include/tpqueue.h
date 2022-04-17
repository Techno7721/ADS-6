// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T, int size>
class TPQueue {
 private:
  T arr[size];
  int first, last;
 public:
  TPQueue(): first(0), last(0) {}
  void push(T value) {
    if (last - first >= size) {
	    std::cout << "Full!";
	  } else if (last == 0) {
	    arr[(last++) % size] = value;
	  } else if (arr[(last - 1) % size].prior < value.prior) {
	    for (int i = first; i < (size + first); ++i) {
		    if (arr[i % size].prior < value.prior) {
		      for (int j = (last - 1); j > (i - 1); --j) {
	          arr[(j + 1) % size] = arr[j % size];
		      }
		      arr[i % size] = value;
		      break;
		    }
	    }
	    last += 1;
	  } else {
	    arr[(last++) % size] = value;
	  }
  }
  T pop() {
    if (first == last) {
	    std::cout << "Empty!";
	  } else {
	    return arr[(first++) % size];
	  }
  }
  T re() {
	  return arr[last];
  }
  T front() {
	  if (first == last) {
	    std::cout << "Empty!";
	  } else {
	    return arr[first % size];
	  }
  }
  T back() {
	  if (first == last) {
	    std::cout << "Empty!";
	  } else {
	    return arr[(last - 1) % size];
	  }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
