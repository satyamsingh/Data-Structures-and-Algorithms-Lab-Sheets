#include"multiq.h"
int main(){
    MultiQ mq = createMQ(5);
    Task t1 = (Task)malloc(sizeof(struct task));
    TaskID tid1 = (TaskID)malloc(sizeof(struct taskid));
    Priority p1 = (Priority)malloc(sizeof(struct priority));
    t1->tid = tid1;
    t1->p = p1;
    tid1->value = 100001;
    p1->value = 1;
    Task t2 = (Task)malloc(sizeof(struct task));
    TaskID tid2 = (TaskID)malloc(sizeof(struct taskid));
    Priority p2 = (Priority)malloc(sizeof(struct priority));
    t2->tid = tid2;
    t2->p = p2;
    tid2->value = 100002;
    p2->value = 2;
    Task t3 = (Task)malloc(sizeof(struct task));
    TaskID tid3 = (TaskID)malloc(sizeof(struct taskid));
    Priority p3 = (Priority)malloc(sizeof(struct priority));
    t3->tid = tid3;
    t3->p = p3;
    tid3->value = 100003;
    p3->value = 3;
    Task t4 = (Task)malloc(sizeof(struct task));
    TaskID tid4 = (TaskID)malloc(sizeof(struct taskid));
    Priority p4 = (Priority)malloc(sizeof(struct priority));
    t4->tid = tid4;
    t4->p = p4;
    tid4->value = 100004;
    p4->value = 1;
    Task t5 = (Task)malloc(sizeof(struct task));
    TaskID tid5 = (TaskID)malloc(sizeof(struct taskid));
    Priority p5 = (Priority)malloc(sizeof(struct priority));
    t5->tid = tid5;
    t5->p = p5;
    tid5->value = 100005;
    p5->value = 1;
    Task t6 = (Task)malloc(sizeof(struct task));
    TaskID tid6 = (TaskID)malloc(sizeof(struct taskid));
    Priority p6 = (Priority)malloc(sizeof(struct priority));
    t6->tid = tid6;
    t6->p = p6;
    tid6->value = 100006;
    p6->value = 1;
    Task t7 = (Task)malloc(sizeof(struct task));
    TaskID tid7 = (TaskID)malloc(sizeof(struct taskid));
    Priority p7 = (Priority)malloc(sizeof(struct priority));
    t7->tid = tid7;
    t7->p = p7;
    tid7->value = 100007;
    p7->value = 2;
    mq = addMQ(mq,t1);
    mq = addMQ(mq,t2);
    mq = addMQ(mq,t3);
    mq = addMQ(mq,t4);
    mq = addMQ(mq,t5);
    mq = addMQ(mq,t6);
    mq = addMQ(mq,t7);
    while(true){
        Task t = delNextMQ(mq);
        if(t==NULL)
            break;
        else
            printf("%ld",t->tid->value);
    }
    return 0;
}
