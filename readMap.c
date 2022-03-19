#include "variant.h"
#define MAX_NAME_LEN 10

typedef void* Element;

Element copyVariant(Element v)
{
    return variantCopy(v); 
}

void freeVariant(Element v)
{
    variantDestroy(v);
}
Element copyString(Element str){}
void freeString(Element str){}
bool equalString(Element str1, Element str2){}


Map readMap(FILE *infile)
{

    Map map = mapCreate(copyString, freeString, equalString, copyVariant, freeVariant);
    if(!map)
    {
        return VARIANT_OUT_OF_MEMORY;
    }

    char name[MAX_NAME_LEN + 1];
   

    while(fscanf(infile, "%s", name) == 1)
    {
        Variant var = variantRead(infile);
        if(!var || mapPut(map, name, var) != MAP_SUCCESS)
        {
            mapDestroy(map);
            variantDestroy(var);
            return NULL;
        }
        variantDestroy(var);
    }
    return map;
}