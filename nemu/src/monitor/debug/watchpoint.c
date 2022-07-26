#include "watchpoint.h"
#include "expr.h"
#include<stdlib.h>
#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = &wp_pool[i + 1];
    wp_pool[i].expr=NULL;
  }
  wp_pool[NR_WP - 1].next = NULL;

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
// add new node from free_ to head;
WP* new_wp(){
  // no pointer;
  if(free_==NULL){
    assert(0);
    return NULL;
  }
  WP* next;
  next=free_;
  free_=free_->next;
  next->next=head;
  head=next;
  return head;
}
// del a node from head;
// add the removed node to free_;
void free_wp(WP *wp){
  if(head==NULL){
    return ;
  }
  WP* del=NULL;
  // if wp is head,we need special;
  if(head==wp){
    del=head;
    head=head->next;
  }else{
    WP* next =head;
    while(next->next!=NULL){
      if(next->next==wp){
        del=next->next;
        next->next=next->next->next;
        break;
      }
      next=next->next;
    }
  }
  if(del==NULL){
    Log("no match node which you want");
  }else{
    del->next=free_;
    free_=del;
  }
}
void del_wp(char * args){
  WP * del=head;
  int no=atoi(args);
  while(del!=NULL){
    if(del->NO==no){
      free_wp(del);
    }
  }
}

void show_wp(){
  WP * t=head;
  if(t==NULL){
    Log("don't have any watchpoint message\n");
    return ;
  }
  while(t!=NULL){
    Log("no=%d,\t\twhat=%s,\t\thistory=%d\n",t->NO,t->expr,t->histroy);
    t=t->next;
  }
}


bool check_watchpoints(){
  WP* temp=head;
  int res;
  bool* f=false;
  while(temp!=NULL){
    res=expr(temp->expr,f);

    if(res!=temp->histroy){
      Log("%s history = %d,now = %d\n",temp->expr,temp->histroy,res);
      temp->histroy=res;
      return true;
    }
    temp=temp->next;
  }
  return false;
}














