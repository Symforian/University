#include <iostream>
#include <pthread.h>

using namespace std;

void *what_to_tell_a(void*)
{
	cout<<"Hello world, thread a there!\n";
	return NULL;
}
void *what_to_tell_b(void*)
{
	cout<<"Hello world, thread b there!\n";
	return NULL;
}
void *what_to_tell_c(void*)
{
	cout<<"Hello world, thread c there!\n";
	return NULL;
}
void *make_some_threads(void*)
{
	pthread_t a,b,c;
	pthread_create(&a, NULL, &what_to_tell_a,NULL);
	pthread_create(&b, NULL, &what_to_tell_b,NULL);
	pthread_create(&c, NULL, &what_to_tell_c,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	pthread_join(c,NULL);
	cout<<"Hello world, parent thread there!\n";
	void* result=NULL;
	return result;
}
int main()
{
	pthread_t parent_thread;
	pthread_create(&parent_thread, NULL, &make_some_threads,NULL);
	pthread_join(parent_thread,NULL);
	cout<<"Hello world, main there!\n";

	return 0;
}
