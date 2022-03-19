#include <stdbool.h>
typedef struct date_t* Date;
Date dateCreate(int day, int month, int year);
Date dateCopy(Date date);
void dateDestroy(Date date);
bool dateIsEarlier(Date d1, Date d2); 


typedef void* Event;
typedef Event (*EventCopyFunction)(Event);
typedef void (*EventFreeFunction)(Event);
typedef bool (*calCondition)(Event, void*);
typedef struct calendar_t* Cal;

typedef enum{
    CAL_OUT_OF_MEMORY,
    CAL_NULL_ARG,
    DATE_ALREADY_EXIST,
    DATE_DOES_NOT_EXIST,
    CAL_SUCCESS
} CalResult;


Cal calCreate(EventCopyFunction, EventFreeFunction);
void calDestroy(Cal);
Cal calCopy(Cal);
CalResult addDate(Cal, Date);
CalResult addEvent(Cal, Date, Event);
CalResult removeDate(Cal, Date);
int numOfEvents(Cal, Date);
int calQuery(Cal, Date, calCondition, void*)

type struct {
    Date date;
    List events;
} *datedEvents;

struct calendar_t{
    Set d_events;
    EventCopyFunction e_copy;
    EventFreeFunction e_free;
};

//datedEvents will hold a date and list of events that belongs to this date. and calendar will hold a set of those datedEvents, date cant appear twice in calendar thus set fits best.
//also, calendar will hold free and copy functions of events because for every creation of datedEvents object it'll to send those function in order to create list of events.

typedef struct {
 char* name;
 int hour;
} HourEvent;

Cal createHourCalender()
{
    return calCreate(HourEventCopy, HourEventFree);
}

Event HourEventCopy(Event event)
{
    HourEvent* e = event;
    HourEvent* copy = malloc(sizeof(*copy));
    copy->name = malloc(sizeof(strlen(e->name) + 1));
    strcpy(copy->name, e->name);
    copy->hour = e->hour;
    return copy;
}

void HourEventFree(Event event)
{
    HourEvent* e = event;
    free(e->name);
    free(e);
}

CalResult addEvent(Cal cal, Date date, int hour, char* name)
{
    HourEvent e;
    e.hour = hour;
    e.name = name;
    return addEvent(cal, date, &e);
}

int eventsLaterThan(Cal cal, Date date, int hour)
{
    return calQuery(cal, date, condition, &hour);
}

bool condition(Event e, void* param)
{
    HourEvent* event = e;
    return e->hour >= *(int*)param;
}


