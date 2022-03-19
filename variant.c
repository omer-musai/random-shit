#include "variant.h"

struct variant_t
{
    VarType type;
    VarElement element;
};


VarElement allocElement(VarType type, VarElement elem)
{
    switch (type){
    case VARTYPE_INT: return malloc(sizeof(int));
    case VARTYPE_DOUBLE: return malloc(sizeof(double));
    case VARTYPE_STRING: return malloc(strlen(elem)+1);
 }
} 

Variant variantCreate(VarElement elem, VarType type)
{
    if(!elem)
    {
        return VARIANT_NULL_ARGUMENT;
    }
    Variant var = malloc(sizeof(*var));
    if(!var)
    {
        return NULL;
    }
    
    var->element = allocElement(type, elem);
    if(!var->element)
    {
        variantDestroy(var);
        return VARIANT_NULL_ARGUMENT;
    }

    switch(type)
    {
        case VARTYPE_INT:
            *(int*)var->element = *(int*)elem;
            break;
        case VARTYPE_DOUBLE:
            *(double*)var->element = *(double*)elem;
            break;
        case VARTYPE_STRING:
            strcpy(var->element, elem);
            break;
    }
    return var;
}

VarResult variantWrite(FILE *outfile, Variant var)
{
    if(!var || !outfile)
    {
        return VARIANT_NULL_ARGUMENT;
    }
    
    switch(var->type)
    {
        case VARTYPE_INT:
            fprintf(outfile, "int %d\n", var->element);
            break;
        case VARTYPE_DOUBLE:
            fprintf(outfile, "double %f\n", var->element);
            break;
        case VARTYPE_STRING:
            fprintf(outfile, "string %s\n", var->element);
            break;
    }
    return VARIANT_SUCCESS;
}

