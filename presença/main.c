/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *
insertionSortList(struct ListNode *cabeca) {
  struct ListNode h, *cauda, *next, *caudaAnterior, *temporario, *temporarioAnterior;

  if (!cabeca)
    return NULL;

  h.next = cabeca;
  cauda = cabeca->next;
  caudaAnterior = cabeca;
  
  while (cauda) {
  
    next = cauda->next;
    temporario = h.next;
    temporarioAnterior = &h;
    
    while (cauda != temporario && temporario->val < cauda->val) {
      temporarioAnterior = temporario;
      temporario = temporario->next;
    }

    if (cauda == temporario) {
      caudaAnterior = cauda;
    } 
    
    else {
      caudaAnterior->next = next;
      temporarioAnterior->next = cauda;
      cauda->next = temporario;
    }
    
    cauda = next;
  }

  return h.next;
}