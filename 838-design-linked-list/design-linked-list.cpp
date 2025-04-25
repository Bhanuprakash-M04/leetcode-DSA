class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int length;

    MyLinkedList() {
        head = NULL;
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index >= length)
            return -1;
        Node* t = head;
        for (int i = 0; i < index; i++) {
            t = t->next;
        }
        return t->data;
    }

    void addAtHead(int val) {
        Node* curr = new Node(val);
        curr->next = head;
        head = curr;
        length++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);
        if (!head) {
            head = temp;
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = temp;
        }
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }

        Node* temp = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length || head == NULL)
            return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */