class Node {
  int val;
  Node * next;
  Node():val(0), next(NULL){}
};


Node* reverse(Node* head) {
  Node *d = new Node(), *tmp =Null;
  while (head) {
    tmp = head->next;
    head->next = d->next;
    d->next = head;
    head = tmp;
  }
  return d->next;
}