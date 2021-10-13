#include <iostream>

 struct node{
    int32_t value;
    struct node *next;
 };

 class linked_list{
    private:
       node *head, *tail;   
    public:
        linked_list(){
            head = nullptr;
            tail = nullptr;
        }
 
        void add_node(int n){
            node *tmp = new node;
            tmp->value = n;
            tmp->next = nullptr;

            if(head == nullptr){
                head = tmp;
                tail = tmp;
            }else{
                tail->next = tmp;
                tail = tmp;
            }
        }
        void remove_first_node(linked_list *l){
            node *tmp;
            if (l->head == nullptr) {return;}
            tmp = l->head;
            l->head = l->head->next;
            delete tmp;
           return;
       }

       void print_nodes(linked_list l){
        node *tmp;
        if (l.head == nullptr) {return;}
        tmp = l.head;
        while (tmp != nullptr) {
            std::cout << tmp->value << std::endl;
            tmp = tmp->next;
        }
        return;
        }
};

int main(){
    linked_list l;
    l.add_node(1);
    l.add_node(2);
    l.add_node(3);
    l.remove_first_node(&l);
    l.remove_first_node(&l);
    l.print_nodes(l);
    return 0;
}    