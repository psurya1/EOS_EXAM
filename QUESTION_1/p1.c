
//my rollnumber is 210950130017

#include <stdio.h>        
#include <fcntl.h>       
#include <sys/stat.h>    
#include <mqueue.h>

mqd_t d1;
struct mq_attr d2;


int main(int argc,char const *argv[])
{   
    d2.mq_flags=0;       /* Flags (ignored for mq_open()) */
    d2.mq_maxmsg=4;      /* Max. # of messages on queue */
    d2.mq_msgsize=64;     /* Max. message size (bytes) */
    d2.mq_curmsgs=0; 

    d1=mq_open("/dictionary.txt", O_WRONLY | O_CREAT ,S_IRUSR | S_IWUSR,&d2);

    
        mq_send(d1,"MA\n",3,0);
        
        mq_close(d1);
    

    return 0;
}
