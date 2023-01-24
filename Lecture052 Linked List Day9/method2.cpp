class Solution
{
    private:
    void insertAttail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        //step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertAttail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        //step2 creating a mapping
        unordered_map<Node*, Node*> oldtoNewNode;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            oldtoNewNode[originalNode] = cloneNode;
            originalNode = originalNode-> next;
            cloneNode = cloneNode -> next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode->arb = oldtoNewNode[originalNode->arb];
            originalNode = originalNode-> next;
            cloneNode = cloneNode-> next;
        }
        return cloneHead;
    }

};
