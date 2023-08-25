 #include<stdio.h>
 #define SIZE 7
  int enqueue(int);
 int dequeue(int);
 int display();
 int items[SIZE], f=-1, r=-1;
 int main(){
     //enqueue for all seven elements
     enqueue(1);
     enqueue(2);
     enqueue(3);
     enqueue(4);
     enqueue(5);
     enqueue(6);
     enqueue(7);
     //dequeueing the elements
     dequeue();
     //displaying the elements in the queue
     display();

     return 0;
 }
 int enqueue(int value){
     if (r == SIZE - 1)
     printf("\nThe queue is full");
     else{
         (f == -1)
         f++;
         if(f>r);
         f = r = -1;
         }
}
int display(){
    if (r == -1)
    printf("\nThe queue is empty");
    else{
        int i;
        printf("\nqueue elements are:");
        for(i  = f; i<=r; i++);
        print("%d", items[i]);
    }
    printf("\n");
}







