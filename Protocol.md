## Description

This file describes the protocol that will be interpreted by the OAST calculation software. It also represents the saved scenario format.
It relies on a JSON extension wich allows coments.

## Preliminary definitions

* __Scenario__ is a set of simulation parameters
* __Protocol__ is the language used to describe a scenario
* __JSON__ is a structured data description language
* __metadata__ is the data that is not specifically linked to the scenario but it refers to general software info (i.e. software compatibility, versioning, ecc.)

## JSON data structure
```
OASTObject: {
	name: <JSON string>
	id: <OASTObjectId>
	OAST_version: <int>
	API_version: <int>
}

OASTScenario: OASTObject{
	creation_date: <JSON date>
	scenario_description: [ <OASTScenarioItem> ]
	scenario_output: [ <OASTScenarioOutput> ]
}

OASTScenarioItem: OASTObject{
	item_type: <enum: satellite >
	item_args: [ <string> ]
}

OASTScenarioOutput: OASTObject{
	input_from: <OASTItemId>
	start_condition: <str>
	item_type: <enum: coverage passageFor conversion printToPDF printToCSV ecc> 
	item_args: [ <string> ]
}
```
## Fields description

The base object is called OASTObject and it contains all the essential informations that are common to each OAST element.

__*OASTScenario*__
**name**: unique name of the OAST element
**id**: unique identifier of the OAST element
**OAST_version**: JSON string formatted as x.y.z-desc, es. 1.4.3-dev. It refers to the version used to compile this file
**API_version**: number of API version for compatibility purposes. Due to the possible additions of different functions in the future, this language may evolve while the previous versions of OAST may not be capable of interpreting them. In order to avoid errors, the API_version string is used to check the capability of the interpreter.

__*OASTScenario*__
**creation_date**: date formatted as dd-mm-yyyy hh:mm 
**scenario_description** is an array of OASTScenarioItem objects that represents the whole scenario

__*OASTScenarioItem*__
**item_type**: enum that identificate the integration module
**item_args**: computation arguments for the integration module

__*OASTScenarioOutput*__W
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
    | | check passage of   | |                 | +--------------------+     +-----------------------+ |
    | | satellite_1 for... | | --------------> | +--------------------+                               |
    | +--------------------+ |                 | | passage_for_out_1  |                               |
    +------------------------+                 | +--------------------+                               |
                                               +------------------------------------------------------+

## Workflow

oast scenario should be prepared as json files scenario.json. This file should contain:
 * a list of OASTScenarioItem representing all the actors in the scenario (i.e. all the dynamic elements for which the simulation should be performed together with their initial conditions.)
 * a list of OASTScenarioOutput representing all the calculation to be performed (i.e. integrate satellite x, with the initial conditions y during timeslice t)


## API_version

1: initial version

