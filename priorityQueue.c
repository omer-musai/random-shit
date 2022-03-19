#include "priorityQueue.h"

struct pq_t
{
    List elements;
    List priorities;
    PrCompare compare;
}

PQ PQCreate(ElemCopyFunction elemCopy, ElemFreeFunction elemFree, PrCopyFunction pCopy, PrFreeFunction pFree, PrCompare pCompare)
{
    PQ pq = malloc(sizeof(*pq));
    if(!pq)
    {
        return NULL;
    }

    pq->elements = listCreate(elemCopy, elemFree);
    if(pq->elements == LIST_OUT_OF_MEMORY)
    {
        free(pq);
        return NULL;
    }

    pq->priorities = listCreate(pCopy, pFree);
    if(pq->priorities == LIST_OUT_OF_MEMORY)
    {
        listDestroy(pq->elements)
        free(pq);
        return NULL;
    }

    pq->compare = PrCompare;

    return pq;
}

PQResult PQAdd(PQ pq, Element e, Priority p)
{
    if(pq->elements.listInsertLast(e) != LIST_SUCCESS)
    {
        return PQ_OUT_OF_MEM;
    }
    
    if(pq->priorities.listInsertLast(e) != LIST_SUCCESS)
    {
        return PQ_OUT_OF_MEM;
    }

    return PQ_SUCCESS;
}


Element PQGetMax(PQ pq)
{
    Element max_elem = listGetFirst(pq->elements);
    if(!max_elem)
    {
        return NULL;
    }
    Priority max_pr = listGetFirst(pq->priorities);
    if(!max_pr)
    {
        return NULL;
    }

    while(Element e = listGetNext(pq->elements))
    {
        Priority p = listGetNext(pq->priorities);

        if(pq->compare(max_pr, p) > 0)
        {
            max_pr = p;
            max_elem = e;
        }
    }
    
    return max_elem;
}