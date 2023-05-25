#include <linux/kernel.h>  
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/list.h>
asmlinkage long sys_hello(void) 
{
    printk("Hello, World!\n");     
    return 0; 
} 

asmlinkage long sys_set_weight(int weight)
{
    if(weight<0)
        return -EINVAL;
    current->weight=weight;
    return 0;

}

asmlinkage long sys_get_weight(void){
    printk("current pid:"+current->pid);
    return current->weight;

}
asmlinkage long sys_get_ancestor_sum(void){
   struct task_struct* p = current;
    int sum=0;
    do
    {
        sum+=p->weight;
        p=p->parent;
    } while(p->parent->pid);

    return sum;   


}
asmlinkage long sys_get_heaviest_descendant(void){
      struct task_struct* p = current;
    int max=p->weight;
    pid_t max_pid=p->pid;
    // while(p->parrent->pid)
    // {
    //     if(p->pid > max){
    //         max_pid = p->pid
    //         max=weight;
    //     }
    // p = list_entry(&children_list,struct task_struct,children);    } 

    return max_pid;   

}
