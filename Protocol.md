## Description

This file describes the protocol that will be interpreted by the OAST calculation software. It also represents the saved scenario format.
It relies on a JSON extension wich allows coments.

## Preliminary definitions

* __Scenario__ is a set of simulation parameters
* __Protocol__ is the language used to describe a scenario
* __JSON__ is a structured data description language
* __metadata__ is the data that is not specifically linked to the scenario but it refers to general software info (i.e. software compatibility, versioning, ecc.)

## JSON data structure

OASTScenario: {
	creation_date: <JSON date>
	OAST_version: <JSON string>
	API_version: <int>
	scenario_description: [ <OASTScenarioItem> ]
	scenario_output: [ <OASTScenarioOutput> ]
}

OASTScenarioItem: {
	item_name: <string>
	item_id: <OASTItemId>
	item_type: <enum: satellite >
	item_args: [ <string> ]
}

OASTScenarioOutput: {
	item_name: <string>
	item_id: <int>
	input_from: <OASTItemId>
	start_condition: <str>
	item_type: <enum: coverage passageFor conversion printToPDF printToCSV ecc> 
	item_args: [ <string> ]
}

## Fields description

__*OASTScenario*__
**creation_date**: date formatted as dd-mm-yyyy hh:mm 
**OAST_version**: JSON string formatted as x.y.z-desc, es. 1.4.3-dev. It refers to the version used to compile this file
**API_version**: number of API version for compatibility purposes. Due to the possible additions of different functions in the future, this language may evolve while the previous versions of OAST may not be capable of interpreting them. In order to avoid errors, the API_version string is used to check the capability of the interpreter.
**scenario_description** is an array of OASTScenarioItem objects that represents the whole scenario

__*OASTScenarioItem*__
**item_name**: unique name of the OASTScenarioItem
**item_id**: unique identifier of the scenario item
**item_type**: enum that identificate the integration module
**item_args**: computation arguments for the integration module

__*OASTScenarioOutput*__
**item_name**: unique name of the OASTScenarioOutput
**item_id**: unique identifier of the scenario output
**input_from**: OASTItemId of the OASTScenarioItem from which the output is connected to the input of this OASTScenarioOutput
**start_condition**: eventual condition to start the module
**item_type**: enum that identificate the output module
**item_args**: computation arguments for output module

## Module working scheme

    +------------------------+
    | OASTScenarioItem       |
    | +--------------------+ |                 +----------------------+
    | | satellite_1        | | --------------->| Integration module 1 |
    | +--------------------+ |                 +----------------------+
    | +--------------------+ |                             |                 +----------------------+
    | | satellite_2        | | ----------------------------|---------------->| Integration module 2 |
    | +--------------------+ |                             |                 +----------------------+
    +------------------------+                             |                             |
                                                           |                             |
    +------------------------+                 +------------------------------------------------------+
    | OASTScenarioOutput     |                 |               Results data structure                 | 
    | +--------------------+ |                 | +--------------------+     +-----------------------+ |
    | | passage_for_out_1  | | <-------------- | | satellite_1 out    |     | satellite_2 out       | |
    | | check passage of   | |	               | +--------------------+     +-----------------------+ |
    | | satellite_1 for... | | --------------> | +--------------------+                               |
    | +--------------------+ |                 | | passage_for_out_1  |                               |
    +------------------------+                 | +--------------------+                               |
                                               +------------------------------------------------------+
    
## API_version

1: initial version

