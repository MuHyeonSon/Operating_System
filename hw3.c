// 201804594 sonmuhyeon operationsystem make deadlock

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t semaphore[4]; // four semaphore

void *thread_car(void *i)
{
	long car_pos = (long)i; // if happen problem, then change to 'long'
	
	for(int j = 0; j < 9; j++) // create 9 car each position
	{
		
		//position : north
		if(car_pos == 0){
			// 0 : turn right// 1 : go strait// 2 : turn left//
			int direction0 = rand()%3; // create random num (0 to 2)


			if(direction0 == 0){ 
				printf("north car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
				printf("north car got semaphore0\n");
				sleep(4);
				sem_post(&semaphore[0]);
				printf("north car release semaphore0\n");
			}	
			else if(direction0 == 1){
       				printf("north car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
       				printf("north car got semaphore0\n");
				sleep(4);
       				printf("north car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
       				printf("north car got semaphore1\n");
				sem_post(&semaphore[0]);
				printf("north car release semaphore0\n");
				sem_post(&semaphore[1]);
				printf("north car release semaphore1\n");
			}
			else if(direction0 == 2){
				printf("north car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
				sleep(4);
       				printf("north car got semaphore0\n");
       				printf("north car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
       				printf("north car got semaphore1\n");
				printf("north car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
				printf("north car got semaphore2\n");
				sem_post(&semaphore[0]);
				printf("north car release semaphore0\n");
				sem_post(&semaphore[1]);
				printf("north car release semaphore1\n");
				sem_post(&semaphore[2]);
				printf("north car release semaphore2\n");

			}	
		}
		//position : west
		else if(car_pos == 1){
			// 0 : turn right// 1 : go strait// 2 : turn left//
			int direction1 = rand()%3; // create random num (0 to 2)

			if(direction1 == 0){ 
				printf("west car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
				printf("west car got semaphore1\n");
				sem_post(&semaphore[1]);
				printf("west car release semaphore1\n");
			}	
			else if(direction1 == 1){
       				printf("west car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
       				printf("west car got semaphore1\n");
       				printf("west car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
       				printf("west car got semaphore2\n");
				sem_post(&semaphore[1]);
				printf("west car release semaphore1\n");
				sem_post(&semaphore[2]);
				printf("west car release semaphore2\n");
			}
			else if(direction1 == 2){
				printf("west car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
       				printf("west car got semaphore1\n");
       				printf("west car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
       				printf("west car got semaphore2\n");
				printf("west car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
				printf("west car got semaphore3\n");
				sem_post(&semaphore[1]);
				printf("west car release semaphore1\n");
				sem_post(&semaphore[2]);
				printf("west car release semaphore2\n");
				sem_post(&semaphore[3]);
				printf("west car release semaphore3\n");

			}	
	
		}
		//position : south
		else if(car_pos == 2){
			// 0 : turn right// 1 : go strait// 2 : turn left//
			int direction2 = rand()%3; // create random num (0 to 2)


			if(direction2 == 0){ 
				printf("south car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
				printf("south car got semaphore2\n");
				sem_post(&semaphore[2]);
				printf("south car release semaphore2\n");
			}	
			else if(direction2 == 1){
       				printf("south car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
       				printf("south car got semaphore2\n");
       				printf("south car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
       				printf("south car got semaphore3\n");
				sem_post(&semaphore[2]);
				printf("south car release semaphore2\n");
				sem_post(&semaphore[3]);
				printf("south car release semaphore3\n");
			}
			else if(direction2 == 2){
				printf("south car is wating semaphore2\n");
				sem_wait(&semaphore[2]);
				sleep(4);
       				printf("south car got semaphore2\n");
       				printf("south car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
       				printf("south car got semaphore3\n");
				printf("south car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
				sleep(4);
				printf("south car got semaphore0\n");
				sem_post(&semaphore[2]);
				printf("south car release semaphore2\n");
				sem_post(&semaphore[3]);
				printf("south car release semaphore3\n");
				sem_post(&semaphore[0]);
				printf("south car release semaphore0\n");

			}	
		}
		//position : east
		else if(car_pos == 3){
			// 0 : turn right// 1 : go strait// 2 : turn left//
			int direction3 = rand()%3; // create random num (0 to 2)


			if(direction3 == 0){ 
				printf("east car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
				printf("east car got semaphore3\n");
				sem_post(&semaphore[3]);
				printf("east car release semaphore3\n");
			}	
			else if(direction3 == 1){
       				printf("east car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
       				printf("east car got semaphore3\n");
       				printf("east car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
				sleep(4);
       				printf("east car got semaphore0\n");
				sem_post(&semaphore[3]);
				printf("east car release semaphore3\n");
				sem_post(&semaphore[0]);
				printf("east car release semaphore0\n");
			}
			else if(direction3 == 2){
				printf("east car is wating semaphore3\n");
				sem_wait(&semaphore[3]);
				sleep(4);
       				printf("east car got semaphore3\n");
       				printf("east car is wating semaphore0\n");
				sem_wait(&semaphore[0]);
				sleep(4);
       				printf("east car got semaphore0\n");
				printf("east car is wating semaphore1\n");
				sem_wait(&semaphore[1]);
				sleep(4);
				printf("east car got semaphore1\n");
				sem_post(&semaphore[3]);
				printf("east car release semaphore3\n");
				sem_post(&semaphore[0]);
				printf("east car release semaphore0\n");
				sem_post(&semaphore[1]);
				printf("east car release semaphore1\n");

			}
		}

	} 


	
	//wait P (access to resource)
//	sem_wait(&semaphore);
//	printf("the car(thread%d) starts passing through the intersection\n",car_pos);

	//critical section
//	sleep(4);

//	printf("the car number %d starts passed through the intersection from rnorth\n",train_num);
       	
	//signal (semaphore release)
//	sem_post(&semaphore);
//	free(i);************************	
//	printf("the car number %d return semaphore\n",train_num);

}

int main()
{
	printf("start program\n");

	// create four semaphore, then give the one ticket each semaphore
	sem_init(&semaphore[0],0,1);
	sem_init(&semaphore[1],0,1);
	sem_init(&semaphore[2],0,1);
	sem_init(&semaphore[3],0,1);

	// define four threads
	pthread_t t[4];

	// creat four threads
	pthread_create(&t[0], NULL, thread_car, (void*)0);
	pthread_create(&t[1], NULL, thread_car, (void*)1);
	pthread_create(&t[2], NULL, thread_car, (void*)2);
	pthread_create(&t[3], NULL, thread_car, (void*)3);
	
	// thread join
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	pthread_join(t[2], NULL);
	pthread_join(t[3], NULL);

	printf("Deadlock didn't happen! \\n");
	return 0;

}

