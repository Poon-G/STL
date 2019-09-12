#include <iostream>
#include <forward_list>
void printList(std::forward_list<int>root){
    for(auto x:root)    
     std::cout<<x<<" ";
     std::cout<<"\n";
}

int main()
{
    std::forward_list<int>root{1,2,3,4,5,6};
    std::forward_list<int>reverse;
    
    //reverse Link List    
   //1 way:
   while(!root.empty()){
        reverse.push_front(root.front());
        root.pop_front();
    }

//2nd way:
    // for(auto x:root){
    //  reverse.push_front(x);
    // }
    
    for(auto y:reverse)
    std::cout<<y<<" ";
    std::cout<<"\n";
    
  //Delete item from link list
    // for(auto x:root){
    //     if(x==4)
    //     root.remove(x);
    // }
    // for(auto x:root){
    //  std::cout<<x<<" ";
    // }
    // std::cout<<"\n";
    
    //swap in k groups
    std::forward_list<int>head{10,20,30,40,50,60};
    int k=2;        //op expected: 20,10,40,30,60,50
    std::forward_list<int>result;
    std::forward_list<int>temp;
    int i=0;
    std::forward_list<int>::iterator ptr=result.before_begin(); 
    for(auto x:head){
        if(i<k){
            temp.push_front(x);
            i++;
        }else{
         i=0;
         for(auto x:temp){
           ptr= result.insert_after(ptr,x);
         }
      //   printList(result);
      
         temp.clear();
         temp.push_front(x);
         i++;
        }
    }
    if(!temp.empty())
     result.splice_after(ptr,temp);
    std::cout<<"\n";
    
    for(auto y:result)
    std::cout<<y<<" ";
    
    return 0;
}
