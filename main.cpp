#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"
#include "math.h"

void add_coordinate(Coordinate *list_end, float x, float y){
     if (list_end == NULL) return;

    Coordinate *newNode = new Coordinate;
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    newNode->previous = list_end;
    newNode->coord_id = list_length(list_end) + 1;

    list_end->next = newNode;
}

void forward_display(Coordinate *list_beginning){
    Coordinate *temp = list_beginning;
    std::cout << "Forward list:" << std::endl;
    while (temp != NULL) {
        std::cout << "ID " << temp->coord_id << ": (" << temp->x << ", " << temp->y << ")" << std::endl;
        temp = temp->next;
    }
    
}

void backward_display(Coordinate *list_end){
    Coordinate *temp = list_end;
    std::cout << "Backward list:" << std::endl;
    while (temp != NULL) {
        std::cout << "ID " << temp->coord_id << ": (" << temp->x << ", " << temp->y << ")" << std::endl;
        temp = temp->previous;
    }
    
}

void delete_coordinate(Coordinate** list_beginning, int coord_id_to_delete){
     Coordinate* temp = *list_beginning;
    while (temp != NULL && temp->coord_id != coord_id_to_delete)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->previous != NULL)
        temp->previous->next = temp->next;
    else
        *list_beginning = temp->next;

    if (temp->next != NULL)
        temp->next->previous = temp->previous;

    delete temp;
    
}

int list_length(Coordinate *list_beginning){
    int count = 0;
    Coordinate *temp = list_beginning;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void closest_to(Coordinate *list_beginning, float x, float y){
    if (list_beginning == NULL) return;

    Coordinate *temp = list_beginning;
    Coordinate *closest = temp;
    float minDist = sqrt((x - temp->x)*(x - temp->x) + (y - temp->y)*(y - temp->y));

    temp = temp->next;
    while (temp != NULL) {
        float dist = sqrt((x - temp->x)*(x - temp->x) + (y - temp->y)*(y - temp->y));
        if (dist < minDist) {
            minDist = dist;
            closest = temp;
        }
        temp = temp->next;
    }

    std::cout << "Closest to (" << x << ", " << y << "): ID "<< closest->coord_id << " (" << closest->x << ", " << closest->y<< ") distance " << minDist << std::endl;
    
}


int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    srand(time(NULL));
    
    Coordinate *head = new Coordinate;
    
    head->x = (rand() % 100) / 10.0f;
    head->y = (rand() % 100) / 10.0f;
    
    head->coord_id = 1;
    head->next = NULL;
    head->previous = NULL;
    
    
    Coordinate *tail = head;
    
    for (int i = 1; i < n; i++) {
        float x = (rand() % 100) / 10.0f;
        float y = (rand() % 100) / 10.0f;
        add_coordinate(tail, x, y);
        tail = tail->next;
        
        
    }
    
    forward_display(head);
    backward_display(tail);
    
    std::cout<<"deleting something I guess"<<std::endl;
    delete_coordinate(&head, 2);
    tail = head;
    if (tail != NULL) {
    while (tail->next != NULL){
        tail = tail->next;
    }
}
    
    forward_display(head);
    closest_to(head, 5.0f, 5.0f);
    
    Coordinate *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
        
        
    }
        return 0;
    }


