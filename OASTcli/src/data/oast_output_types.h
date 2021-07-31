#ifndef OAST_TYPES_H
#define OAST_TYPES_H

#include "../base_includes.h"

typedef enum oast_end_event {
	PASSAGE_FOR,
	TIMESIM
} oast_output_type_t;

typedef enum oast_start_event {
	START_EVENT,
	AFTER_SCENARIO_COMPLETION_ID,
} oast_event_t;

/* TO BE FINISHED */

typedef struct oast_scenario_output {
	uint16_t		input_from;
	oast_event_t		start_condition;
	
	oast_output_type_t *	item_type;
	uint8_t *		item_args;
} oast_scenario_out_t;

#endif

