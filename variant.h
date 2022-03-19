#ifndef VARIANT_H_
#define VARIANT_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct variant_t* Variant;
typedef void* VarElement;

typedef enum
{
    VARTYPE_INT,
    VARTYPE_DOUBLE,
    VARTYPE_STRING,
} VarType;

typedef enum
{
    VARIANT_SUCCESS,
    VARIANT_OUT_OF_MEMORY,
    VARIANT_NULL_ARGUMENT,
    VARIANT_FILE_ERROR
} VarResult;

Variant variantCreate(VarElement elem, VarType type);
void variantDestroy(Variant var);
Variant variantCopy(Variant var);
VarResult variantUpdate(Variant var, VarElement elem, VarType type);
VarResult variantWrite(FILE *outfile, Variant var);
Variant variantRead(FILE *infile);
VarElement allocElement(VarType type, VarElement elem);


#endif