typedef struct matamazon_t* Matamazon;
typedef struct sale_offer_t* SaleOffer;
typedef struct bid_t* Bid;
typedef struct time_t* Time; 

typedef enum{
    MATAMAZON_SUCCES,
    MATAMAZON_OUT_OF_MEMORY,
    MATAMAZON_NULL_ARGUMENT,
    MATAMAZON_ITEM_ALREADY_EXIST,


} MatamazonResult;

typedef bool (*saleOfferCond) (SaleOffer, void* param);
typedef void* Item;
typedef void* customerId;

Matamazon matamazonCreate();
void matamazonDestroy(Matamazon);
MatamazonResult matamazonAddSaleOffer(Matamazon, SaleOffer);
MatamazonResult matamazonRemoveSaleOffer(Matamazon, SaleOffer);
MatamazonResult matamazonAddBid(Matamazon, Bid, customerId);
MatamazonResult matamazonRemoveBid(Matamazon, Bid);
MatamazonResult matamazonSale(Matamazon);
MatamazonResult matamazonPrint(Matamazon, File*);
int genericSaleOfferCount(Matamazon, saleOfferCond, void* param);

struct matamazon_t{
    Set saleOffers;
};

struct sale_offer_t{
    int itemId;
    Item item;
    int minimalPrice;
    Time time;
};

struct bid_t{
    customerId id;
    double price;
    int itemId;
};


SaleOffer saleOffercopy(SaleOffer s)
{
    SaleOffer copy = malloc(sizeof(*copy));
    copy->itemId = s->itemId;
    copy->minimalPrice = s->minimalPrice;
    copy->time = s->time;
    copy->item = s->item;
}

Void saleOfferDestroy(SaleOffer s){
    timeDestroy(s->time);
    itemDestroy(s->item);
    free(s);
}

bool saleOfferEqual(SaleOffer s1, SaleOffer s2){
    return s1->itemId == s2->itemId;
}

MatamazonResult matamazonAddSaleOffer(Matamazon m, SaleOffer s)
{
    if(setAdd(m->saleOffers, s) == SET_OUT_OF_MEMORY)
    {
        return MATAMAZON_OUT_OF_MEMORY;
    }
    return MATAMAZON_SUCCES;
}

MatamazonResult matamazonSale(Matamazon m)
{
    SET_FOREACH(SaleOffer, s, m->saleOffers)
    {
        int current_price = 0;
        int current_buyer = 0;
        if (s->time <= getCurrentTime())
        {
            LIST_FOREACH(Bid, b, m->bids)
            {
                if(b->itemId == s->itemId && b->price >= current)
                {
                    current_price = b->price;
                    current_buyer = b->id;
                }
            };
            if(current_buyer)
            {
                transactionPerform(current_buyer, s->item);
            }
        }
    };
}

int getNumberOfSuitableClothes(Matamazon m, int size)
{
    return genericSaleOfferCount(m, cond, size)
}

bool cond (SaleOffer s, int size)
{
    ClothingItem product = *(ClothingItem*)s->item;
    return product->size == size;
}