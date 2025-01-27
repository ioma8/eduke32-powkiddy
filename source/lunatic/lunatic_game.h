/* The Lunatic Interpreter, part of EDuke32. Game-side stuff. */

#ifndef EDUKE32_LUNATIC_H_
#define EDUKE32_LUNATIC_H_

#include "lunatic.h"
#include "gameexec.h"  // MAXEVENTS


extern L_State g_ElState;

// actor initialization data
typedef struct
{
    con_move_t mov;
    int16_t movflags;
    int16_t strength;
    con_action_t act;
    uint8_t haveit;  // shouldn't be used directly
} el_actor_t;

extern uint8_t g_elEvents[MAXEVENTS];  // shouldn't be used directly
extern el_actor_t g_elActors[MAXTILES];

extern int32_t g_elEventError;

extern uint32_t g_eventCalls[MAXEVENTS], g_actorCalls[MAXTILES];
extern double g_eventTotalMs[MAXEVENTS], g_actorTotalMs[MAXTILES], g_actorMinMs[MAXTILES], g_actorMaxMs[MAXTILES];

// -- functions --
void El_PrintTimes(void);

void El_ClearErrors(void);
void El_DisplayErrors(void);

int32_t El_CreateState(L_State *estate, const char *name);
void El_DestroyState(L_State *estate);

int32_t El_CallEvent(L_State *estate, int32_t eventidx, int32_t iActor, int32_t iPlayer, int32_t lDist, int32_t *iReturn);
int32_t El_CallActor(L_State *estate, int32_t actortile, int32_t iActor, int32_t iPlayer, int32_t lDist);

void El_OnError(const char *str);

int32_t (*El_RestoreGamevars)(const char *savecode);

static inline int32_t El_HaveEvent(int32_t eventidx) { return g_elEvents[eventidx]!=0; }
static inline int32_t El_HaveActor(int32_t actortile) { return g_elActors[actortile].haveit!=0; }

#endif
