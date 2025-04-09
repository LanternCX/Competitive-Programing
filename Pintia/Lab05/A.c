Status Push(LinkList L, ElemType e){
	LinkList nd = (LinkList)malloc(sizeof(struct LNode));
	nd->data = e;
	nd->next = L->next;
	L->next = nd;
	return OK;
}

Status Pop(LinkList L,ElemType *e){
	if(L == NULL){
		return ERROR;
	}
	*e = L->next->data;
	L->next = L->next->next;
	return OK;
}