
#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

typedef struct pq_t* PQ; 
typedef void* Priority;
typedef void* Element;

typedef enum {
 PQ_SUCCESS, PQ_OUT_OF_MEM, PQ_NULL_ARG, PQ_EMPTY
} PQResult;


typedef Element (*ElemCopyFunction)(Element);
typedef void (*ElemFreeFunction)(Element);

typedef Priority (*PrCopyFunction) (Priority);
typedef Priority (*PrFreeFunction) (Priority);
typedef int (*PrCompare) (Priority a, Priority b);

 PQ PQCreate(ElemCopyFunction, ElemFreeFunction, PrCopyFunction, PrFreeFunction, PrCompare);
 void PQDestroy(PQ);
 PQResult PQAdd(PQ, Element, Priority);
 Element PQGetMax(PQ);
 PQResult PQRemoveMax(PQ);
 int PQGetSize(PQ);
 Element PQGetFirst(PQ);
 Element PQGetNext(PQ);

 #endif