// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <mutex>
#include <condition_variable>
#include <semaphore.h> 
#include <deque>

template <typename T>
class TWITCHTEST_API BlockingQueue
{
private:
	std::mutex d_mutex;
	Semaphore empty;
	TQueue<T> Queue;
public:
	void push(T const& value) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "push");
		d_mutex.lock();
		Queue.Enqueue(value);
		empty.post();
		d_mutex.unlock();
	}

	T pop() {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "pop");
		T cmd;
		empty.wait();
		d_mutex.lock();
		Queue.Dequeue(cmd);
		d_mutex.unlock();
		return cmd;


		/*
		std::unique_lock<std::mutex> lock(this->d_mutex);
		this->d_condition.wait(lock, [=] { return !this->d_queue.empty(); });
		T rc(std::move(this->d_queue.back()));
		this->d_queue.pop_back();
		return rc;
		*/
	}
};