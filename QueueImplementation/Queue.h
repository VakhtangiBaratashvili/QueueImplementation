#pragma once

#include <iostream>

using namespace std;

template <typename T>

class Queue {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& val) {
			data = val;
			next = nullptr;
		}
	};
	typedef Node* NodePointer;
	NodePointer head_;
	NodePointer tail_;
public:
	Queue() {
		head_ = nullptr;
		tail_ = nullptr;
	}
	Queue(const Queue& orig) {
		head_ = nullptr;
		tail_ = nullptr;
		NodePointer origCurrent = orig.head_;
		while (origCurrent) {
			enqueue(origCurrent->data);
			origCurrent = origCurrent->next;
		}
	}
	Queue& operator=(const Queue& rhs) {
		if (this == &rhs) {
			return *this;
		}
		~Queue();
		NodePointer rhsCurrent = rhs.head_;
		while (rhsCurrent) {
			enqueue(rhsCurrent->data);
			rhsCurrent = rhsCurrent->next;
		}
		return *this;
	}
	~Queue() {
		while (!empty()) {
			dequeue();
		}
	}
	bool empty() const {
		return head_ == nullptr;
	}
	T& front() {
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		return head_->data;
	}
	T& back() {
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		return tail_->data;
	}
	void enqueue(const T& val) {
		NodePointer newNode = new Node(val);
		if (empty()) {
			head_ = tail_ = newNode;
		}
		else {
			tail_->next = newNode;
			tail_ = newNode;
		}
	}
	void dequeue() {
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		NodePointer temp = head_;
		head_ = head_->next;
		delete temp;
		if (head_ == nullptr) {
			tail_ = nullptr;
		}
	}
	void display(ostream& out = cout) const {
		NodePointer current = head_;
		while (current) {
			out << current->data << " ";
			current = current->next;
		}
		out << endl;
	}
};

template <typename T>
ostream& operator<<(ostream& out, Queue<T> queue) {
	queue.display(out);
	return out;
}