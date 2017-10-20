#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

bool parent = true;
int thread_child = 3;
void* what_to_tell_a(void*)
{
	cout<<"Hello world, thread a there!\n";
	void* result=NULL;
	thread_child--;
	return result;
}
void* what_to_tell_b(void*)
{
	cout<<"Hello world, thread b there!\n";
	void* result=NULL;
	thread_child--;
	return result;
}
void* what_to_tell_c(void*)
{
	cout<<"Hello world, thread c there!\n";
	void* result=NULL;
	thread_child--;
	return result;
}
void* make_some_threads(void*)
{
	pthread_t a;
	pthread_t b;
	pthread_t c;
	pthread_create(&a, NULL, &what_to_tell_a,NULL);
	pthread_create(&b, NULL, &what_to_tell_b,NULL);
	pthread_create(&c, NULL, &what_to_tell_c,NULL);
	while(thread_child>0)
	{usleep(1);}
	cout<<"Hello world, parent thread there!\n";
	void* result=NULL;
	parent = false;
	return result;
}
int main()
{
	pthread_t parent_thread;
	pthread_create(&parent_thread, NULL, &make_some_threads,NULL);
	while(parent)
	{usleep(1);}
	cout<<"Hello world, main there!\n";

	return 0;
}
