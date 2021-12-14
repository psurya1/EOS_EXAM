
//my rollnumber is 210950130017

#include <stdio.h>        
#include <fcntl.h>       
#include <sys/stat.h>    
#include <mqueue.h>
#include <mqueue.h>
#include <string.h>

mqd_t cdacmq;
struct mq_attr d2;
unsigned char buff[64];
int msg_prio;
int c;


int main(int argc,char const *argv[])
{   
    d2.mq_flags=0;       /* Flags (ignored for mq_open()) */
    d2.mq_maxmsg=4;      /* Max. # of messages on queue */
    d2.mq_msgsize=64;     /* Max. message size (bytes) */
    d2.mq_curmsgs=0; 

    cdacmq=mq_open("/dictionary.txt", O_RDONLY | O_CREAT ,S_IRUSR | S_IWUSR,&d2);
        
    mq_receive(cdacmq,buff,64,&msg_prio);
    c=strlen(buff);
    printf("RECEIVED MESSAGE :%s PRIORITY :%d",buff,msg_prio);
    printf("LENGTH:%d\n",c);
    mq_close(cdacmq);
    return 0;
}
