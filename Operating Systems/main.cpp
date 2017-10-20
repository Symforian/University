#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* what_to_tell_a(void*)
{
	cout<<"Hello world, thread a there!\n";
	//cout.flush();
	void* result=NULL;
	return result;
}
void* what_to_tell_b(void*)
{
	cout<<"Hello world, thread b there!\n";
	//cout.flush();
	void* result=NULL;
	return result;
}
void* what_to_tell_c(void*)
{
	cout<<"Hello world, thread c there!\n";
	//cout.flush();
	void* result=NULL;
	return result;
}
int main()
{
	pthread_t a;
	pthread_t b;
	pthread_t c;
	pthread_create(&a, NULL, &what_to_tell_a,NULL);
	pthread_create(&b, NULL, &what_to_tell_b,NULL);
	pthread_create(&c, NULL, &what_to_tell_c,NULL);
	usleep(3);
	cout<<"Hello world, main there!\n";
	//cout.flush();

	return 0;
}
